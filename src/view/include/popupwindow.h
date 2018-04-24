
#ifndef INCLUDE_POPUPWINDOW_H_
#define INCLUDE_POPUPWINDOW_H_

#include <curses.h>
#include "cellAddress.h"

class PopupWindow {

private:

	WINDOW *popupwin;
public:
	PopupWindow();
	void initialize();
	void drawWindow();
	void exit();
	int getInput();
	void drawString(std::string inputString);
};

#endif
