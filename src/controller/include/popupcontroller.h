/*
  Programmeertechnieken opdracht 2
  Andrew Huang        s1913999
  Paul Peters         s1453440
  Ruben van Erkelens  s1437267
  Karl Freeke         s1551973
*/

#ifndef POPUPCONTROLLER_H_
#define POPUPCONTROLLER_H_

#include "sheet.h"
#include "popupwindow.h"

class PopupController {

public:
	PopupController(PopupWindow window, const int & row, const int & col);
	void windowLoop();
	void windowSizeLoop();

private:
	PopupWindow window;
	void handlePopup(int command);
	void writeString();
	void backspace();
	void addToString(char input);
	
	void loopSizeInput(const std::string & msg, int & getal);
	void inputSizeWindow();
	std::string editString;
	int row, col;
	

};

#endif
