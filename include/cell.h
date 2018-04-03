/*
 * cell.h
 *
 *  Created on: Mar 22, 2018
 *      Author: asch
 */

#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include <string>
#include <memory>

#include "cellValueBase.h"

class Cell {
public:
	Cell(Cell&& c);
	Cell();
	~Cell();
	void readInt(const int & value);
	void readFloat(const float & value);
	void readString(const std::string & value);
	void readFormula(CellValueBase* base);

	int getInt();
	float getFloat();
	std::string getEditString();
	std::string getDrawString();

	void clear();
private:
	std::unique_ptr<CellValueBase> value;

};

#endif /* INCLUDE_CELL_H_ */
