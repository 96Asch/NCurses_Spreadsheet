
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
