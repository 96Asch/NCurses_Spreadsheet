/*
 * cellAddress.cpp
 *
 *  Created on: Mar 22, 2018
 *      Author: asch
 */
 
 #include "cell.h"
 #include <vector>
 
class Column {
 public:
  Column();
  ~Column() = default;
  Cell& getCell(int index);
  std::vector<Cell>::iterator begin();
  std::vector<Cell>::iterator end();
   
  
 private:
  std::vector<Cell> column;
  
};


