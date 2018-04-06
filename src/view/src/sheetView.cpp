#include "sheetView.h"

#define LINES 24
#define COLS 80

SheetView::SheetView() {
}

SheetView::~SheetView() {

}

void SheetView::initialize() {

	/* Initialiseren */
	initscr();
	noecho();
	/* Maak een venster, grootte lines x cols */
	win = newwin(LINES, COLS, 0, 0);
	keypad(win, TRUE); /* Enable keypad input */

}

WINDOW* SheetView::getWin() {
	return win;
}

void SheetView::draw() {

	/* Verplaats cursor rij 10, kolom 20 */
//	wmove(win, 0, 0);
//	/* Plaats een string */
//	waddstr(win, "HELLO!!");
	/* Nogmaals, maar nu op een achtergrond */
	attr_t old_attr; /* Huidige settings onthouden */
	short old_pair;
	wattr_get(win, &old_attr, &old_pair, NULL);
	wattron(win, A_STANDOUT);
	wmove(win, 10, 10);
	waddstr(win, "HELLO WORLD!!!");
	wattr_set(win, old_attr, old_pair, NULL); /* Oude settings terugzetten */
}

void SheetView::debug(const char* string) {
	wmove(win, 0, 0);
	waddstr(win, string);
}

void SheetView::exit() {
	delwin(win); /* Dealloceer venster */
	endwin(); /* Curses stoppen */
}
