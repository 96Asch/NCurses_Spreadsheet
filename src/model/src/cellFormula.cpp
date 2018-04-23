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
#define ERROR_MSG "ERR"

CellFormula::CellFormula(const std::string & rawFormula) :
		originalFormula(rawFormula),  output(ERROR_MSG), formula(nullptr), result(0), recursionDepth(5){
	Sheet::getInstance().attach(this);
	CellFormulaParser parser;
	if (parser.parse(rawFormula, formula))
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

float CellFormula::setIfCellContainsString(const Cell & cell) {
	int retval = cell.getFloat();
	if (retval == 0 && !cell.getDrawString().empty())
		output = cell.getDrawString();
	return retval;

}

void CellFormula::calculate() {
	result = evaluate(formula);
	if (output.empty()) {
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
			//TODO ERROR if cell is circular
			return setIfCellContainsString(Sheet::getInstance().getCell(address.getRow(), address.getColumn()));
		}
	}
	return 0;
}
