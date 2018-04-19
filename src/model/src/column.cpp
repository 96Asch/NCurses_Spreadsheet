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

Cell& Column::getCell(const int & index) {
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

