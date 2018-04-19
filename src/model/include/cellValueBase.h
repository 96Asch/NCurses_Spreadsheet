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
	virtual ~CellValueBase();
	virtual std::string getDrawString() const = 0;
	virtual std::string getEditString() const = 0;
	virtual float getFloat() const = 0;
	virtual int getInt() const = 0;
	static CellValueBase* cellValueFactory (const std::string & input);

};

#endif /* INCLUDE_CELLVALUEBASE_H_ */
