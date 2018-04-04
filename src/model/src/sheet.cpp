#include "sheet.h"
#include <iostream>

Sheet::Sheet() :
		sheet(80) {
}

std::vector<Column>::iterator Sheet::begin() {
	return sheet.begin();
}

std::vector<Column>::iterator Sheet::end() {
	return sheet.end();
}

Cell & Sheet::getCell(int row, int column) {
	return sheet[column].getCell(row);
}

//TODO implement
void Sheet::ensureSize(const int & rows, const int & cols) {
	std::cout << rows << " " << cols << std::endl;
}
