/*
 Programmeertechnieken opdracht 2
 Andrew Huang        s1913999
 Paul Peters         s1453440
 Ruben van Erkelens  s1437267
 Karl Freeke         s1551973
 */

#include "popupcontroller.h"
#include "cellValueBase.h"

#define WINDOW_RIGHT_MARGIN 3
#define INT_MAX_LENGTH 3
#define DEFAULT_WINDOW_OFFSET 0

PopupController::PopupController(PopupWindow window, const int & row,
		const int & col) :
		window(window), row(row), col(col) {
}

PopupController::PopupController(PopupWindow window) :
		window(window), row(0), col(0) {
}

void PopupController::getInt(const std::string & msg, int & getal) {
	int command;
	editString = "";
	window.drawWindow();
	window.drawString(msg);
	do {
		command = window.getInput();
		if (isdigit(command) or command == KEY_BACKSPACE) {
			handlePopup(command);
			window.drawWindow();
			window.drawString(msg + format(editString, msg.size()));
		}
	} while (command != '\n');

	if ((not editString.empty()) && editString.size() <= INT_MAX_LENGTH)
		getal = stoi(editString);
	else {
		window.drawString(
				"ERROR: Incorrect number 0-" + std::to_string(INT_MAX_LENGTH)
						+ " digits allowed... press a key");
		window.getInput();
	}
}

void PopupController::inputSizeWindow() {
	int numRows(0), numColumns(0);
	getInt("Enter row size: ", numRows);
	getInt("Enter column size: ", numColumns);
	Sheet::getInstance().ensureSize(numRows, numColumns);
}

void PopupController::resizeLoop() {
	int command;
	window.initialize();
	window.drawWindow();
	window.drawString("Edit size? (y/n)");
	command = window.getInput();
	if (command == 'y')
		inputSizeWindow();
	window.exit();
}

void PopupController::editLoop() {
	int command;
	editString = Sheet::getInstance().getCell(row, col).getEditString();
	window.initialize();
	window.drawWindow();
	window.drawString(format(editString, DEFAULT_WINDOW_OFFSET));
	do {
		command = window.getInput();
		handlePopup(command);
		window.drawString(format(editString, DEFAULT_WINDOW_OFFSET));

	} while (command != '\n');
	writeString();
	window.exit();
}

void PopupController::showText(const std::string & text) {
	window.initialize();
	window.drawWindow();
	window.drawString(text);
	window.getInput();
	window.exit();
}

std::string PopupController::format(const std::string & str,
		const size_t & offset) {
	if (str.size() >= window.getWidth() - WINDOW_RIGHT_MARGIN - offset) {
		int startIndex = str.size()
				- (window.getWidth() - WINDOW_RIGHT_MARGIN - offset);
		return str.substr(startIndex);
	}
	return str;
}

void PopupController::handlePopup(int command) {
	switch (command) {
	case KEY_BACKSPACE:
		backspace();
		break;
	default:
		addToString(command);
		break;
	}
}

void PopupController::backspace() {
	if (!editString.empty())
		editString.pop_back();
}

void PopupController::addToString(char input) {
	if (input != '\n')
		editString += input;
}

void PopupController::writeString() {
		Sheet::getInstance().getCell(row, col).set(
				CellValueBase::cellValueFactory(editString));
}

