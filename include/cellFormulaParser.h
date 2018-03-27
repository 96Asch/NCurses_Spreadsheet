/*
 * cellFormulaParser.h
 *
 *  Created on: Mar 26, 2018
 *      Author: asch
 */

#ifndef INCLUDE_CELLFORMULAPARSER_H_
#define INCLUDE_CELLFORMULAPARSER_H_

#include <string>
#include <vector>
#include <stack>
#include <map>
#include "cellAddress.h"

enum Operator {
	PLUS, MINUS, DIVIDE, MULTIPLICATION, AVG, COUNT, SUM
};



class CellFormulaParser {
public:
	CellFormulaParser() = default;
	~CellFormulaParser() = default;
	bool parse(const std::string & formula);

private:
	std::string prefix;
	std::map<char, std::string> renameTable;
	char renamable = 33;

	void fillBlankAroundOperatorsAndAppend(std::string &copy,
			const std::string & src);
	char getRenamable();
	void rename(std::string & rename);
	void reverseRename(std::string & rename);
	bool parseToken(const std::string & tokenString);
	bool parseSub(const std::string & subFormula);
	void infixToPostfix(std::stack<char> & charStack, std::string & formula);
	bool isAggregate(const std::string & str);
	int getOperatorPriority(const char & op);

};

#endif /* INCLUDE_CELLFORMULAPARSER_H_ */
