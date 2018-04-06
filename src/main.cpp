#include "sheetController.h"


int main(void) {
	SheetView* view = new SheetView;
	SheetController controller(view);
	controller.run();
	delete view;
	return 0;
}
