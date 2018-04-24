/*
 * CellFormula.h
 *
 *  Created on: Mar 22, 2018
 *      Author: asch
 */

#ifndef INCLUDE_CELLFORMULA_H_
#define INCLUDE_CELLFORMULA_H_

#include <string>
#include <memory>

#include "cellValueBase.h"
#include "cellFormulaParser.h"
#include "range.h"
#include "observer.h"

class CellFormula: public CellValueBase, public Observer{
public:
	/**
	 * Constructor for the CellFormula class..
	 * @param std::string formula, the input formula.
	 */
	CellFormula(const std::string & formula);
	~CellFormula();

	/**
	 * Returns the result of the formula to draw.
	 * @return std::string, result to draw.
	 */
	std::string getDrawString() const;

	/**
	 * Returns the raw formula.
	 * @return std::string, the raw formula.
	 */
	std::string getEditString() const;

	/**
	 * Returns the result of the formula as a float.
	 * @return float, value of the formula.
	 */
	float getFloat() const;

	/**
	 * Returns the result of the formula as an int.
	 * @return int, value of the formula.
	 */
	int getInt() const;

	/**
	 * Updates the calculation of the formula.
	 */
	void update() override;

private:
	Range range;
	std::string originalFormula, output;
	std::shared_ptr<Token> formula;
	float result;
	bool calculationError, parserError;

	/**
	 * Calculates the sum of the cells within the given range.
	 * @param std::string begin, the begin address of the range.
	 * @param std::string end, the end address of the range.
	 * @return float, the result of the summation.
	 */
	float sum(const std::string & begin, const std::string & end);

	/**
	 * Calculates the average of the cells within the given range.
	 * @param std::string begin, the begin address of the range.
	 * @param std::string end, the end address of the range.
	 * @return float, the result of the mean.
	 */
	float average(const std::string & begin, const std::string & end);

	/**
	 * Counts the number of the cells within the given range.
	 * @param std::string begin, the begin address of the range.
	 * @param std::string end, the end address of the range.
	 * @return float, the result of the counting.
	 */
	float count(const std::string & begin, const std::string & end);

	/**
	 * Recursively evaluates the stored expression tree.
	 * @param std::shared_ptr<Token> node, the current node to evaluate.
	 * @return float, the result of the evaluation.
	 */
	float evaluate(std::shared_ptr<Token> & node);
	
	 /**
	 * Returns true if float val contains an integer
	 * @param float val, the float that will be evaluated
	 * @return true if float val contains an integer 
	 */
	bool isInteger(const float & val);

	/**
	 * Returns true if the Cell already has a string.
	 * @param Cell cell, the cell to look at.
	 * @return bool, true if the cell has a string value.
	 */
	bool isCellAString (const Cell & cell);

	/**
	 * Evaluates the parse tree and sets the output variables.
	 * Sets the output to ERR if there is an error.
	 * @param bool recalculate, indicates whether this is a recalculation.
	 */
	void calculate();

};

#endif /* INCLUDE_CELLFORMULA_H_ */
