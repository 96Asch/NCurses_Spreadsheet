/*
 * cellValueBase.h
 *
 *  Created on: Mar 22, 2018
 *      Author: asch
 */

#ifndef INCLUDE_CELLVALUEBASE_H_
#define INCLUDE_CELLVALUEBASE_H_

#include <string>

class CellValueBase {
public:

	/**
	 * Constructor of the CellValueBase class.
	 */
	CellValueBase();

	/**
	 * Destructor of the CellValueBase class.
	 */
	virtual ~CellValueBase();

	/**
	 * Returns the value of the cell to draw on screen.
	 * @return std::string, the string to draw.
	 */
	virtual std::string getDrawString() const = 0;

	/**
	 * Returns the value of the cell for the editor.
	 * @return std::string, the string to show.
	 */
	virtual std::string getEditString() const = 0;

	/**
	 * Returns the value of the cell to calculate with.
	 * @return float, the float value of the cell.
	 */
	virtual float getFloat() const = 0;

	/**
	 * Returns the value of the cell to calculate with.
	 * @return int, the int value of the cell.
	 */
	virtual int getInt() const = 0;

	/**
	 * Parses and returns the appropriate CellValueBase based on
	 * the format of the given string.
	 * @param std::string input, the string to parse.
	 * @return CellValueBase*, a pointer to the newly created CellValueBase.
	 */
	static CellValueBase* cellValueFactory (const std::string & input);

};

#endif /* INCLUDE_CELLVALUEBASE_H_ */
