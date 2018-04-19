
#ifndef INCLUDE_POPUPWINDOW_H_
#define INCLUDE_POPUPWINDOW_H_

#include <curses.h>
#include "cellAddress.h"

class PopupWindow {

private:

	WINDOW *popupwin;
	int column, row;
public:
	PopupWindow(int row, int column);
	void initialize();
	void drawWindow();
	void exit();
	int getInput();
	void insertChar();
	int getRow();
	int getColumn();

};

#endif
