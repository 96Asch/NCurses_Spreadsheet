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
	Cell();
	void set(CellValueBase* base);

	int getInt();
	float getFloat();
	std::string getEditString() const;
	std::string getDrawString() const;

	void clear();
private:
	std::unique_ptr<CellValueBase> value;

};

#endif /* INCLUDE_CELL_H_ */
