/*
 * CellFormula.h
 *
 *  Created on: Mar 22, 2018
 *      Author: asch
 */

#ifndef INCLUDE_CELLFORMULA_H_
#define INCLUDE_CELLFORMULA_H_

#include <string>
#include <memory>

#include "cellValueBase.h"
#include "cellFormulaParser.h"
#include "sheet.h"


class CellFormula: public CellValueBase {
public:
	CellFormula(Sheet & sheet, const std::string & formula);
	~CellFormula();
	std::string getDrawString();
	std::string getEditString();
	float getFloat();
	int getInt();

	void print();

private:
	Sheet& sheet;
	std::string originalFormula, output;
	CellFormulaParser parser;
	std::shared_ptr<Token> formula;

	float result;

	float evaluate(std::shared_ptr<Token> & node);
	void print(std::shared_ptr<Token> const node);

};

#endif /* INCLUDE_CELLFORMULA_H_ */
