/*
 * CellFormula.cpp
 *
 *  Created on: Mar 22, 2018
 *      Author: asch
 */

#include "cellFormula.h"
#include "util.h"
#include <iostream>

CellFormula::CellFormula(Sheet & sheet, const std::string & rawFormula) :
		sheet(sheet), originalFormula(rawFormula) {
	CellFormulaParser parser;
	if (!parser.parse(rawFormula, formula)) {
		output = "ERR";
		result = 0;
		formula = nullptr;
	} else {
		result = evaluate(formula);
		if (isInteger(result))
			output = std::to_string(getInt());
		else
			output = std::to_string(getFloat());
	}
}

CellFormula::~CellFormula() {
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
	return static_cast<int>(result);
}

//TODO FIX RANGE loop does not accept end
float CellFormula::sum(const std::string & begin, const std::string & end) {
	CellAddress address1(begin), address2(end);
	range.createRange(address1, address2, &sheet);
	float sum = 0;
	for (Range::iterator it = range.begin(); it != range.end(); ++it)
		sum += it->getFloat();
	sum += range.end()->getFloat();
	return sum;
}

float CellFormula::average(const std::string & begin, const std::string & end) {
	CellAddress address1(begin), address2(end);
	range.createRange(address1, address2, &sheet);
	float sum = 0;
	float count = range.getSize();
	for (const auto &i : range) {
		sum += i.getFloat();
	}
	sum += range.end()->getFloat();
	return sum / count;
}

float CellFormula::count(const std::string & begin, const std::string & end) {
	CellAddress address1(begin), address2(end);
	range.createRange(address1, address2, &sheet);
	return range.getSize();
}

//TODO Add Celladdresses and Aggregate functions
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
			return sheet.getCell(address.getRow(), address.getColumn()).getFloat();
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

