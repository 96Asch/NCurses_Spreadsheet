
#ifndef INCLUDE_SHEETVIEW_H_
#define INCLUDE_SHEETVIEW_H_

#include <curses.h>
#include "cellAddress.h"

class SheetView {

private:
	int rows, cols;

	WINDOW *win;
	CellAddress cursorLocation;

	void initHeader();

	char headerLetter(int asciiVal);
	void drawHighlight(const char* string);
	void drawHeader();
	void drawCells();
	std::string numberToAlpha(const int & num);
	std::string formater(std::string cellstring);

public:

	SheetView();
	~SheetView();

	int getInput();
	void initialize();
	void exit();

	void draw();

	CellAddress getCursor();
	void setCursor();


};

#endif
