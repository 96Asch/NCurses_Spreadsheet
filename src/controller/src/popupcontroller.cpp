#include "popupcontroller.h"

void popupcontroller::windowloop() {
	popupwindow popup;
	do{
		popup.callwindow();
		command = popup.getInput();
	} while(command != '\n');
	popup.exit();
}
