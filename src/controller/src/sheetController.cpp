/*
 * sheetController.cpp
 *
 *  Created on: Apr 5, 2018
 *      Author: asch
 */

#include "sheetController.h"
#include <curses.h>


SheetController::SheetController(SheetView* view) :
		view(view), finished(false) {

}

SheetController::~SheetController() {
}

void SheetController::run() {
	view->initialize();
	loop();
	view->exit();
}

void SheetController::loop() {
	do {
		view->draw();
		view->debug("This is text");
		command = wgetch(view->getWin());
		if(command == 'q')
			finished = true;

	} while(!finished);
}

