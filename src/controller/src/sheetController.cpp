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
		case 'q':
			finished = true;
			break;
		case KEY_DOWN:
			moveDown();
			break;
		case KEY_UP:
			moveUp();
			break;
		case KEY_RIGHT:
			moveRight();
			break;
		case KEY_LEFT:
			moveLeft();
			break;
		case KEY_BACKSPACE:
			backspace();
			break;
		default:
			break;
	} 
	
	
}


void SheetController::backspace(){
	int row = view.getCursor().getRow();
	int column = view.getCursor().getColumn();
	Sheet::getInstance().getCell(row,column).set(new CellValue<std::string>("        "));

}

void SheetController::moveDown(){
	view.setCursor(view.getCursor().moveRow(1));
}
void SheetController::moveUp(){
	if(view.getCursor().getRow() != 0)
	{
	view.setCursor(view.getCursor().moveRow(-1));
	}
}
void SheetController::moveLeft(){
	view.setCursor(view.getCursor().moveColumn(-1));
}
void SheetController::moveRight(){
	view.setCursor(view.getCursor().moveColumn(1));
}

void SheetController::loop() {
	do {
		view.draw();
		command = view.getInput();
		handleCommand(command);
	} while(!finished);
}

