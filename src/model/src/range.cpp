#include "range.h"
#include "util.h"

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

Range* Range::createRange(CellAddress begin, CellAddress end) {
	beginAddress = begin;
	endAddress = end;
	return this;
} //createRange

Range* Range::rangeFromString(const std::string & rangeString) {
	int split = 0;
	if (checkRange(rangeString, split)) {
		beginAddress.createFromReference(rangeString.substr(0, split));
		endAddress.createFromReference(rangeString.substr(split + 1));
	} //if
	return this;
} //createRange

RangeIterator Range::begin() {
	return RangeIterator(beginAddress, endAddress);
} //begin

RangeIterator Range::end() {
	return RangeIterator(endAddress, endAddress);
} //end

int Range::getSize() {
	int distanceX = 1 + endAddress.getColumn() - beginAddress.getColumn();
	int distanceY = 1 + endAddress.getRow() - beginAddress.getRow();
	return (distanceX * distanceY);
}
