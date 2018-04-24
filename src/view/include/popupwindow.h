/*
  Programmeertechnieken opdracht 2
  Andrew Huang        s1913999
  Paul Peters         s1453440
  Ruben van Erkelens  s1437267
  Karl Freeke         s1551973
*/

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
