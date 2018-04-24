
#ifndef POPUPCONTROLLER_H_
#define POPUPCONTROLLER_H_

#include "sheet.h"
#include "popupwindow.h"

class PopupController {

public:
	void windowLoop();
	void windowSizeLoop();
	PopupController(PopupWindow window);
	

private:
	PopupWindow window;
	void handlePopup(int command);
	void writeString();
	void backspace();
	void addToString(char input);
	
	void loopSizeInput(const std::string & msg, int & getal);
	void inputSizeWindow();
	std::string editString;
	

};

#endif
