/*
 * sheetController.h
 *
 *  Created on: Apr 5, 2018
 *      Author: asch
 */

#ifndef SRC_CONTROLLER_INCLUDE_SHEETCONTROLLER_H_
#define SRC_CONTROLLER_INCLUDE_SHEETCONTROLLER_H_

#include "sheetView.h"
#include "sheet.h"

class SheetController {
public:
	SheetController(SheetView view);
	virtual ~SheetController();

	void run();

private:
	SheetView view;
	bool finished;
	int command;
	void moveCursorUp();
	void moveCursorDown();
	void moveCursorLeft();
	void moveCursorRight();
	void handleCommand(const int & command);
	void loop();
	void backspace();

};

#endif /* SRC_CONTROLLER_INCLUDE_SHEETCONTROLLER_H_ */
