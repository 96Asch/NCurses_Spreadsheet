#include "range.h"
#include "util.h"

bool Range::checkRange (std::string address, int & split){\
  for (size_t i = 0; i < address.length(); i++ ){
    if (address[i] == ':') {
      split = i;
    if (isCellAddress(address.substr(0, i)) && (isCellAddress(address.substr(i+1)))) 
        return true;
      else
        return false;
    }
  }//for
  return false;
}//checkRange

Range* Range::createRange (CellAddress begin, CellAddress end, Sheet* sheet){
    beginAddress = begin;
    endAddress = end;
    this->sheet = sheet;
    return this;
}//createRange


Range* Range::rangeFromString(std::string rangeString, Sheet* sheet){
  int split = 0;
  if (checkRange(rangeString, split)) {
    this->sheet = sheet;
    beginAddress.createFromReference(rangeString.substr(0, split));
    endAddress.createFromReference(rangeString.substr(split + 1));
  }//if
  return this;
}//createRange


RangeIterator Range::begin(){
  return RangeIterator (this->sheet, beginAddress, endAddress);
}//begin

RangeIterator Range::end(){
  return RangeIterator (this->sheet, endAddress, endAddress);
}//end
