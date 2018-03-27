/*
 * CellFormula.cpp
 *
 *  Created on: Mar 22, 2018
 *      Author: asch
 */

#include "cellFormula.h"

CellFormula::CellFormula(const std::string & formula) : originalFormula(formula) {}

std::string CellFormula::getDrawString() {
	return "TODO";
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



