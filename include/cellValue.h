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
class CellValue final : public CellValueBase
{
  private:
    T value;
  public:
    CellValue(T initial_value)
    : CellValueBase(), value(initial_value){ 
    
    
    }
    ~CellValue() = default;
    T getValue(){
      return value;
    }
    
    std::string getDrawString(){
      using boost::lexical_cast;
      try {
        return lexical_cast<std::string>(value);
      } catch (...) {
        return "error";
      }
    }//getDrawString

    std::string getEditString(){
       using boost::lexical_cast;
      try {
        return lexical_cast<std::string>(value);
      } catch (...) {
        return "error";
      }
    }//getEditString

    float  getFloat(){
      using boost::lexical_cast;
      try {
        return lexical_cast<float>(value);
      } catch (...) {
        return 0;
      }
    }//getFloat

    int  getInt(){
      using boost::lexical_cast;
      try {
        return lexical_cast<int>(value);
      } catch (...) {
        return 0;
      }
    }//getFloat
};//CellValue   


#endif /* INCLUDE_CELLVALUE_H_ */
