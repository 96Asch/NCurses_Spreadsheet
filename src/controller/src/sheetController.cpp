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

const static std::string FORMULAS =
		"Supported formulas:\n Summation: =SUM(ADDRESS:ADDRESS)\n Mean: =AVG(ADDRESS:ADDRESS)\n Count: =COUNT(ADDRESS:ADDRESS)\n Non-aggregate functions also allowed.";
const static std::string CREDITS =
		"This spreadsheet is an assignment for PRT.\n This program was developed by:\n \t\t Andrew Huang \t\t s1913999\n \t\t Paul Peters \t\t s1453440\n \t\t Ruben van Erkelens \t s1437267\n \t\t Karl Freeke \t\t s1551973.";

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
	case 'c':
		showCredits();
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
	case KEY_DC:
		deleteCell();
		break;
	default:
		break;
	}
}

void SheetController::editSize() {
	int width = 0;
	view.removeHelp();
	PopupWindow sizePopup(EDIT_HEIGHT, EDIT_WIDTH, EDIT_POS_X, EDIT_POS_Y);
	PopupController control(sizePopup);
	control.resizeLoop();
	view.clear();
	view.exit();
	width = Sheet::getInstance().getCols();
	if (width < 20)
	  width = 20;
	view.initialize(Sheet::getInstance().getRows(),width);

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
	PopupWindow help(TEXT_WINDOW_HEIGHT, EDIT_WIDTH, EDIT_POS_X, EDIT_POS_Y + 4);
	PopupController control(help);
	control.showText(FORMULAS);
}

void SheetController::showCredits() {
	PopupWindow help(TEXT_WINDOW_HEIGHT, EDIT_WIDTH, EDIT_POS_X, EDIT_POS_Y + 4);
	PopupController control(help);
	control.showText(CREDITS);
}

void SheetController::loop() {
	do {
		view.clear();
		view.draw();
		command = view.getInput();
		handleCommand(command);
	} while (!finished);
}

