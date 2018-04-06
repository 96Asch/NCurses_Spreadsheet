/*
 * sheetController.cpp
 *
 *  Created on: Apr 5, 2018
 *      Author: asch
 */

#include "sheetController.h"


SheetController::SheetController(SheetView view) :
		view(view), finished(false) {
}

SheetController::~SheetController() {
}

void SheetController::run() {
	view.initialize();
	loop();
	view.exit();
}

void SheetController::handleCommand(const int & command) {
	switch(command) {
	case 'q':
		finished = true;
		break;
	default:
		break;
	}
}

void SheetController::loop() {
	do {
		view.draw();
		view.debug("This is text");
		command = view.getInput();
		handleCommand(command);
	} while(!finished);
}

