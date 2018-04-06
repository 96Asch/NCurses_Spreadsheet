#include "sheetView.h"
#include "sheet.h"
#include "column.h"

#include "util.h"
#include <string>

#define LINES 24
#define COLS 80
#define CELLSIZE 8

SheetView::SheetView() {

}

SheetView::~SheetView() {

}

void SheetView::initialize() {

	/* Initialiseren */
	initscr();
	noecho();
	/* Maak een venster, grootte lines x cols */
	win = newwin((LINES + 5), (COLS + 5) * CELLSIZE, 0, 0);
	keypad(win, TRUE); /* Enable keypad input */

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
	for (int i = 0; i <= COLS; i++) {
		wmove(win, 0, i * 8 + 8);
		temp = "   ";
		temp += numberToAlpha(i);
		temp += "    ";
		if (i > 26)
			temp.pop_back();
		drawHighlight(temp.c_str());
	}

	for (int i = 1; i <= LINES; i++) {
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

	for (Sheet::iterator sit = Sheet::getInstance().begin(); sit != Sheet::getInstance().end(); ++sit){
			for(Column::iterator cit = sit->begin() ; cit != sit->end(); ++cit){

			}
	}
}

void SheetView::draw() {
	drawHeader();
	drawCells();
}

void SheetView::setCursor() {

}

CellAddress SheetView::getCursor() {

	return cursorLocation;

}

void SheetView::exit() {
	delwin(win); /* Dealloceer venster */
	endwin(); /* Curses stoppen */
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

