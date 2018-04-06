/*
 * sheetController.h
 *
 *  Created on: Apr 5, 2018
 *      Author: asch
 */

#ifndef SRC_CONTROLLER_INCLUDE_SHEETCONTROLLER_H_
#define SRC_CONTROLLER_INCLUDE_SHEETCONTROLLER_H_

#include "sheetView.h"

class SheetController {
public:
	SheetController(SheetView* view);
	virtual ~SheetController();

	void run();

private:
	SheetView* view;
	bool finished;
	char command;

	void handleCommand(const char & command);
	void loop();

};

#endif /* SRC_CONTROLLER_INCLUDE_SHEETCONTROLLER_H_ */
