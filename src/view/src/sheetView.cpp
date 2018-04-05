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

//void SheetView::initHeader() {
//	std::string str;
//	attr_t old_attr;
//	short old_pair;
//	int size = CellSize;
//
//	wattr_get(win, &old_attr, &old_pair, NULL);
//	wattron(win, A_STANDOUT);
//
//	for (int i = 0; i < COLS * 8; i++) {
//		wmove(win, 0, 8 + i);
//		if (i != 0 && i % 8 == 8 / 2) {
//			str = headerLetter(i / 8);
//			waddstr(win, str.c_str());
//		} else {
//			waddstr(win, " ");
//		}
//	}
//
//	for (int i = 0; i < MAXrow; i++) {
//		wmove(win, i + 1, 0);
//		if (i == 9)
//			size--;
//		for (int j = 0; j < size; j++) {
//			if (j == 8 / 2) {
//				wprintw(win, "%d", i + 1);
//			} else {
//				waddch(win, ' ');
//			}
//		}
//	}
//	wattr_set(win, old_attr, old_pair, NULL);
//}

void SheetView::draw() {

	/* Verplaats cursor rij 10, kolom 20 */
	wmove(win, 100, 200);
	/* Plaats een string */
	waddstr(win, "HELLO WORLD!!");
	/* Nogmaals, maar nu op een achtergrond */
	attr_t old_attr; /* Huidige settings onthouden */
	short old_pair;
	wattr_get(win, &old_attr, &old_pair, NULL);
	wattron(win, A_STANDOUT);
	wmove(win, 12, 20);
	waddstr(win, "HELLO WORLD!!!");
	wattr_set(win, old_attr, old_pair, NULL); /* Oude settings terugzetten */
	wrefresh(win);

	int ch;
	while ((ch = wgetch(win)) != '\n')
		;

}

void SheetView::exit() {
	delwin(win); /* Dealloceer venster */
	endwin(); /* Curses stoppen */
}
