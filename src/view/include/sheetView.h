
#ifndef INCLUDE_SHEETVIEW_H_
#define INCLUDE_SHEETVIEW_H_

#include <curses.h>
#include "../../model/include/cellAddress.h"
#include "../../model/include/sheet.h"

class SheetView {

private:
	WINDOW *win;
	void initHeader();
	CellAddress cursorLocation;
	char headerLetter(int asciiVal);
	void initCells();
	

public:
	void initialize();
	SheetView();
	~SheetView();
	void draw();
	void exit();
	CellAddress getCursor();
	void setCursor();
	char getChar(int x, int y);


};

#endif
