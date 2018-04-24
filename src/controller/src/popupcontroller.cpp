#include "popupcontroller.h"
#include "cellValueBase.h"

#define CELLSIZE 16

PopupController::PopupController(PopupWindow window): window(window){	
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
	int row(0),column(0);
	loopSizeInput("Enter row size: ", row);
	loopSizeInput("Enter column size: ", column);
	Sheet::getInstance().ensureSize(row,column);
}

 void PopupController::windowSizeLoop(){
 	int command;
 	window.initialize(CELLSIZE*2);
 	window.drawWindow();
 	window.drawString("Edit size? (y/n)");
	command = window.getInput();
	if(command == 'y')
		inputSizeWindow();
 	window.exit();
 }

void PopupController::windowLoop() {
	
	int command;
	editString = Sheet::getInstance().getCell(window.getRow(),window.getColumn()).getEditString();
	window.initialize(CELLSIZE);
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
	Sheet::getInstance().getCell(window.getRow(),window.getColumn()).set(CellValueBase::cellValueFactory(editString));
}




