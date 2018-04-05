/*
 * cellAddress.h
 *
 *  Created on: Mar 22, 2018
 *      Author: asch
 */

#ifndef INCLUDE_CELLADDRESS_H_
#define INCLUDE_CELLADDRESS_H_

#include <string>

class CellAddress {
public:

	/**
	 * Constructor for the CellAddress.
	 * @param string address to convert
	 */
	CellAddress(std::string address);
	CellAddress() = default;

	/**
	 * Destructor for the CellAddress.
	 */
	~CellAddress() = default;

	/**
	 * Returns the row of the cell.
	 * @return integer number of the row
	 */
	int getRow() const;

	/**
	 * Returns the column of the cell.
	 * @return integer number of the column
	 */
	int getColumn() const;

	/**
	 * Converts a sheet indexes to container indexes.
	 * @param string address to convert
	 */
	void createFromReference(const std::string & address);
	
	CellAddress &operator++() {
		 row++;
		return *this;
	}

private:
	size_t row, column;

	/**
	 * Converts a letter to a number.
	 * @param char c, the char to convert
	 * @return integer number
	 */
	int letterToInt(const char & c);

	/**
	 * Converts and sets the column string to numbers.
	 * @param string letters, the column described in letters.
	 */
	void columnToNumber(const std::string & letters);

	/**
	 * Converts and sets the row number.
	 * @param string rowNumber, the row described in numbers.
	 */
	void rowToIndex(const std::string & rowNumber);
};

#endif /* INCLUDE_CELLADDRESS_H_ */
