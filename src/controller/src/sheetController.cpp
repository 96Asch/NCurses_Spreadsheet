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
	case KEY_DOWN:
		moveDown();
	case KEY_UP:
		moveCursor();
	case KEY_RIGHT:
		moveCursor();
	case KEY
	default:
		break;
	}
}

void SheetController::moveDown(){
	view.getCursor.moveRow(-1);
}
void SheetController::moveUp(){
	view.getCursor.moveRow(1);
}
void SheetController::moveLeft(){
	view.getCursor.moveColumn(-1);
}
void SheetController::moveRigth(){
	view.getCursor.moveColumn(1);
}
void SheetController::loop() {
	do {
		view.draw();
		command = view.getInput();
		handleCommand(command);
	} while(!finished);
}

