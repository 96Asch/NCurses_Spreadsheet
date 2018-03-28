/*
 * cellFormulaParser.h
 *
 *  Created on: Mar 26, 2018
 *      Author: asch
 */

#ifndef INCLUDE_CELLFORMULAPARSER_H_
#define INCLUDE_CELLFORMULAPARSER_H_

#include <string>
#include <map>
#include <list>
#include "cellAddress.h"

//enum TokenType {
//	PLUS,
//	MINUS,
//	DIVIDE,
//	MULTIPLICATION,
//	AVG,
//	COUNT,
//	SUM,
//	CELLADDRESS,
//	INT,
//	FLOAT
//};
//
//struct Token {
//	Token(const TokenType & type, const bool & isOperator) :
//			type(type), isOper(isOperator) {
//	}
//
//	union {
//		CellAddress address;
//		int integer;
//		float floatingPoint;
//	} value;
//
//	TokenType type;
//	bool isOper;
//	Token* left, *right;
//};

class CellFormulaParser {
public:
	CellFormulaParser() = default;
	~CellFormulaParser() = default;
	bool parse(const std::string & formula);

private:

	std::string fillBlankAroundOperators(const std::string & src);
	bool isNegativeNum(const std::string & src, size_t index);
	void split(std::string rename, std::list<std::string> & tokens);
//	bool parseToken(const char & renamed, Token* token);
//	Token* buildTree(const std::string & prefix, size_t index, bool & hasError);
	bool isAggregate(const std::string & str);
	int getOperatorPriority(const char & op);
	void infixToPrefix(std::list<std::string> & infix);
};

#endif /* INCLUDE_CELLFORMULAPARSER_H_ */
