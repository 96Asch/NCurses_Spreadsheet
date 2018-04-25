/*
  Programmeertechnieken opdracht 2
  Andrew Huang        s1913999
  Paul Peters         s1453440
  Ruben van Erkelens  s1437267
  Karl Freeke         s1551973
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

bool checkRange(const std::string & address, int & split);
void splitAddress(const std::string & address, size_t & index);
bool contains(const std::string & src, const char & c, int & occurence);
bool isCellAddress(const std::string & address);


#endif /* INCLUDE_UTIL_H_ */
