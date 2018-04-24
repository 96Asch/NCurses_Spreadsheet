/*
  Programmeertechnieken opdracht 2
  Andrew Huang        s1913999
  Paul Peters         s1453440
  Ruben van Erkelens  s1437267
  Karl Freeke         s1551973
*/

#include "popupwindow.h"
#include "sheet.h"
#include "column.h"
#include "util.h"
#include <string>

#define POS_X 0
#define POS_Y 0
#define CELLSIZE 8
#define MAX_WIDTH 64
#define MAX_HEIGHT 3
#define UPPER_MARGIN 3


PopupWindow::PopupWindow() {
}

void PopupWindow::initialize() {
	initscr();
	noecho();
	popupwin = newwin(MAX_HEIGHT, MAX_WIDTH, POS_Y, POS_X*CELLSIZE);
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

void PopupWindow::exit() {
	delwin(popupwin); /* Dealloceer venster */
	endwin(); /* Curses stoppen */
}

int PopupWindow::getInput() {
	return wgetch(popupwin);
}
