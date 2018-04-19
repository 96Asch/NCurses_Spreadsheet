/*
 * sheetController.cpp
 *
 *  Created on: Apr 5, 2018
 *      Author: asch
 */

#include "sheetController.h"
#include "cellValue.h"


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
		case '\n':
			pressEnter();
			break;
		case 'q':
			finished = true;
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
		default:
			break;
	} 
	
	
}


void SheetController::insertChar(const char c){
	int row = view.getCursor().getRow();
	int column = view.getCursor().getColumn();
	
	std::string input = Sheet::getInstance().getCell(row,column).getEditString();
	
	input = input + c; 
	
	Sheet::getInstance().getCell(row,column).set(new CellValue<std::string>(input));

}

void SheetController::deleteCell(){
	int row = view.getCursor().getRow();
	int column = view.getCursor().getColumn();

	Sheet::getInstance().getCell(row,column).set(nullptr);
	
}

void SheetController::pressEnter() {
	int row = view.getCursor().getRow();
	int column = view.getCursor().getColumn();
	PopupWindow window(row,column);
	PopupController popup(window);
	popup.windowLoop();
}

void SheetController::moveCursorDown(){
	view.setCursor(view.getCursor().moveRow(1));
}
void SheetController::moveCursorUp(){
	if(view.getCursor().getRow() != 0)
		view.setCursor(view.getCursor().moveRow(-1));
}
void SheetController::moveCursorLeft(){
	if(view.getCursor().getColumn() != 0)	
		view.setCursor(view.getCursor().moveColumn(-1));
}
void SheetController::moveCursorRight(){
	view.setCursor(view.getCursor().moveColumn(1));
}

void SheetController::loop() {
	do {
		view.draw();
		command = view.getInput();
		handleCommand(command);
	} while(!finished);
}

