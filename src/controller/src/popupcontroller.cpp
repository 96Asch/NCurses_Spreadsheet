#include "popupcontroller.h"
#include "cellValueBase.h"



PopupController::PopupController(PopupWindow window): window(window){
	
	row = window.getRow();
	column = window.getColumn();
	
	editString = Sheet::getInstance().getCell(row,column).getEditString();

}

void PopupController::windowLoop() {
	
	window.initialize();
		
	
	do{
		window.drawWindow();
		command = window.getInput();
		handlePopup(command);
		
		
		
	} while(command != '\n');
	window.exit();
}

void PopupController::handlePopup(int command){

	switch(command){
	
		case '\n' :
			writeString();
			break;
	
	}
}


void PopupController::writeString(){
	
	Sheet::getInstance().getCell(row,column).getValue.cellValueFactory(editString)


}




