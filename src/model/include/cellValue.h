/*
 * cellValue.h
 *
 *  Created on: Mar 22, 2018
 *      Author: asch
 */

#ifndef INCLUDE_CELLVALUE_H_
#define INCLUDE_CELLVALUE_H_

#include "cellValueBase.h"

#include <boost/lexical_cast.hpp>


template<typename T>
class CellValue final : public CellValueBase {
private:
	T value;
public:

	/**
	 * Constructor for the CellValue class.
	 * @param T value, the value to store into the CellValue.
	 */
	CellValue(T initial_value) :
			CellValueBase(), value(initial_value) {

	}

	/**
	 * Destructor for the CellValue class.
	 */
	~CellValue() = default;

	/**
	 * Returns a string value for drawing.
	 * @return string value
	 */
	std::string getDrawString() const{
		using boost::lexical_cast;
		using boost::bad_lexical_cast;
		try {
			return lexical_cast<std::string>(value);
		} catch (bad_lexical_cast &) {
			return "error";
		}
	} //getDrawString

	/**
	 * Returns a string value for editing.
	 * @return string value
	 */
	std::string getEditString() const{
		using boost::lexical_cast;
		using boost::bad_lexical_cast;
		try {
			return lexical_cast<std::string>(value);
		} catch (bad_lexical_cast &) {
			return "error";
		}
	} //getEditString

	/**
	 * Returns a float value from the cell.
	 * @return float value
	 */
	float getFloat() const{
		using boost::lexical_cast;
		using boost::bad_lexical_cast;
		try {
			return lexical_cast<float>(value);
		} catch (bad_lexical_cast &) {
			return 0;
		}
	} //getFloat

	/**
	 * Returns an integer value from the cell.
	 * @return integer value
	 */
	int getInt() const{
		using boost::lexical_cast;
		using boost::bad_lexical_cast;
		try {
			return lexical_cast<int>(value);
		} catch (bad_lexical_cast &) {
			return 0;
		}
	} //getFloat
};
//CellValue   

#endif /* INCLUDE_CELLVALUE_H_ */
