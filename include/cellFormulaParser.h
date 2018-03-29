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
#include <memory>
#include <iostream>
#include "cellAddress.h"

enum TokenType {
	PLUS,
	MINUS,
	DIVIDE,
	MULTIPLICATION,
	AVG,
	COUNT,
	SUM,
	CELLADDRESS,
	INT,
	FLOAT
};

struct Token {
	Token();
	Token(const TokenType & type, const bool & isAgg) :
			type(type), isOperator(isAgg) {
		left = right = nullptr;
	}

	Token(const TokenType & type) :
			type(type), isOperator(false) {
		left = right = nullptr;
	}
	virtual ~Token() = default;
	virtual std::string toString() {
		switch (type) {
		case PLUS:
			return "+";
		case MINUS:
			return "-";
		case DIVIDE:
			return "/";
		case MULTIPLICATION:
			return "*";
		case AVG:
			return " AVG ";
		case COUNT:
			return " COUNT ";
		case SUM:
			return " SUM ";
		default:
			return "ERR";
		}
	}
	;

	TokenType type;
	bool isOperator;
	std::shared_ptr<Token> left, right;
};

struct Operator: Token {
	Operator(const TokenType & type) :
			Token(type, true) {
	}

};

struct Float: Token {
	Float(const float & number) :
			Token(FLOAT), value(number) {
	}
	std::string toString() {
		return std::to_string(value);
	}
	float value;
};

struct Integer: Token {
	Integer(const int & number) :
			Token(INT), value(number) {
	}
	std::string toString() {
		return std::to_string(value);
	}
	int value;
};

struct Address: Token {
	Address(const std::string & token) :
			Token(CELLADDRESS), address(token) {
	}
	std::string toString() {
		return address;
	}
	std::string address;
};

class CellFormulaParser {
public:
	CellFormulaParser() = default;
	~CellFormulaParser() = default;
	bool parse(const std::string & formula, std::shared_ptr<Token> & root);

private:
	typedef std::list<std::string>::iterator ListIt;
	std::map<std::string, TokenType> aggregateMap = { { "AVG", AVG }, { "COUNT",
			COUNT }, { "SUM", SUM } };

	bool isAggregate(const std::string & str);
	int getOperatorPriority(const char & op);
	std::string fillBlankAroundOperators(const std::string & src);
	bool isNegativeNum(const std::string & src, size_t index);
	void split(std::string rename, std::list<std::string> & tokens);
	void infixToPrefix(std::list<std::string> & infix);
	void splitAggregates(std::list<std::string> & tokens);

	bool parseToken(const std::string & token, std::shared_ptr<Token> & newTok);
	std::shared_ptr<Token> buildTree(ListIt & begin, const ListIt & end,
			bool & hasError);

};

#endif /* INCLUDE_CELLFORMULAPARSER_H_ */
