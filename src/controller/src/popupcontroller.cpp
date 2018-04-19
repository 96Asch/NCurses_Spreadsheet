#include "popupcontroller.h"
#include "cellValueBase.h"



PopupController::PopupController(PopupWindow window): window(window){
	
	row = window.getRow();
	column = window.getColumn();
	editString = Sheet::getInstance().getCell(row,column).getDrawString();

}

void PopupController::windowLoop() {
	
	int command;	
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
	
		case '\n' :
			writeString();
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
	editString.pop_back();
}

void PopupController::addToString(char input){
	editString += input ;
}

void PopupController::writeString(){
	Sheet::getInstance().getCell(row,column).set(CellValueBase::cellValueFactory(editString));
}




