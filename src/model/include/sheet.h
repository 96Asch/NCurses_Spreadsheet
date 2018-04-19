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
#include <subject.h>

class Sheet : public Subject{
public:
	static Sheet& getInstance();
	std::vector<Column>::iterator begin();
	std::vector<Column>::iterator end();
	Cell& getCell(const int & row, const int & column);
	void ensureSize(const int & rows, const int & cols);
	void notify() override;
	typedef std::vector<Column>::iterator iterator;

private:
	int rows, cols;
	std::vector<Column> sheet;

	Sheet();
	Sheet(const int & rows, const int & cols);
	~Sheet() = default;
	Sheet(Sheet const&);
    void operator=(Sheet const&);

};

#endif
