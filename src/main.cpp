#include "sheetController.h"


int main(void) {
	SheetView view;
	SheetController controller(view);
	controller.run();
	return 0;
}
