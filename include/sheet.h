/*
 * sheet.h
 *
 *  Created on: Mar 22, 2018
 *      Author: asch
 */
 
 #include "cell.h"
 #include "column.h"
 #include <vector>
 
 
class Sheet{
  public:
    Sheet();
    ~Sheet() = default;
    std::vector<Column>::iterator begin();
    std::vector<Column>::iterator end();
    Cell& getCell(int row,int column);
  
  
  private:
    std::vector<Column> sheet;
  
  
 
 
 };
