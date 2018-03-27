/*
 * CellFormula.h
 *
 *  Created on: Mar 22, 2018
 *      Author: asch
 */

#ifndef INCLUDE_CELLFORMULA_H_
#define INCLUDE_CELLFORMULA_H_

#include <string>
#include "cellValueBase.h"

class CellFormula : public CellValueBase{
public:
	CellFormula(const std::string & formula);
	~CellFormula() = default;
	std::string getDrawString();
	std::string getEditString();
	float getFloat();
	int getInt();

private:
	std::string originalFormula;

	void parse(const std::string & formula);


};

#endif /* INCLUDE_CELLFORMULA_H_ */
