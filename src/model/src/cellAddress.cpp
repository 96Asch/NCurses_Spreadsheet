/*
 * cellAddress.cpp
 *
 *  Created on: Mar 22, 2018
 *      Author: asch
 */

#include "cellAddress.h"
#include "util.h"
#include "sheet.h"
#include <iostream>
#include <cmath>

#define ASCII_START 64

CellAddress::CellAddress(const std::string & address) :  row(0), column(0) {
	createFromReference(address);
}

void CellAddress::createFromReference(const std::string & address) {
	size_t i;
	if (isCellAddress(address)) {
		splitAddress(address, i);
		columnToNumber(address.substr(0, i));
		rowToIndex(address.substr(i));
	}
}

void CellAddress::columnToNumber(const std::string & col) {
	column = 0;
	int multiplier, exp = 0;
	for (int i = col.size() - 1; i >= 0; i--, exp++) {
		multiplier = (col.at(i) - ASCII_START);
		column += multiplier * std::pow(26, exp);
	}
	column -= 1;
} //columnToNumber

void CellAddress::rowToIndex(const std::string & rowNumber) {
	row = std::stoi(rowNumber) - 1;
}

CellAddress CellAddress::moveRow(const int & number) {
	if (row + number >= 0 && row + number < Sheet::getInstance().getRows())
		row += number;
	return *this;
}

CellAddress CellAddress::moveColumn(const int & number) {
	if (column + number >= 0 && column + number < Sheet::getInstance().getCols())
		column += number;
	return *this;
}

int CellAddress::getRow() const {
	return row;
}

int CellAddress::getColumn() const {
	return column;
}
