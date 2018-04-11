/*
 * cellAddress.cpp
 *
 *  Created on: Mar 22, 2018
 *      Author: asch
 */
#ifndef INCLUDE_COLUMN_H_
#define INCLUDE_COLUMN_H_

#include "cell.h"
#include <vector>

class Column {
public:
	Column();
	Cell& getCell(const int & index);
	void resize(const int & rows);
	std::vector<Cell>::iterator begin();
	std::vector<Cell>::iterator end();
	int getSize();
	typedef std::vector<Cell>::iterator iterator;

private:
	std::vector<Cell> column;

};

#endif
