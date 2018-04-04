#ifndef INCLUDE_RANGE_H_
#define INCLUDE_RANGE_H_

#include <string>
#include "cellAddress.h"
#include "cell.h"
#include "sheet.h"

class RangeIterator;

class Range {
public:
	Range() = default;
	~Range() = default;

	Range* createRange(CellAddress begin, CellAddress end, Sheet* sheet);
	Range* rangeFromString(const std::string & rangeString, Sheet* sheet);
	RangeIterator begin();
	RangeIterator end();
	int getSize();
	typedef RangeIterator iterator;

private:
	CellAddress beginAddress;
	CellAddress endAddress;
	Sheet* sheet;

	bool checkRange(const std::string & address, int & split);
};

class RangeIterator: public std::iterator<std::input_iterator_tag, Cell> {
private:
	Sheet* sheet;
	int offsetX, offsetY;
	int beginY, endX, endY;

public:
	RangeIterator(Sheet* sheet, const CellAddress & beginAdd,
			const CellAddress & endAdd) :
			sheet(sheet), offsetX(beginAdd.getColumn()), offsetY(
					beginAdd.getRow()), beginY(beginAdd.getRow()), endX(
					endAdd.getColumn()), endY(endAdd.getRow()) {
	}

	//TODO FIX equals
	/* Zijn de iteratoren gelijk aan elkaar? */
	bool operator==(const RangeIterator &iter) const {
		return (iter.offsetY == offsetY && iter.offsetX == offsetX);
	}

	bool operator!=(const RangeIterator &iter) const {
		return !operator==(iter);
	}

	/* Element op de huidige plek van de iterator uitlezen */
	Cell &operator*() const {
		return sheet->getCell(offsetY, offsetX);
	}

	Cell *operator->() const {
		return &sheet->getCell(offsetY, offsetX);
	}

	/* Implementeer "++iter": verplaats de iterator een plek */
	RangeIterator &operator++() {
		if (offsetX <= endX) {
			offsetY++;
			if (offsetY > endY) {
				offsetX++;
				offsetY = beginY;
			}
		}
		return *this;
	}

	RangeIterator &operator++(int) {
		if (offsetX <= endX) {
			offsetY++;
			if (offsetY > endY) {
				offsetX++;
				offsetY = beginY;
			}
		}
		return *this;
	}

};
#endif 
