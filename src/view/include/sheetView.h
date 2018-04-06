
#ifndef INCLUDE_SHEETVIEW_H_
#define INCLUDE_SHEETVIEW_H_

#include <curses.h>

class SheetView {

private:
	WINDOW *win;

	void initHeader();

public:
	SheetView();
	~SheetView();

	WINDOW* getWin();
	int getInput();
	void debug(const char* string);
	void initialize();
	void draw();
	void exit();

};

#endif
