/*
 * CellFormula.cpp
 *
 *  Created on: Mar 22, 2018
 *      Author: asch
 */

#include "cellFormula.h"
#include "util.h"

CellFormula::CellFormula(const std::string & rawFormula) :
		originalFormula(rawFormula) {
	if (!parser.parse(rawFormula, formula)) {
		output = "ERR";
		formula = nullptr;
	}
	else {
		result = evaluate(formula);
		if(isInteger(result))
			output = std::to_string(getInt());
		else
			output = std::to_string(getFloat());
	}
}

CellFormula::~CellFormula() {
	formula = nullptr;
}
std::string CellFormula::getDrawString() {
	return output;
}

std::string CellFormula::getEditString() {
	return originalFormula;
}

float CellFormula::getFloat() {
	return result;
}

int CellFormula::getInt() {
	return static_cast<int>(result);
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
			return 0;
		case COUNT:
			return 1;
		case SUM:
			return 2;
		case FLOAT:
		case INT:
			return node->getValue();
		case CELLADDRESS:
			return 3;
		default:
			return 0;
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

