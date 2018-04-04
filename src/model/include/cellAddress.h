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
	CellAddress(std::string address);
	~CellAddress() = default;

	int getRow();
	int getColumn();
	void createFromReference(const std::string & address);
private:
	int row;
	int column;
	int letterToInt(const char & c);
	void columnToNumber(const std::string & letter);
	void rowToIndex(const std::string & rowNumber);
};

#endif /* INCLUDE_CELLADDRESS_H_ */
