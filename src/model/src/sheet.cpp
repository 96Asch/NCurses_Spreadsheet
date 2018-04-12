#include "sheet.h"
#include <iostream>

Sheet::Sheet() :
		sheet(80) {
}

Sheet& Sheet::getInstance() {
	static Sheet instance;
	return instance;
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

int Sheet::getSize() {
	return sheet.size();
}

void Sheet::notify(int row, int col) {
	for(Observer* obs : observers) {
		if(obs)
			obs->update(row, col);
	}
}

void Sheet::ensureSize(const int & rows, const int & cols) {
	sheet.resize(cols);
	for(size_t i = 0; i < sheet.size(); i++)
		sheet[i].resize(rows);
}
