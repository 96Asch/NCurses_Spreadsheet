/*
  Programmeertechnieken opdracht 2
  Andrew Huang        s1913999
  Paul Peters         s1453440
  Ruben van Erkelens  s1437267
  Karl Freeke         s1551973
*/


#include "range.h"
#include "util.h"

#define DEFAULT_ADDRESS "A1"

Range::Range() {
	beginAddress.createFromReference(DEFAULT_ADDRESS);
	endAddress.createFromReference(DEFAULT_ADDRESS);
}

Range::Range(const CellAddress& begin, const CellAddress & end) : beginAddress(begin), endAddress(end) {
	++endAddress;
}


bool Range::checkRange(const std::string & address, int & split) {
	for (size_t i = 0; i < address.length(); i++) {
		if (address[i] == ':') {
			split = i;
			if (isCellAddress(address.substr(0, i))
					&& (isCellAddress(address.substr(i + 1))))
				return true;
			else
				return false;
		}
	} //for
	return false;
} //checkRange

Range* Range::createRange(CellAddress begin, CellAddress end){
	CellAddress temp;
	if (begin > end) {
	  temp = begin;
	  begin = end;
	  end = temp;
	}
	beginAddress = begin;
	endAddress = end;
	++endAddress;
	return this;
} //createRange

Range* Range::rangeFromString(const std::string & rangeString) {
	int split = 0;
	if (checkRange(rangeString, split)) {
    return createRange(CellAddress(rangeString.substr(0,split)), CellAddress(rangeString.substr(split+1)));
	} //if
	return this;
} //createRange

RangeIterator Range::begin() const{
	return RangeIterator(beginAddress, endAddress);
} //begin

RangeIterator Range::end() const{
	return RangeIterator(endAddress, endAddress);
} //end

int Range::getSize() const{
	int distanceX = 1 + endAddress.getColumn() - beginAddress.getColumn();
	int distanceY = endAddress.getRow() - beginAddress.getRow();
	return (distanceX * distanceY);
}
