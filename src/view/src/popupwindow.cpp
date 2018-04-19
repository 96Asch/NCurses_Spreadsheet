#include "popupwindow.h"
#include "sheet.h"
#include "column.h"
#include "util.h"
#include <string>

#define LINES 24
#define COLS 80
#define CELLSIZE 8


void popupwindow::callwindow() {
	int row = cursorLocation.getRow();
	int column = cursorLocation.getColumn();
	initscr();
	noecho();
	popupwin = newwin(3, CELLSIZE, 0, 0);
	keypad(popupwin, TRUE);
	wborder(popupwin, '|', '|', '-', '-', '+', '+', '+', '+');
}

void popupwindow::exit() {
	delwin(popupwin); /* Dealloceer venster */
	endwin(); /* Curses stoppen */
}

int popupwindow::getInput() {
	return wgetch(popupwin);
}
