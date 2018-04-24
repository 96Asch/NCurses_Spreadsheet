/*
  Programmeertechnieken opdracht 2
  Andrew Huang        s1913999
  Paul Peters         s1453440
  Ruben van Erkelens  s1437267
  Karl Freeke         s1551973
*/

#ifndef INCLUDE_SHEET_H_
#define INCLUDE_SHEET_H_

#include "cell.h"
#include "column.h"
#include <vector>
#include <subject.h>

class Sheet : public Subject{
public:
	/**
	 * Returns an singleton of  the Sheet datastructure.
	 * @return Sheet, a static reference to the sheet.
	 */
	static Sheet& getInstance();

	/**
	 * Returns an iterator to the begin of the vector.
	 * @return std::vector<Column>::iterator, an iterator the begin of the vector<Column>.
	 */
	std::vector<Column>::iterator begin();

	/**
	 * Returns an iterator to the end of the vector.
	 * @return std::vector<Column>::iterator, an iterator the end of the vector<Column>.
	 */
	std::vector<Column>::iterator end();

	/**
	 * Returns a reference to a cell in the sheet.
	 * @param int row, the row index of the sheet.
	 * @param int column, the column index of the sheet.
	 */
	Cell& getCell(const int & row, const int & column);

	/**
	 * Resizes the sheet datastructure.
	 * @param int rows, the amount of rows the sheet should have.
	 * @param int cols, the amount of columns the sheet should have.
	 */
	void ensureSize(const int & rows, const int & cols);

	/**
	 * Returns the number of rows of the sheet.
	 * @return int, the number of rows of the sheet.
	 */
	int getRows() const;

	/**
	 * Returns the number of columns of the sheet.
	 * @return int, the number of columns of the sheet.
	 */
	int getCols() const;

	/**
	 * Notifies all observers of the sheet.
	 */
	void notify() override;

	typedef std::vector<Column>::iterator iterator;

private:
	int rows, cols;
	std::vector<Column> sheet;

	/**
	 * Constructor of the Sheet class.
	 */
	Sheet();

	/**
	 * Constructor of the Sheet class.
	 * @param int rows, the amount of rows the sheet should have.
	 * @param int cols, the amount of columns the sheet should have.
	 */
	Sheet(const int & rows, const int & cols);

	/**
	 * Destructor of the Sheet class.
	 */
	~Sheet() = default;

	/**
	 * Copy constructor of the Sheet class.
	 * Since Sheet is a singleton the copy constructor is disabled.
	 */
	Sheet(Sheet const&) = delete;

	/**
	 * Assignment operator of the Sheet class.
	 * Since Sheet is a singleton the assignment operator is disabled.
	 */
    void operator=(Sheet const&) = delete;

};

#endif
