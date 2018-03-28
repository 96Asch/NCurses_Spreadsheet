/*
 * util.h
 *
 *  Created on: Mar 26, 2018
 *      Author: asch
 */

#ifndef INCLUDE_UTIL_H_
#define INCLUDE_UTIL_H_

#include <string>
#include <boost/lexical_cast.hpp>

template<typename T>
bool is(std::string someString, T & casted) {
	using boost::lexical_cast;
	using boost::bad_lexical_cast;

	try {
		casted = boost::lexical_cast < T > (someString);
	} catch (bad_lexical_cast &) {
		return false;
	}

	return true;
}

bool contains(const std::string & src, const char & c, int & occurence);
bool isCellAddress(const std::string & address);
bool isOperator(const std::string & str);
bool isOperator(const char & c);



#endif /* INCLUDE_UTIL_H_ */
