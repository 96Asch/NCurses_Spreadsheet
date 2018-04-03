/*
 * cell.cpp
 *
 *  Created on: Mar 22, 2018
 *      Author: asch
 */

#include "cell.h"
#include "cellValue.h"


Cell::Cell(Cell && c) :
		value(std::move(c.value)) {
}

Cell::Cell() {
	clear();
}

Cell::~Cell() {
}

void Cell::readInt(const int & input) {
	value.reset(new CellValue<int>(input));
}

void Cell::readFloat(const float & input) {
	value.reset(new CellValue<float>(input));
}

void Cell::readString(const std::string & input) {
	value.reset(new CellValue<std::string>(input));
}

void Cell::readFormula(CellValueBase* base) {
	value.reset(base);
}

int Cell::getInt() {
	return value->getInt();
}

float Cell::getFloat() {
	return value->getFloat();
}

std::string Cell::getEditString() {
	return value->getEditString();
}

std::string Cell::getDrawString() {
	return value->getDrawString();
}

void Cell::clear() {
	value.reset(nullptr);
}
