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
	Cell& getCell(int row, int column);
	void ensureSize(const int & rows, const int & cols);
	int getSize();
	void notify(int row, int col) override;
	typedef std::vector<Column>::iterator iterator;

private:
	Sheet();
	~Sheet() = default;
	Sheet(Sheet const&);
    void operator=(Sheet const&);
	std::vector<Column> sheet;

};

#endif
