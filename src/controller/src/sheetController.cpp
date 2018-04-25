/*
 Programmeertechnieken opdracht 2
 Andrew Huang        s1913999
 Paul Peters         s1453440
 Ruben van Erkelens  s1437267
 Karl Freeke         s1551973
 */

#include "sheetController.h"
#include "cellValue.h"

#define EDIT_POS_X 1
#define EDIT_POS_Y 0
#define EDIT_WIDTH 64
#define EDIT_HEIGHT 3
#define TEXT_WINDOW_HEIGHT 10

SheetController::SheetController(SheetView view) :
		view(view), finished(false) {
}

SheetController::~SheetController() {
}

void SheetController::run() {
	view.initialize(Sheet::getInstance().getRows(),
			Sheet::getInstance().getCols());
	loop();
	view.exit();
}

void SheetController::moveCursorDown() {
	view.setCursor(view.getCursor().moveRow(1));
}
void SheetController::moveCursorUp() {
	view.setCursor(view.getCursor().moveRow(-1));
}
void SheetController::moveCursorLeft() {
	view.setCursor(view.getCursor().moveColumn(-1));
}
void SheetController::moveCursorRight() {
	view.setCursor(view.getCursor().moveColumn(1));
}

void SheetController::handleCommand(const int & command) {

	switch (command) {
	case '\n':
		pressEnter();
		break;
	case 'q':
		finished = true;
		break;
	case 'h':
		showFormulae();
		break;
	case 'r':
		editSize();
		break;
	case KEY_DOWN:
		moveCursorDown();
		break;
	case KEY_UP:
		moveCursorUp();
		break;
	case KEY_RIGHT:
		moveCursorRight();
		break;
	case KEY_LEFT:
		moveCursorLeft();
		break;
	case KEY_BACKSPACE:
		deleteCell();
		break;
	case KEY_DC:
		deleteCell();
		break;
		break;
	default:
		break;
	}
}

void SheetController::editSize() {
	view.removeHelp();
	PopupWindow sizePopup(EDIT_HEIGHT, EDIT_WIDTH, EDIT_POS_X, EDIT_POS_Y);
	PopupController control(sizePopup);
	control.resizeLoop();
	view.clear();
	view.exit();
	view.initialize(Sheet::getInstance().getRows(),
			Sheet::getInstance().getCols());

}

void SheetController::deleteCell() {
	int row = view.getCursor().getRow();
	int column = view.getCursor().getColumn();
	Sheet::getInstance().getCell(row, column).set(nullptr);
}

void SheetController::pressEnter() {
	int row = view.getCursor().getRow();
	int column = view.getCursor().getColumn();
	view.removeHelp();
	PopupWindow window(EDIT_HEIGHT, EDIT_WIDTH, EDIT_POS_X, EDIT_POS_Y);
	PopupController control(window, row, column);
	control.editLoop();
}

void SheetController::showFormulae() {
	std::string formulae =
			"Supported formulas:\n Summation: =SUM(ADDRESS:ADDRESS)\n Mean: =AVG(ADDRESS:ADDRESS)\n Count: =COUNT(ADDRESS:ADDRESS)\n Non-aggregate functions also allowed.";
	PopupWindow help(TEXT_WINDOW_HEIGHT, EDIT_WIDTH, EDIT_POS_X, EDIT_POS_Y + 4);
	PopupController control(help);
	control.showText(formulae);
}

void SheetController::loop() {
	do {
		view.clear();
		view.draw();
		command = view.getInput();
		handleCommand(command);
	} while (!finished);
}

