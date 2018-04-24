#include "popupwindow.h"
#include "sheet.h"
#include "column.h"
#include "util.h"
#include <string>

#define LINES 24
#define COLS 80
#define CELLSIZE 16

void PopupWindow::initialize(int windowSize) {
	
	initscr();
	noecho();
	popupwin = newwin(3, windowSize, row, column*8 + 4);
	keypad(popupwin, TRUE);
	

}


void PopupWindow::drawString(std::string inputString){	
	werase(popupwin);
	drawWindow();	
	wmove(popupwin,1,1);	
	wprintw(popupwin,inputString.c_str());
	wrefresh(popupwin);
	doupdate();
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
