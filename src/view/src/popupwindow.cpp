#include "popupwindow.h"
#include "sheet.h"
#include "column.h"
#include "util.h"
#include <string>

#define LINES 24
#define COLS 80
#define CELLSIZE 16

void PopupWindow::initialize() {
	
	initscr();
	noecho();
	popupwin = newwin(3, CELLSIZE, row, column*8 + 4);
	keypad(popupwin, TRUE);

}


void PopupWindow::insertChar(){

	//waddch(popupwin, );

}


void PopupWindow::drawWindow(){

wborder(popupwin, '|', '|', '-', '-', '+', '+', '+', '+');

}

int PopupWindow::getRow(){
	return row;

}

int PopupWindow::getColumn(){
	return column;
}


PopupWindow::PopupWindow(int row, int column): column(column), row(row) {


}


void PopupWindow::exit() {
	delwin(popupwin); /* Dealloceer venster */
	endwin(); /* Curses stoppen */
}

int PopupWindow::getInput() {
	return wgetch(popupwin);
}
