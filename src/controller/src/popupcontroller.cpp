#include "popupcontroller.h"
#include "cellValueBase.h"

#define CELLSIZE 16

PopupController::PopupController(PopupWindow window, const int & row, const int & col)
: window(window), row(row), col(col){	
}

void PopupController::loopSizeInput(const std::string & msg, int & getal) {
	int command;
	editString = "";
	window.drawWindow();
	window.drawString(msg);
	do{
		command = window.getInput();
		if(isdigit(command) or command == KEY_BACKSPACE){
			handlePopup(command);
			window.drawWindow();
			window.drawString(msg+editString);
		}
	} while(command != '\n');
	if(not editString.empty())
		getal = stoi(editString);
}

void PopupController::inputSizeWindow(){
	int numRows(0),numColumns(0);
	loopSizeInput("Enter row size: ", numRows);
	loopSizeInput("Enter column size: ", numColumns);
	Sheet::getInstance().ensureSize(numRows,numColumns);
}

void PopupController::windowSizeLoop(){
 	int command;
 	window.initialize();
 	window.drawWindow();
 	window.drawString("Edit size? (y/n)");
	command = window.getInput();
	if(command == 'y')
		inputSizeWindow();
 	window.exit();
 }

void PopupController::windowLoop() {
	int command;
	editString = Sheet::getInstance().getCell(row,col).getEditString();
	window.initialize();
	window.drawWindow();
	window.drawString(editString);
	do{
		command = window.getInput();
		handlePopup(command);
		window.drawString(editString);
		
	} while(command != '\n');
	writeString();
	window.exit();
}

void PopupController::handlePopup(int command){
	switch(command){
		case '\n':
			break;
		case KEY_BACKSPACE:
			backspace();
			break;		
		default:
			addToString(command);
			break;
	}
}


void PopupController::backspace(){
	if(!editString.empty())
		editString.pop_back();
}

void PopupController::addToString(char input){
	editString += input ;
}

void PopupController::writeString(){
	if(!editString.empty())
		Sheet::getInstance().getCell(row,col).set(CellValueBase::cellValueFactory(editString));
}




