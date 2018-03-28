/*
 * cellFormulaParser.cpp
 *
 *  Created on: Mar 26, 2018
 *      Author: asch
 */

#include "cellFormulaParser.h"
#include "util.h"
#include <boost/tokenizer.hpp>
#include <algorithm>
#include <sstream>
#include <list>
#include <stack>
#include <stdio.h>
#include <stdlib.h>

//TODO Account for multiple brackets
bool CellFormulaParser::isAggregate(const std::string & str) {
	std::string aggregates[] = { "SUM", "AVG", "COUNT" };
	size_t firstBracketIndex;
	int occurence = 0;
	for (std::string agg : aggregates) {
		if (str.size() > agg.size() && str.substr(0, agg.size()) == agg) {
			firstBracketIndex = agg.size();
			if (str[firstBracketIndex] == '(' && str.back() == ')') {
				if (contains(str.substr(firstBracketIndex + 1), ':', occurence)
						&& occurence == 1)
					return true;
			}
		}
	}
	return false;
}

int CellFormulaParser::getOperatorPriority(const char & op) {
	switch (op) {
	case '(':
	case ')':
		return 1;
	case '-':
	case '+':
		return 2;
	case '*':
	case '\\':
		return 3;
	default:
		return -1;
	}
}

bool CellFormulaParser::isNegativeNum(const std::string & src, size_t index) {
	if (index + 1 < src.size() && src[index] == '-'
			&& isdigit(src[index + 1])) {
		if (index == 0)
			return true;
		else
			return (src[index - 1] == '(') || isOperator(src[index - 1]);
	}
	return false;
}

std::string CellFormulaParser::fillBlankAroundOperators(
		const std::string & src) {
	std::string processed;
	for (size_t i = 0; i < src.size(); i++) {
		if (isOperator(src[i]) && !isNegativeNum(src, i)) {
			processed.push_back(' ');
			processed.push_back(src[i]);
			processed.push_back(' ');
		} else
			processed.push_back(src[i]);
	}
	return processed;
}

void CellFormulaParser::split(std::string rename,
		std::list<std::string> & tokens) {
	std::string tokenString, aggregateString;
	bool aggregateMode = false;

	rename = fillBlankAroundOperators(rename);
	std::stringstream ss(rename);

	while (std::getline(ss, tokenString, ' ')) {
		if (!tokenString.empty()) {
			if (tokenString == "SUM" || tokenString == "AVG"
					|| tokenString == "COUNT") {
				aggregateMode = true;
			}
			if (aggregateMode) {
				aggregateString += tokenString;
				if (tokenString.front() == ')') {
					aggregateMode = false;
					tokenString = aggregateString;
					aggregateString.clear();
				}
			}

			if (!aggregateMode) {
				tokens.push_back(tokenString);
			}
		}
	}
}

//bool CellFormulaParser::parseToken(const char & renamed, Token* token) {
//	if(isOperator(renamed)) {
//		token = new Token;
//		switch(renamed) {
//		case '+':
//			token->type = Token::PLUS;
//			return true;
//		case '-':
//			token->type = Token::PLUS;
//			return true;
//		case '/':
//			token->type = Token::PLUS;
//			return true;
//		case '*':
//			token->type = Token::PLUS;
//			return true;
//		default:
//			delete token;
//			token = nullptr;
//			return false;
//		}
//	}
//}

//Token* CellFormulaParser::buildTree(const std::string & prefix, size_t index, bool & hasError) {
//	Token* token = nullptr;
//	if (index < prefix.size()) {
//		if(!parseToken(prefix[index++], token)){
//			hasError = true;
//			return nullptr;
//		}
//		else if(token->isOperator) {
//			token->left = buildTree(prefix, index, hasError);
//			token->right = buildTree(prefix, index, hasError);
//		}
//		else {
//			token->left = token->right = nullptr;
//		}
//	}
//}

bool CellFormulaParser::parse(const std::string & formula) {

	if (formula.front() != '=')
		return false;
	printf("O: %s\n", formula.c_str());
	std::list < std::string > tokens;
	split(formula.substr(1, formula.size() - 1), tokens);
	infixToPrefix (tokens);
	for (std::string s : tokens) {
		printf("Token: %s\n", s.c_str());
	}
	return true;
}

void CellFormulaParser::infixToPrefix(std::list<std::string> & tokens) {
	std::list < std::string > temp;
	std::stack<char> charStack;
	std::string operators;
	char op;

	for (auto it = tokens.rbegin(); it != tokens.rend(); it++) {
		if (!isOperator(*it)) {
			temp.push_back(*it);
		} else {
			op = (*it).front();
			if (op == ')')
				charStack.push(op);
			else if (op == '(') {
				while (!charStack.empty() && charStack.top() != ')') {
					operators = charStack.top();
					temp.push_back(operators);
					charStack.pop();
				}
				charStack.pop();
			} else {
				if (!charStack.empty()
						&& getOperatorPriority(charStack.top())
								<= getOperatorPriority(op)) {
					charStack.push(op);
				} else {
					while (!charStack.empty()
							&& getOperatorPriority(charStack.top())
									>= getOperatorPriority(op)) {
						operators = charStack.top();
						temp.push_back(operators);
					}
					charStack.push(op);
				}
			}
		}
	}
	while (!charStack.empty()) {
		operators = charStack.top();
		temp.push_back(operators);
		charStack.pop();
	}
	tokens.clear();
	tokens.assign(temp.rbegin(), temp.rend());
}

