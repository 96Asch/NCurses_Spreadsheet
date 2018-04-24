/*
  Programmeertechnieken opdracht 2
  Andrew Huang        s1913999
  Paul Peters         s1453440
  Ruben van Erkelens  s1437267
  Karl Freeke         s1551973
*/

#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include <string>
#include <memory>

#include "cellValue.h"
#include "cellValueBase.h"

class Cell {

public:

	/**
	 * Constructor for the Cell class.
	 */
	Cell();

	/**
	 * Sets a value in the cell.
	 * @param Celvaluebase pointer to a value
	 */
	void set(CellValueBase* base);

	/**
	 * Returns an integer value from the cell.
	 * @return integer value
	 */
	int getInt() const;

	/**
	 * Returns a float value from the cell.
	 * @return float value
	 */
	float getFloat() const;

	/**
	 * Returns a string value for editing.
	 * @return string value
	 */
	std::string getEditString() const;

	/**
	 * Returns a string value for drawing.
	 * @return string value
	 */
	std::string getDrawString() const;

	/**
	 * Clears the value of the cell
	 */
	void clear();

private:
	std::unique_ptr<CellValueBase> value;
};

#endif /* INCLUDE_CELL_H_ */
