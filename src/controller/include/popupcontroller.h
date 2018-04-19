
#ifndef POPUPCONTROLLER_H_
#define POPUPCONTROLLER_H_

#include "sheet.h"
#include "popupwindow.h"

class PopupController {

public:
	void windowLoop();
	PopupController(PopupWindow window);
	

private:
	PopupWindow window;
	void handlePopup(int command);
	void writeString();
	void backspace();
	void addToString(char input);
	int row;
	int column;
	std::string editString;
	

};

#endif
