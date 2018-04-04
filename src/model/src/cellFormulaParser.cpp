/*
 * cellFormulaParser.cpp
 *
 *  Created on: Mar 26, 2018
 *      Author: asch
 */

#include "cellFormulaParser.h"
#include "util.h"
#include <sstream>
#include <algorithm>
#include <list>
#include <stack>

bool CellFormulaParser::isAggregate(const std::string & str) {
	std::string aggregates[] = { "SUM", "AVG", "COUNT" };
	size_t firstBracketIndex;
	int occurence = 0;
	for (std::string agg : aggregates) {
		if (str.size() > agg.size() && str.substr(0, agg.size()) == agg) {
			firstBracketIndex = agg.size();
			if (str[firstBracketIndex] == '(' && str.back() == ')') {
				if (contains(str.substr(firstBracketIndex + 1), ':', occurence)
						&& occurence == 1) {
					return true;
				}
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
	tokens.assign(temp.rbegin(), temp.rend());
}

void CellFormulaParser::splitAggregates(std::list<std::string> & tokens) {
	std::string delim = "(:)";
	std::list < std::string > tempList;
	std::string temp;
	for (std::string token : tokens) {
		if (isAggregate(token)) {
			std::stringstream ss(token);
			for (size_t i = 0; i < delim.size(); i++) {
				std::getline(ss, temp, delim[i]);
				if (!temp.empty())
					tempList.push_back(temp);
			}
		} else {
			tempList.push_back(token);
		}
	}
	tokens.assign(tempList.begin(), tempList.end());
}

bool CellFormulaParser::parseToken(const std::string & token,
		std::shared_ptr<Token> & newTok) {
	int intVal;
	float floatVal;
	if (isOperator(token)) {
		switch (token.front()) {
		case '+':
			newTok = std::make_shared < Operator > (PLUS);
			break;
		case '-':
			newTok = std::make_shared < Operator > (MINUS);
			break;
		case '/':
			newTok = std::make_shared < Operator > (DIVIDE);
			break;
		case '*':
			newTok = std::make_shared < Operator > (MULTIPLICATION);
			break;
		default:
			return false;
		}
	} else if (token == "AVG" || token == "SUM" || token == "COUNT")
		newTok = std::make_shared < Operator > (aggregateMap.at(token));
	else if (isCellAddress(token))
		newTok = std::make_shared < Address > (token);
	else if (is<int>(token, intVal))
		newTok = std::make_shared < Integer > (intVal);
	else if (is<float>(token, floatVal))
		newTok = std::make_shared < Float > (floatVal);
	else
		return false;
	return true;
}

std::shared_ptr<Token> CellFormulaParser::buildTree(ListIt & begin,
		const ListIt & end, bool & hasError) {
	std::shared_ptr<Token> token;
	if (begin != end) {
		if (!parseToken(*begin++, token)) {
			hasError = true;
			return nullptr;
		} else if (token && token->isOperator) {
			token->left = buildTree(begin, end, hasError);
			token->right = buildTree(begin, end, hasError);
			if (token->type == DIVIDE && token->right
					&& (token->right->type == INT || token->right->type == FLOAT)
					&& token->right->getValue() == 0) {
				hasError = true;
				return nullptr;
			}
		} else {
			token->right = token->left = nullptr;

		}
		return token;
	}
	return nullptr;
}

bool CellFormulaParser::parse(const std::string & formula,
		std::shared_ptr<Token> & root) {

	if (formula.front() != '=')
		return false;

	root = nullptr;
	bool hasError = false;
	std::list < std::string > tokens;

	split(formula.substr(1, formula.size() - 1), tokens);
	infixToPrefix (tokens);
	splitAggregates(tokens);
	ListIt tokenIt = tokens.begin();
	root = buildTree(tokenIt, tokens.end(), hasError);

	if (hasError) {
		root = nullptr;
		return false;
	}
	return true;
}

