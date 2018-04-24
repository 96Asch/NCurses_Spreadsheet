/*
  Programmeertechnieken opdracht 2
  Andrew Huang        s1913999
  Paul Peters         s1453440
  Ruben van Erkelens  s1437267
  Karl Freeke         s1551973
*/

#include "popupcontroller.h"
#include "cellValueBase.h"

#define CELLSIZE 16

PopupController::PopupController(PopupWindow window): window(window){
	
	row = window.getRow();
	column = window.getColumn();
	
}

void PopupController::inputSizeWindow(){
	int command, getal = 0;
	editString = "Number of Rows: ";
	window.drawString(editString);
	do{
		command = window.getInput();
		if(command >= 0 && command <=9){
			addToString(command);
			window.drawString(editString);
			getal = getal*10 + command;
		}
	} while(command != '\n');
	
	if(getal != 0)
		row = getal;
	getal = 0;
	editString = "Number of columns: ";
	window.drawString(editString);
	do {
		command = window.getInput();
		if(command >= 0 && command <= 9){
			addToString(command);
			window.drawString(editString);
			getal = getal*10 + command;
		}
	} while (command != '\n');
	if(getal != 0)
		column = getal;
		
}





 void PopupController::windowSizeLoop(){
 	int command;
 	window.initialize(CELLSIZE*2);
 	window.drawWindow();
 	window.drawString("Edit size? (y/n)");
 	do{
 		command = window.getInput();
 		if(command == 'y')
			inputSizeWindow();
 	} while(command != 'n');
 }

void PopupController::windowLoop() {
	
	int command;
	editString = Sheet::getInstance().getCell(row,column).getEditString();
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
	if(!editString.empty())
		editString.pop_back();
}

void PopupController::addToString(char input){
	editString += input ;
}

void PopupController::writeString(){
	Sheet::getInstance().getCell(row,column).set(CellValueBase::cellValueFactory(editString));
}




