


#include "column.h"
#include "cell.h"


Column::Column(): column(24){}

Cell& Column::getCell(int index){
  return column[index];
}

std::vector<Cell>::iterator Column::begin() {
  return column.begin();
}

std::vector<Cell>::iterator Column::end(){
  return column.end(); 
}
  
  
