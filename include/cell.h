/*
 * cell.h
 *
 *  Created on: Mar 22, 2018
 *      Author: asch
 */

#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include<string>
#include"cellFormula.h"
#include"cellValueBase.h"
#include<memory>

class Cell {
public:
	Cell();
	virtual ~Cell();

  void readInt(int value);
  void readFloat(float value);
  void readString(std::string value);
  void readFormula(CellFormula formula);
  
  int getInt();
  float getFloat();
  std::string getEditString();
  std::string getDrawString();
  CellFormula getFormula();
  
  void clear();
private:
  std::unique_ptr<CellValueBase> value;
  
};

#endif /* INCLUDE_CELL_H_ */
