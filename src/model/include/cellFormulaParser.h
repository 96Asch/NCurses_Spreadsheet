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

	virtual float getValue() {
		return 0;
	}

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
	float getValue() {
		return value;
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
	float getValue() {
		return value;
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
	/**
	 * Constructor for the CellFormulaParser.
	 */
	CellFormulaParser() = default;
	~CellFormulaParser() = default;

	/**
	 * Parses a string into an expression tree.
	 * @param string formula, the string to be parsed.
	 * @param std::shared_ptr<Token> root, the pointer to the root of the tree.
	 * @return true if the formula is correctly parsed.
	 */
	bool parse(const std::string & formula, std::shared_ptr<Token> & root);

private:
	typedef std::list<std::string>::iterator ListIt;
	std::map<std::string, TokenType> aggregateMap = { { "AVG", AVG }, { "COUNT",
			COUNT }, { "SUM", SUM } };


   /**
	 * Returns true if the string is an operator.
	 * @param string str, the string operator.
	 * @return true if the string is an operator.
	 */
	bool isOperator(const std::string & str);
	
	/**
	 * Returns true if the char is an operator.
	 * @param string str, the char operator.
	 * @return true if the char is an operator.
	 */
	bool isOperator(const char & c); 
	
	/**
	 * Returns true if the string is an aggregate formula.
	 * @param string str, the string formula.
	 * @return true if the formula is an aggregate formula.
	 */
	bool isAggregate(const std::string & str);

	/**
	 * Returns the priority of the operator.
	 * @param char op, the operator.
	 * @return the priority of the operator.
	 */
	int getOperatorPriority(const char & op);

	/**
	 * Inserts whitespace around the operators of the string and returns it.
	 * @param string src, the string to insert whitespace.
	 * @return string with whitespaces around the operators.
	 */
	std::string fillBlankAroundOperators(const std::string & src);

	/**
	 * Returns true if a string is a negative number.
	 * @param string src, the string to check.
	 * @param size_t index, the index of the current string.
	 * @return true if the string is a negative number.
	 */
	bool isNegativeNum(const std::string & src, size_t index);

	/**
	 * Tokenizes a string around the whitespaces and puts them in a list.
	 * @param string src, the string with whitespaces to tokenize.
	 * @param std::list<std::string> tokens, the list to fill with tokens.
	 */
	void split(std::string src, std::list<std::string> & tokens);

	/**
	 * Converts a formula in the infix notation to prefix notation.
	 * @param std::list<std::string> infix, the infix notation formula to convert.
	 */
	void infixToPrefix(std::list<std::string> & infix);

	/**
	 * Splits aggregate formulae into tokens and reinserts them, preserving order.
	 * @param std::list<std::string> tokens, the list of tokens to split.
	 */
	void splitAggregates(std::list<std::string> & tokens);

	/**
	 * Parses a single token and sets the node for the expression tree.
	 * @param string token, the token to parse.
	 * @param std::shared_ptr<Token> newTok, the new node for the expression tree.
	 * @return true if the token is correctly parsed.
	 */
	bool parseToken(const std::string & token, std::shared_ptr<Token> & newTok);

	/**
	 * Builds an expression tree of a list of tokens in prefix notation.
	 * @param ListIt begin, the begin iterator of the list.
	 * @param ListIt end, the end iterator of the list.
	 * @param bool hasError, true if there was an error during building.
	 * @return std::shared_ptr<Token>, the new node of the expression tree.
	 */
	std::shared_ptr<Token> buildTree(ListIt & begin, const ListIt & end,
			bool & hasError);		

};

#endif /* INCLUDE_CELLFORMULAPARSER_H_ */
