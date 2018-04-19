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
	case '\n':
		popup();
		break;
	default:
		break;
	}
}

void SheetController::loop() {
	do {
		view.draw();
		command = view.getInput();
		handleCommand(command);
	} while(!finished);
}

void SheetController::popup() {
	popupwindow popup;
	do{
		popup.callwindow();
		command = popup.getInput();
	} while(command != '\n');
	popup.exit();
}

