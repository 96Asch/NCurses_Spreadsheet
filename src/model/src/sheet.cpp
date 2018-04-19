#include "sheet.h"
#include <iostream>

#define DEFAULT_ROWS 24
#define DEFAULT_COLS 80

Sheet::Sheet() :
		rows(DEFAULT_ROWS), cols(DEFAULT_COLS),sheet(DEFAULT_COLS) {

}

Sheet& Sheet::getInstance() {
	static Sheet instance;
	return instance;
}

std::vector<Column>::iterator Sheet::begin(){
	return sheet.begin();
}

std::vector<Column>::iterator Sheet::end(){
	return sheet.end();
}

//TODO return value in case out of bounds.
Cell & Sheet::getCell(const int & row, const int & column) {
	if(row < rows && column < cols)
		return sheet[column].getCell(row);
	return sheet[0].getCell(0);
}

void Sheet::notify(const Cell & cell) {
	for(Observer* obs : observers) {
		if(obs)
			obs->update(cell);
	}
}

void Sheet::ensureSize(const int & row, const int & col) {
	rows = row;
	cols = col;
	sheet.resize(cols);
	for(size_t i = 0; i < sheet.size(); i++)
		sheet[i].resize(rows);
}
