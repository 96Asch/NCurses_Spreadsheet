#include "column.h"
#include "cell.h"

Column::Column() :
		column(24) {
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

