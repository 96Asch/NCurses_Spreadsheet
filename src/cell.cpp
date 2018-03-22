/*
 * cell.cpp
 *
 *  Created on: Mar 22, 2018
 *      Author: asch
 */

#include "cell.h"
#include "cellValue.h"

Cell::Cell() {
	// TODO Auto-generated constructor stub
  clear();
  
}

Cell::~Cell() {
	// TODO Auto-generated destructor stub
}

void Cell::readInt(int input) {
  value.reset(new CellValue<int>(input));
}

void Cell::readFloat(float input) {
  value.reset(new CellValue<float>(input));
}

void Cell::readString(std::string input) {
  value.reset(new CellValue<std::string>(input));  
}

void Cell::readFormula(CellFormula formula) {

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

std::string Cell::getDrawString(){
  return value->getDrawString();
}

void Cell::clear() {
  value.reset(nullptr);
}
