#ifndef INCLUDE_RANGE_H_
#define INCLUDE_RANGE_H_

#include <string>
#include "cellAddress.h"
#include "sheet.h"

class Range {
public:
	Range(CellAdress addressBegin, CellAdress addressEnd);
	~Range() = default;

private:
  void createRange ();
  int beginRow;
  int beginColumn;
  int endRow;
  int endColumn;
};

#endif 
