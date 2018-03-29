/*
 * CellFormula.cpp
 *
 *  Created on: Mar 22, 2018
 *      Author: asch
 */

#include "cellFormula.h"

CellFormula::CellFormula(const std::string & rawFormula) : originalFormula(rawFormula) {
	if(!parser.parse(rawFormula, formula)){
//		clear(formula);
		output = "ERR";
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
	return 0;
}

int CellFormula::getInt() {
	return 0;
}

void CellFormula::print(std::shared_ptr<Token> const node) {
	if (node) {
		if (node->isOperator) {
			if (node != formula)
				std::cout << "( ";
			print(node->left);
			std::cout << node->toString() << ' ';
			print(node->right);
			if (node != formula)
				std::cout << ") ";
		}
		else {
			std::cout << node->toString() << ' ';
		}
	}
}

void CellFormula::print() {
	print(formula);
}



