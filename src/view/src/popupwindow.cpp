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

#define CELLSIZE 8
#define UPPER_MARGIN 3


PopupWindow::PopupWindow(const int & height, const int & width, const int & posX, const int & posY)
: height(height), width(width), posX(posX), posY(posY){
}

void PopupWindow::initialize() {
	initscr();
	noecho();
	popupwin = newwin(height, width, posY, posX*CELLSIZE);
	keypad(popupwin, TRUE);
	curs_set(1);
}

void PopupWindow::drawString(const std::string & inputString){
	werase(popupwin);
	drawWindow();	
	wmove(popupwin,1,1);	
	wprintw(popupwin,inputString.c_str());
	wrefresh(popupwin);
	doupdate();
}

size_t PopupWindow::getHeight() const {
	return height;
}

size_t PopupWindow::getWidth() const {
	return width;
}

void PopupWindow::drawWindow(){

	wborder(popupwin, '|', '|', '-', '-', '+', '+', '+', '+');

}

void PopupWindow::exit() {
	curs_set(0);
	delwin(popupwin);
	endwin(); 
}

int PopupWindow::getInput() {
	return wgetch(popupwin);
}
