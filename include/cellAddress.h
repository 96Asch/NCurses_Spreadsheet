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
	virtual ~CellAddress();

  int getRow();
  int getColumn();
private:
  int row;
  int column;
  int letterToInt(char c);
  void columnToNumber(std::string letter);
	void rowToIndex(std::string rowNumber);
	void init(std::string address);
};

#endif /* INCLUDE_CELLADDRESS_H_ */
