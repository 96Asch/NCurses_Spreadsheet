
#ifndef INCLUDE_POPUPWINDOW_H_
#define INCLUDE_POPUPWINDOW_H_

#include <curses.h>
#include "cellAddress.h"

class popupwindow {

private:

	WINDOW *popupwin;
	CellAddress cursorLocation;

public:

	void callwindow();
	void exit();
	int getInput();

};

#endif
