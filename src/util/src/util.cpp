/*
  Programmeertechnieken opdracht 2
  Andrew Huang        s1913999
  Paul Peters         s1453440
  Ruben van Erkelens  s1437267
  Karl Freeke         s1551973
*/

#include "iostream"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <fenv.h>

bool contains(const std::string & src, const char & c, int & occurence) {
	for (char ch : src)
		if (ch == c)
			occurence++;
	if (occurence > 0)
		return true;
	return false;
}

bool isCellAddress(const std::string & address) {
	bool digitMode = false;
	size_t digitIn = 0;
	if(address.empty())
		return false;
	splitAddress(address, digitIn);
	if (digitIn > MAX_COL_LENGTH || (address.length() - digitIn) > MAX_ROW_LENGTH)
		return false;
	if (!isupper(address.front()) || address.size() < 2)
	  return false;
	for (size_t i = 1; i < address.size(); i++) {
	  if (!isdigit(address[i]) && !isupper(address[i]))
	    return false;
	  if (!digitMode) 
	    if (isdigit(address[i]))
        digitMode = true;	  
	  if (digitMode)
	    if (!isdigit(address[i]))
	      return false;
	}
	return true;
}

void splitAddress(const std::string & address, size_t & index) {
	for (size_t i = 0; i < address.length(); i++) {
		if (isdigit(address[i])) {
			index = i;
			break;
		}
	}
}


