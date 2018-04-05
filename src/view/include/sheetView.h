
#ifndef INCLUDE_SHEETVIEW_H_
#define INCLUDE_SHEETVIEW_H_

#include <curses.h>
#include "../../model/include/cellAddress.h"
#include "../../model/include/sheet.h"

class SheetView {

private:
	WINDOW *win;

	void initHeader();
	CellAddress cursorLocatie;
	void initialize();

public:
	SheetView();
	~SheetView();

	
	void draw();
	void exit();
	CellAddress getCursor();
	Sheet sheet;

};

#endif
