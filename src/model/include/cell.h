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

#include "cellValue.h"
#include "cellValueBase.h"

class Cell {

public:
	Cell();
	/**
	 * Sets a value in the cell.
	 * @param Celvaluebase pointer to a value
	 */
	void set(CellValueBase* base);

	/**
	 * Returns an integer value from the cell.
	 * @return integer value
	 */
	int getInt() const;

	/**
	 * Returns a float value from the cell.
	 * @return float value
	 */
	float getFloat() const;

	/**
	 * Returns a string value for editing.
	 * @return string value
	 */
	std::string getEditString() const;

	/**
	 * Returs a string value for drawing.
	 * @return string value
	 */
	std::string getDrawString() const;

	template <typename T>
	CellValue<T> getValue() const;

	/**
	 * Clears the value of the cell
	 */
	void clear();

private:
	std::unique_ptr<CellValueBase> value;
};

#endif /* INCLUDE_CELL_H_ */
