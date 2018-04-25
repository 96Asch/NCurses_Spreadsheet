/*
 Programmeertechnieken opdracht 2
 Andrew Huang        s1913999
 Paul Peters         s1453440
 Ruben van Erkelens  s1437267
 Karl Freeke         s1551973
 */

#ifndef SRC_CONTROLLER_INCLUDE_SHEETCONTROLLER_H_
#define SRC_CONTROLLER_INCLUDE_SHEETCONTROLLER_H_


#include "sheetView.h"
#include "sheet.h"
#include "popupcontroller.h"

class SheetController {
public:
	/**
	 * Constructor SheetController class
	 * @param Sheetview value.
	*/
	SheetController(SheetView view);
	/**
	 * Deconstructor Sheetcontroller class
	 * 
	*/
	virtual ~SheetController();
	/**
	 * Runs SheetView
	 * 
	*/
	void run();

private:
	SheetView view;
	bool finished;
	int command;
	/**
	 * Moves cursor location up.
	 * 
	*/
	void moveCursorUp();
	/**
	 *  Moves cursor location down.
	 * 
	*/
	void moveCursorDown();
	/**
	 *  Moves cursor location left.
	 * 
	*/
	void moveCursorLeft();
	/**
	 *  Moves cursor location right.
	 * 
	*/
	void moveCursorRight();
	/**
	 * Handles user input.
	 * @param integer value.
	*/
	void handleCommand(const int & command);
	/**
	 * Loops the sheetview until finished.
	 * 
	*/
	void loop();
	/**
	 * Creates popupwindow for resizing the sheet.
	 * 
	*/
	void editSize();
	/**
	 * Creates popupwindow with formulae.
	 * 
	*/
	void showFormulae();
	/**
	 * Creates popupwindow with credits.
	 * 
	*/
	void showCredits();
	/**
	 * Handles the Enter command.
	 * 
	*/
	void pressEnter();
	/**
	 * Deletes the value of a cell
	 * 
	*/
	void deleteCell();

};

#endif /* SRC_CONTROLLER_INCLUDE_SHEETCONTROLLER_H_ */
