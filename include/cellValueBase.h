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
	CellValueBase();
	virtual ~CellValueBase() = 0;
	virtual std::string getDrawString() = 0;
	virtual std::string getEditString() = 0;
	virtual float getFloat() = 0;
	virtual int getInt() = 0;

};

#endif /* INCLUDE_CELLVALUEBASE_H_ */
