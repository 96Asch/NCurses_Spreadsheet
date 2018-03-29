/*
 * util.cpp
 *
 *  Created on: Mar 26, 2018
 *      Author: asch
 */

#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


bool contains(const std::string & src, const char & c, int & occurence) {
	for(char ch : src)
		if(ch == c)
			occurence++;
	if(occurence > 0)
		return true;
	return false;
}

//TODO: limit amount of addresses
bool isCellAddress(const std::string & address) {
	bool digitMode = false;
	if (address.size() >= 2 && isalpha(address.front())
			&& isdigit(address.back())) {
		for (size_t i = 1; i < address.size() - 1; i++) {
			if (isdigit(address[i]) && !digitMode) {
				digitMode = true;
			} else if (digitMode && isalpha(address[i])) {
				return false;
			}
		}
		return true;
	}
	return false;
}

bool isOperator(const std::string & str) {
	return (str.size() == 1 && isOperator(str.front()));
}

bool isOperator(const char & c) {
	switch(c) {
	case '+':
	case '-':
	case '/':
	case '*':
	case '(':
	case ')':
		return true;
	default:
		return false;
	}
}

bool isInteger(const float & val) {
	return val == ceilf(val);
}

