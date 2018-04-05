#include "sheetView.h"


int main(void) {

	SheetView sheet;
	sheet.initialize();
	sheet.draw();
	getch();
	return 0;
}
