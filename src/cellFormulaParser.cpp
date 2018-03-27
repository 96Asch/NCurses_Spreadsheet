/*
 * cellFormulaParser.cpp
 *
 *  Created on: Mar 26, 2018
 *      Author: asch
 */

#include "cellFormulaParser.h"
#include "util.h"
#include <boost/tokenizer.hpp>
#include<algorithm>
#include <sstream>
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
	case '-':
	case '+':
		return 2;
	case '*':
	case '\\':
		return 1;
	default:
		return -1;
	}
}

void CellFormulaParser::fillBlankAroundOperatorsAndAppend(std::string &copy,
		const std::string & src) {
	for (char c : src) {
		if (isOperator(c) || c == '(' || c == ')') {
			copy.push_back(' ');
			copy.push_back(c);
			copy.push_back(' ');
		} else
			copy.push_back(c);
	}
}

char CellFormulaParser::getRenamable() {
	char newRenamable;
	while (!isValidRename(renamable)) {
		renamable++;
	}
	newRenamable = renamable;
	renamable++;

	if (renamable == 127)
		renamable = 33;
	return newRenamable;
}

//TODO Fix (A3-A5) corner cases in a better way
void CellFormulaParser::rename(std::string & rename) {
	std::string copy, tokenString, aggregateString;
	char temp;
	bool aggregateMode = false;
	fillBlankAroundOperatorsAndAppend(copy, rename);
	rename.clear();
	std::stringstream ss(copy);
//	printf("Original String: %s\n", copy.c_str());
	while (std::getline(ss, tokenString, ' ')) {
		if (!tokenString.empty()) {

			if(tokenString == "SUM" || tokenString == "AVG" || tokenString == "COUNT") {
				aggregateMode = true;
			}

			if(aggregateMode) {
				aggregateString += tokenString;
				if(tokenString.front() == ')') {
					aggregateMode = false;
					tokenString = aggregateString;
					aggregateString.clear();
				}
			}

			if (isAggregate(tokenString) || isCellAddress(tokenString)
					|| isCellAddress(tokenString.substr(1))
					|| isCellAddress(
							tokenString.substr(0, tokenString.size() - 1))) {
				temp = getRenamable();
				renameTable.insert(std::make_pair(temp, tokenString));
				rename.push_back(temp);
			} else if(!aggregateMode){
				rename += tokenString;
			}
//						printf("Token: %s\n", tokenString.c_str());
			//			printf("is aggregate?: %s\n", isAggregate(tokenString) ? "YES" : "NO");
		}


	}
}

void CellFormulaParser::reverseRename(std::string & rename) {
	std::string temp;
	for (char c : rename) {
		if (isValidRename(c)) {
			if (renameTable.count(c))
				temp += renameTable.at(c);
		} else {
			temp.push_back(c);
		}
	}
	rename = temp;
}

bool CellFormulaParser::parse(const std::string & formula) {
	if (formula.front() != '=')
		return false;
	std::string copy = formula.substr(1, formula.size() - 1);

	rename(copy);

//	while (!charStack.empty()) {
//		char c = charStack.top();
//		charStack.pop();
//		prefix += c;
//		printf("Rest: %c\n", c);
//	}
//	printf("Postfix: %s\n", prefix.c_str());
//	prefix.clear();
	printf("Renamed String: %s\n", copy.c_str());

	reverseRename(copy);
	printf("Turned back String: %s\n", copy.c_str());

	return true;
}

void CellFormulaParser::infixToPostfix(std::stack<char> & charStack,
		std::string & infix) {
	if (!isOperator(infix)) {
		prefix += infix;
		printf("Operand: %s\n", infix.c_str());
	} else if (infix == "(") {
		charStack.push('(');
	} else if (infix == ")") {
		while (!charStack.empty() && charStack.top() != '(') {
			char c = charStack.top();
			charStack.pop();
			prefix += c;
			printf("Operator: %c\n", c);
		}
		if (!charStack.empty() && charStack.top() == '(') {
			charStack.pop();
		}
	} else {
		while (!charStack.empty()
				&& getOperatorPriority(infix.front())
						<= getOperatorPriority(infix.front())) {
			if (charStack.top() == '(')
				charStack.pop();
			else {
				char c = charStack.top();
				printf("op %c\n", c);
				charStack.pop();
				prefix += c;
			}
		}
		charStack.push(infix.front());
	}
}

