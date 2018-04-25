/*
  Programmeertechnieken opdracht 2
  Andrew Huang        s1913999
  Paul Peters         s1453440
  Ruben van Erkelens  s1437267
  Karl Freeke         s1551973
*/

#include "column.h"
#include "cell.h"

#define DEFAULT_ROWS 24

Column::Column() :
		column(DEFAULT_ROWS) {
}

Column::Column(const int & rows) {
	for(int i = 0; i < rows; i++)
		column.push_back(Cell());
}

Cell& Column::getCell(const size_t & index) {
	if(index > column.size())
		return column.front();
	return column[index];
}

void Column::resize(const int & rows) {
	column.resize(rows);
}

std::vector<Cell>::iterator Column::begin() {
	return column.begin();
}

std::vector<Cell>::iterator Column::end() {
	return column.end();
}

