/*
 * CellFormula.cpp
 *
 *  Created on: Mar 22, 2018
 *      Author: asch
 */

#include "cellFormula.h"
#include "util.h"
#include <iostream>
#include "sheet.h"
#include <fenv.h>

#define MAX_RECURSION 7

CellFormula::CellFormula(const std::string & rawFormula) :
		originalFormula(rawFormula), recursionDepth(5) {
	Sheet::getInstance().attach(this);
	CellFormulaParser parser;
	if (!parser.parse(rawFormula, formula)) {
		output = "ERR";
		result = 0;
		formula = nullptr;
	} else
		calculate();
}

CellFormula::~CellFormula() {
	Sheet::getInstance().detach(this);
	formula = nullptr;
}

std::string CellFormula::getDrawString() const {
	return output;
}

std::string CellFormula::getEditString() const {
	return originalFormula;
}

float CellFormula::getFloat() const {
	return result;
}

int CellFormula::getInt() const {
	int retval = static_cast<int>(result);
	return retval;
}

void CellFormula::update() {
	calculate();
}

bool CellFormula::isInteger(const float & val) {
	fesetround (FE_TONEAREST);
	return val == rintf(val);
}

float CellFormula::sum(const std::string & begin, const std::string & end) {
	CellAddress address1(begin), address2(end);
	range.createRange(address1, address2);
	float sum = 0;
	for (const auto &i : range) {
		sum += i.getFloat();
	}
	return sum;
}

float CellFormula::average(const std::string & begin, const std::string & end) {
	CellAddress address1(begin), address2(end);
	range.createRange(address1, address2);
	float count = range.getSize(), sum = 0;
	for (const auto &i : range) {
		sum += i.getFloat();
	}

	return sum / count;
}

float CellFormula::count(const std::string & begin, const std::string & end) {
	CellAddress address1(begin), address2(end);
	range.createRange(address1, address2);
	return range.getSize();
}

void CellFormula::copyStringAtAddress(const CellAddress & address) {
	if (!Sheet::getInstance().getCell(address.getRow(), address.getColumn()).getDrawString().empty())
		output = Sheet::getInstance().getCell(address.getRow(),
				address.getColumn()).getDrawString();
}

void CellFormula::calculate() {
	result = evaluate(formula);
	if (!output.empty()) {
		if (isInteger(result))
			output = std::to_string(getInt());
		else
			output = std::to_string(getFloat());
	}
}

float CellFormula::evaluate(std::shared_ptr<Token> & node) {
	if (node) {
		switch (node->type) {
		case PLUS:
			return evaluate(node->left) + evaluate(node->right);
		case MINUS:
			return evaluate(node->left) - evaluate(node->right);
		case DIVIDE:
			return evaluate(node->left) / evaluate(node->right);
		case MULTIPLICATION:
			return evaluate(node->left) * evaluate(node->right);
		case AVG:
			return average(node->left->toString(), node->right->toString());
		case COUNT:
			return count(node->left->toString(), node->right->toString());
		case SUM:
			return sum(node->left->toString(), node->right->toString());
		case FLOAT:
		case INT:
			return node->getValue();
		case CELLADDRESS:
			CellAddress address(node->toString());
			//TODO ERROR if cell is a string or circular
			float retval = Sheet::getInstance().getCell(address.getRow(),
					address.getColumn()).getFloat();
			if (retval == 0)
				copyStringAtAddress(address);
			return retval;
		}
	}
	return 0;
}

void CellFormula::print(std::shared_ptr<Token> const token) {
	if (token) {
		if (token->isOperator) {
			if (token != formula)
				std::cout << "( ";
			print(token->left);
			std::cout << token->toString() << ' ';
			print(token->right);
			if (token != formula)
				std::cout << ") ";
		} else {
			std::cout << token->toString() << ' ';
		}
	}
}

void CellFormula::print() {
	print(formula);
}

