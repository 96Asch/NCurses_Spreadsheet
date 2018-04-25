/*
  Programmeertechnieken opdracht 2
  Andrew Huang        s1913999
  Paul Peters         s1453440
  Ruben van Erkelens  s1437267
  Karl Freeke         s1551973
*/

#include "cell.h"
#include "cellValue.h"
#include "sheet.h"

#define DEFAULT_NUM 0
#define DEFAULT_STR ""

Cell::Cell() {
	value.reset(nullptr);
}

void Cell::set(CellValueBase* base) {	
	value.reset(base);
	Sheet::getInstance().notify();
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
