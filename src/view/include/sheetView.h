
#ifndef INCLUDE_SHEETVIEW_H_
#define INCLUDE_SHEETVIEW_H_

#include <curses.h>
#include "cellAddress.h"

class SheetView {

private:
	WINDOW *win;
	void initHeader();
	CellAddress cursorLocation;
	char headerLetter(int asciiVal);
	void initCells();
	

public:

	SheetView();
	~SheetView();

	int getInput();
	void debug(const char* string);
	void initialize();

	void draw();
	void exit();
	CellAddress getCursor();
	void setCursor();
	char getChar(int x, int y);


};

#endif
