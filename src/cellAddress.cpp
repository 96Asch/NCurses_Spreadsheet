/*
 * cellAddress.cpp
 *
 *  Created on: Mar 22, 2018
 *      Author: asch
 */

#include "cellAddress.h"
#include "util.h"
#include <iostream>
#include <cmath>

CellAddress::CellAddress(std::string address) {
	createFromReference(address);
}

void CellAddress::createFromReference(const std::string & address){
	size_t i;
	splitAddress(address, i);
	columnToNumber(address.substr(0, i));
	rowToIndex(address.substr(i));
}

int CellAddress::letterToInt(const char & c) {
	return c - 64;
}

void CellAddress::columnToNumber(const std::string & col) {
	column = 0;
	int multiplier;
	int exp = 0;
	for (int i = col.size() - 1; i >= 0; i--, exp++) {
		multiplier = letterToInt(col[i]);
		column += multiplier * std::pow(26, exp);
	}
} //columnToNumber

void CellAddress::rowToIndex(const std::string & rowNumber) {
	row = std::stoi(rowNumber) - 1;
}

int CellAddress::getRow() {
	return row;
}

int CellAddress::getColumn() {
	return column;
}
