/*
 * sheetController.cpp
 *
 *  Created on: Apr 5, 2018
 *      Author: asch
 */

#include "sheetController.h"
#include "cellValue.h"

#define EDIT_POS_X 1
#define EDIT_POS_Y 0


SheetController::SheetController(SheetView view) :
		view(view), finished(false) {
}

SheetController::~SheetController() {
}

void SheetController::run() {
	view.initialize(Sheet::getInstance().getRows(), Sheet::getInstance().getCols());
	loop();
	view.exit();
}



void SheetController::handleCommand(const int & command) {
	
	switch(command) {
		case '\n':
			pressEnter();
			break;
		case 'q':
			finished = true;
			break;
		case 'r':
			editSize();
			break;
		case KEY_DOWN:
			moveCursorDown();
			break;
		case KEY_UP:
			moveCursorUp();
			break;
		case KEY_RIGHT:
			moveCursorRight();
			break;
		case KEY_LEFT:
			moveCursorLeft();
			break;
		case KEY_BACKSPACE:
			deleteCell();
			break;
		case KEY_DC:
			deleteCell();
			break;
		break;
		default:
			break;
	} 
}



void SheetController::editSize(){
	PopupWindow sizePopup;
	PopupController size(sizePopup, 0, 0);
	size.windowSizeLoop();
	view.clear();
	view.exit();
	view.initialize(Sheet::getInstance().getRows(),Sheet::getInstance().getCols());

}

void SheetController::deleteCell(){
	int row = view.getCursor().getRow();
	int column = view.getCursor().getColumn();
	Sheet::getInstance().getCell(row,column).set(nullptr);
	
}

void SheetController::pressEnter() {
	int row = view.getCursor().getRow();
	int column = view.getCursor().getColumn();
	PopupWindow window;
	PopupController popup(window, row, column);
	popup.windowLoop();
}

void SheetController::moveCursorDown(){
	view.setCursor(view.getCursor().moveRow(1));
}
void SheetController::moveCursorUp(){
	view.setCursor(view.getCursor().moveRow(-1));
}
void SheetController::moveCursorLeft(){
	view.setCursor(view.getCursor().moveColumn(-1));
}
void SheetController::moveCursorRight(){
	view.setCursor(view.getCursor().moveColumn(1));
}

void SheetController::loop() {
	do {
		view.clear();
		view.draw();
		command = view.getInput();
		handleCommand(command);
	} while(!finished);
}

