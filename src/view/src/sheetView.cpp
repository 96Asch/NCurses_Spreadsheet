#include "sheetView.h"
#include "sheet.h"
#include "column.h"
#include "cellValue.h"
#include "util.h"
#include <string>

#define CELLSIZE 8

SheetView::SheetView(): rows(23), cols(79), cursorLocation("A1") {
	Sheet::getInstance().getCell(4,5).set(new CellValue<std::string>("lange string"));
}

SheetView::~SheetView() {

}

void SheetView::initialize() {

	/* Initialiseren */
	initscr();
	noecho();
	/* Maak een venster, grootte lines x cols */
	win = newwin((rows + 5), (cols + 5) * CELLSIZE, 0, 0);
	keypad(win, TRUE); /* Enable keypad input */
	curs_set(0);

}
void SheetView::drawHighlight(const char* string) {
	attr_t old_attr; /* Huidige settings onthouden */
	short old_pair;
	wattr_get(win, &old_attr, &old_pair, NULL);
	wattron(win, A_STANDOUT);
	waddstr(win, string);
	wattr_set(win, old_attr, old_pair, NULL); /* Oude settings terugzetten */
}

void SheetView::drawHeader() {
	std::string temp, temp2;
	for (int i = 0; i <= cols; i++) {
		wmove(win, 0, i * 8 + 8);
		temp = "   ";
		temp += numberToAlpha(i);
		temp += "    ";
		if (i > 26)
			temp.pop_back();
		drawHighlight(temp.c_str());
	}

	for (int i = 1; i <= rows; i++) {
		wmove(win, i, 0);
		temp = "   ";
		temp += std::to_string(i);
		temp += "    ";
		if (i > 9)
			temp.pop_back();
		drawHighlight(temp.c_str());
	}
}

int SheetView::getInput() {
	return wgetch(win);
}

char SheetView::headerLetter(int asciiVal) {
	char asciiChar = asciiVal + 65;
	return asciiChar;
}

void SheetView::drawCells() {
	std::string drawstring;
	int row = 0, column = 0;
	for (Sheet::iterator sit = Sheet::getInstance().begin(); sit != Sheet::getInstance().end(); ++sit){
			for(Column::iterator cit = sit->begin() ; cit != sit->end(); ++cit){
				drawstring = formatter(cit->getDrawString());
				wmove(win, row + 1, (column+1) * CELLSIZE);
				waddstr(win, drawstring.c_str());
				row++;
			}
	row = 0;
	column++;
	}
}



void SheetView::draw() {
	drawHeader();
	drawCells();
	drawCursor();
}

void SheetView::drawCursor(){
	int row = cursorLocation.getRow();
	int column = cursorLocation.getColumn();
	std::string string = Sheet::getInstance().getCell(row,column).getDrawString();
	wmove(win, row+1, (column+1)*CELLSIZE);
	drawHighlight(formatter(string).c_str());
}

void SheetView::setCursor(const CellAddress newLocation) {
	cursorLocation = newLocation;
}

CellAddress SheetView::getCursor() {
	return cursorLocation;
}

void SheetView::exit() {
	delwin(win); /* Dealloceer venster */
	endwin(); /* Curses stoppen */
}

//retutn string van 8 tekens
std::string SheetView::formatter(std::string cellstring){
	std::string temp;
	if(cellstring.length() < 8) {
		for(size_t i = 0; i < 8-cellstring.length(); i++)
			temp += " ";
		cellstring = temp + cellstring;
	}
	return cellstring.substr(0,8);
}

std::string SheetView::numberToAlpha(const int & num) {
	std::string alpha;
	int temp = num / 26;
	int rest = num % 26;

	if (temp > 0) {
		alpha.push_back((64 + temp));
	}
	alpha.push_back((65 + rest));
	return alpha;
}
