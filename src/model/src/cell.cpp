/*
 * cell.cpp
 *
 *  Created on: Mar 22, 2018
 *      Author: asch
 */

#include "cell.h"
#include "cellValue.h"

#define DEFAULT_NUM 0
#define DEFAULT_STR ""

Cell::Cell() {
	clear();
}

void Cell::set(CellValueBase* base) {
	value.reset(base);
}

int Cell::getInt() const {
	if (value)
		return value->getInt();
	return DEFAULT_NUM;
}

float Cell::getFloat() const {
	if (value)
		return value->getFloat();
	return DEFAULT_NUM;
}

std::string Cell::getEditString() const {
	if (value)
		return value->getEditString();
	return DEFAULT_STR;
}

std::string Cell::getDrawString() const {
	if (value)
		return value->getDrawString();
	return DEFAULT_STR;
}

void Cell::clear() {
	value.reset(nullptr);
}
