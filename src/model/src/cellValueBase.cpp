/*
 * cellValueBase.cpp
 *
 *  Created on: Mar 22, 2018
 *      Author: asch
 */

#include "cellValueBase.h"
#include "util.h"
#include "cellFormula.h"
#include "cellValue.h"

CellValueBase::CellValueBase(){}

CellValueBase::~CellValueBase(){}


CellValueBase* CellValueBase::cellValueFactory (const std::string & input) {
  int intValue = 0;
  float floatValue = 0;
  
  if (!input.empty()) {
    if (input.front() == '=')
      return new CellFormula(input);
    else if (is<int>(input, intValue))
      return new CellValue<int>(intValue);
    else if (is<float>(input, floatValue))
      return new CellValue<float>(floatValue);
    else 
      return new CellValue<std::string>(input);
}
  else 
    return nullptr;
}

