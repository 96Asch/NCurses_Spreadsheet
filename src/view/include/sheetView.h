/*
  Programmeertechnieken opdracht 2
  Andrew Huang        s1913999
  Paul Peters         s1453440
  Ruben van Erkelens  s1437267
  Karl Freeke         s1551973
*/

#ifndef INCLUDE_SHEETVIEW_H_
#define INCLUDE_SHEETVIEW_H_

#include <curses.h>
#include "cellAddress.h"

class SheetView {

private:
	WINDOW *win;
	CellAddress cursorLocation;

	void initHeader();

	char headerLetter(int asciiVal);
	void drawHighlight(const char* string);
	void drawHeader();
	void drawCells();
	void drawCursor();
	std::string numberToAlpha(const int & num);
	std::string formatter(std::string cellstring);

public:

	SheetView();
	~SheetView();

	int getInput();
	void initialize(const int & numRows, const int & numCols);
	void exit();
	void clear();
	void draw();

	CellAddress getCursor();
	void setCursor(const CellAddress newLocation);


};

#endif
