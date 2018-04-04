/*
 * cellValue.h
 *
 *  Created on: Mar 22, 2018
 *      Author: asch
 */

#ifndef INCLUDE_CELLVALUE_H_
#define INCLUDE_CELLVALUE_H_

#include <boost/lexical_cast.hpp>
#include "cellValueBase.h"

template<typename T>
class CellValue final : public CellValueBase {
private:
	T value;
public:
	CellValue(T initial_value) :
			CellValueBase(), value(initial_value) {

	}
	~CellValue() = default;
	T getValue() {
		return value;
	}

	std::string getDrawString() const{
		using boost::lexical_cast;
		using boost::bad_lexical_cast;
		try {
			return lexical_cast<std::string>(value);
		} catch (bad_lexical_cast &) {
			return "error";
		}
	} //getDrawString

	std::string getEditString() const{
		using boost::lexical_cast;
		using boost::bad_lexical_cast;
		try {
			return lexical_cast<std::string>(value);
		} catch (bad_lexical_cast &) {
			return "error";
		}
	} //getEditString

	float getFloat() const{
		using boost::lexical_cast;
		using boost::bad_lexical_cast;
		try {
			return lexical_cast<float>(value);
		} catch (bad_lexical_cast &) {
			return 0;
		}
	} //getFloat

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
