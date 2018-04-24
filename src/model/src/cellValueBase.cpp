/*
  Programmeertechnieken opdracht 2
  Andrew Huang        s1913999
  Paul Peters         s1453440
  Ruben van Erkelens  s1437267
  Karl Freeke         s1551973
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

