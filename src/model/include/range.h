#ifndef INCLUDE_RANGE_H_
#define INCLUDE_RANGE_H_

#include <string>
#include "cellAddress.h"
#include "cell.h"
#include "sheet.h"
#include <iterator>

class RangeIterator;

class Range {
public:
	Range();
	~Range() = default;

  RangeIterator begin();
  RangeIterator end();
  
private:
  bool checkRange(std::string address, int & split);
  Range* createRange(CellAddress begin, CellAddress end, Sheet* sheet);
  Range* rangeFromString(std::string rangeString, Sheet* sheet);
 

 
  CellAddress beginAddress;
  CellAddress endAddress;
  Sheet* sheet;
};

class RangeIterator : public std::iterator<std::input_iterator_tag, Cell>
{
  private:
    Sheet* sheet;
    int offsetX;
    int offsetY;
    CellAddress begin;
    CellAddress end;
    
  public:
      RangeIterator(Sheet* sheet, const CellAddress & beginAdd, const CellAddress & endAdd) : sheet(sheet), begin(beginAdd), end(endAdd){ 

      offsetX = beginAdd.getColumn();
      offsetY = beginAdd.getRow();
    }
    
  /* Zijn de iteratoren gelijk aan elkaar? */
  bool operator==(const RangeIterator &iter) const {
    return (&iter.sheet == &sheet && iter.offsetY == offsetY && iter.offsetX == offsetX &&
    begin.getRow() == iter.begin.getRow() && begin.getColumn() == iter.begin.getColumn() 
    && end.getRow() == iter.end.getRow() && end.getColumn() == iter.end.getColumn());
  }
  
  bool operator!=(const RangeIterator &iter) const {
    return !operator==(iter);
  }
  
  /* Element op de huidige plek van de iterator uitlezen */
  Cell &operator*() const {
    return sheet->getCell(offsetY, offsetX);
  }
  
  Cell *operator->() const {
    return &sheet->getCell(offsetY, offsetX);
  }
  
  /* Implementeer "++iter": verplaats de iterator een plek */
  RangeIterator &operator++() {
    if (offsetX < end.getColumn()) {  
      offsetY++;
      if (offsetY > end.getRow()){
        offsetX++;
        offsetY = begin.getRow();
      }
    }
    return *this;
  }
};
#endif 
