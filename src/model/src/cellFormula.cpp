/*
  Programmeertechnieken opdracht 2
  Andrew Huang        s1913999
  Paul Peters         s1453440
  Ruben van Erkelens  s1437267
  Karl Freeke         s1551973
*/

#include "cellFormula.h"
#include "util.h"
#include <iostream>
#include "sheet.h"
#include <fenv.h>

#define MAX_RECURSION 7
#define ERROR_MSG "ERR"

CellFormula::CellFormula(const std::string & rawFormula) :
		originalFormula(rawFormula), output(""), formula(nullptr), result(0), calculationError(false), parserError(false){
	Sheet::getInstance().attach(this);
	CellFormulaParser parser;
	if (parser.parse(rawFormula, formula))
		calculate();
	else {
		parserError = true;
		output = ERROR_MSG;
	}
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
	output = "";
	calculationError = false;
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
		if(isCellAString(i) || i.getDrawString() == ERROR_MSG)
			calculationError = true;
		sum += i.getFloat();
	}
	return sum;
}

float CellFormula::average(const std::string & begin, const std::string & end) {
	CellAddress address1(begin), address2(end);
	range.createRange(address1, address2);
	float count = range.getSize(), sum = 0;
	for (const auto &i : range) {
		if(isCellAString(i) || i.getDrawString() == ERROR_MSG)
			calculationError = true;
		sum += i.getFloat();
	}
	return sum / count;
}

float CellFormula::count(const std::string & begin, const std::string & end) {
	CellAddress address1(begin), address2(end);
	range.createRange(address1, address2);
	return range.getSize();
}

bool CellFormula::isCellAString (const Cell & cell) {
	return (cell.getFloat() == 0 && !cell.getDrawString().empty());
}

void CellFormula::calculate() {
	result = evaluate(formula);
	if (output.empty()) {
		if(parserError || calculationError)
			output = ERROR_MSG;
		else if (isInteger(result))
			output = std::to_string(getInt());
		else
			output = std::to_string(getFloat());
	}
}

float CellFormula::evaluate(std::shared_ptr<Token> & node) {
	if (node && !calculationError) {
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
			Cell* cell = &Sheet::getInstance().getCell(address.getRow(), address.getColumn());
			//TODO ERROR if cell is circular
			if(isCellAString(*cell) || cell->getDrawString() == ERROR_MSG)
				output = cell->getDrawString();
			return cell->getFloat();
		}
	}


	return 0;
}
