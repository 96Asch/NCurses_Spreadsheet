/*
 * sheet.h
 *
 *  Created on: Mar 22, 2018
 *      Author: asch
 */

#ifndef INCLUDE_SHEET_H_
#define INCLUDE_SHEET_H_

#include "cell.h"
#include "column.h"
#include <vector>

class Sheet {
public:
	Sheet();
	~Sheet() = default;
	std::vector<Column>::iterator begin();
  std::vector<Column>::iterator end();
	Cell& getCell(int row, int column);
	void ensureSize(const int & rows, const int & cols);

private:
	std::vector<Column> sheet;

};

#endif
