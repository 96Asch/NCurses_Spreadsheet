/*
  Programmeertechnieken opdracht 2
  Andrew Huang        s1913999
  Paul Peters         s1453440
  Ruben van Erkelens  s1437267
  Karl Freeke         s1551973
*/

#ifndef INCLUDE_COLUMN_H_
#define INCLUDE_COLUMN_H_

#include "cell.h"
#include <vector>

class Column {
public:
	/**
	 * Constructor of the Column class.
	 */
	Column();

	/**
	 * Constructor of the Column class.
	 * @param int rows, the number of rows to put into the column.
	 */
	Column(const int & rows);

	/**
	 * Returns a reference to the cell in the column.
	 * @param int index, the row index to retrieve the cell.
	 * @return Cell&, a reference to the cell.
	 */
	Cell& getCell(const int & index);

	/**
	 * Resizes the column.
	 * @param int rows, the number of rows to resize the column with.
	 */
	void resize(const int & rows);

	/**
	 * Returns an iterator to the begin of the column.
	 * @return std::vector<Cell>::iterator, iterator to the begin of the column.
	 */
	std::vector<Cell>::iterator begin();

	/**
	 * Returns an iterator to the begin of the column.
	 * @return std::vector<Cell>::iterator, iterator to the begin of the column.
	 */
	std::vector<Cell>::iterator end();
	typedef std::vector<Cell>::iterator iterator;

private:
	std::vector<Cell> column;

};

#endif
