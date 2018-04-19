/*
 * util.h
 *
 *  Created on: Mar 26, 2018
 *      Author: asch
 */

#ifndef INCLUDE_UTIL_H_
#define INCLUDE_UTIL_H_

#define MAX_COL_LENGTH 3
#define MAX_ROW_LENGTH 3

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
void splitAddress(const std::string & address, size_t & index);
bool contains(const std::string & src, const char & c, int & occurence);
bool isCellAddress(const std::string & address);


#endif /* INCLUDE_UTIL_H_ */
