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
	PopupController(PopupWindow window);
	void editLoop();
	void resizeLoop();
	void showText(const std::string & text);

private:
	PopupWindow window;
	std::string editString;
	int row, col;

	void handlePopup(int command);
	void writeString();
	void backspace();
	void addToString(char input);
	std::string format(const std::string & str, const size_t & offset);
	void getInt(const std::string & msg, int & getal);
	void inputSizeWindow();
};

#endif
