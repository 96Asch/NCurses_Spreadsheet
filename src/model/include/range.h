/*
  Programmeertechnieken opdracht 2
  Andrew Huang        s1913999
  Paul Peters         s1453440
  Ruben van Erkelens  s1437267
  Karl Freeke         s1551973
*/

#ifndef INCLUDE_RANGE_H_
#define INCLUDE_RANGE_H_

#include "cellAddress.h"
#include "cell.h"
#include "sheet.h"

#include <string>

class RangeIterator;

class Range {
public:
	/**
	 * Constructor of the Range class.
	 */
	Range();

	/**
	 * Constructor of the Range class.
	 * @param CellAddress begin, the begin address of the range.
	 * @param CellAddress end, the end address of the range.
	 */
	Range(const CellAddress & begin, const CellAddress & end);

	/**
	 * Destructor of the Range class.
	 */
	~Range() = default;

	/**
	 * Creates a Range pointer which iterates over the given range.
	 * @param CellAddress begin, the begin address of the range.
	 * @param CellAddress end, the end address of the range.
	 * @return Range*, pointer to the created range.
	 */
	Range* createRange(CellAddress begin, CellAddress end);

	/**
	 * Creates a Range pointer which iterates over the given range.
	 * @param std::string rangeString, the range to iterate over.
	 * @return Range*, pointer to the created range.
	 */
	Range* rangeFromString(const std::string & rangeString);

	/**
	 * Returns an iterator to the begin of the range.
	 * @return RangeIterator, an iterator to the begin of the range.
	 */
	RangeIterator begin() const;

	/**
	 * Returns an iterator to the end of the range.
	 * @return RangeIterator, an iterator to the end of the range.
	 */
	RangeIterator end() const;

	/**
	 * Returns the number of cells to iterate over.
	 * @return int, the number of cells to iterate over.
	 */
	int getSize() const;

	typedef RangeIterator iterator;

private:
	CellAddress beginAddress;
	CellAddress endAddress;

	bool checkRange(const std::string & address, int & split) const;
};

class RangeIterator: public std::iterator<std::input_iterator_tag, Cell> {
private:
	int offsetX, offsetY;
	int beginY, endX, endY;

public:
	RangeIterator(const CellAddress & beginAdd, const CellAddress & endAdd) :
			offsetX(beginAdd.getColumn()), offsetY(beginAdd.getRow()), beginY(
					beginAdd.getRow()), endX(endAdd.getColumn()), endY(
					endAdd.getRow()) {
	}

	bool operator==(const RangeIterator &iter) const {
		return (iter.offsetY == offsetY && iter.offsetX == offsetX);
	}

	bool operator!=(const RangeIterator &iter) const {
		return !operator==(iter);
	}

	Cell &operator*() const {
		return Sheet::getInstance().getCell(offsetY, offsetX);
	}

	Cell *operator->() const {
		return &Sheet::getInstance().getCell(offsetY, offsetX);
	}

	RangeIterator &operator++() {
		if (offsetX <= endX) {
			offsetY++;
			if (offsetY >= endY && offsetX != endX) {
				offsetX++;
				offsetY = beginY;
			}
		}
		return *this;
	}

	RangeIterator &operator++(int) {
		if (offsetX <= endX) {
			offsetY++;
			if (offsetY >= endY && offsetX != endX) {
				offsetX++;
				offsetY = beginY;
			}
		}
		return *this;
	}

};
#endif 
