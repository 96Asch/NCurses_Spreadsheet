/*
  Programmeertechnieken opdracht 2
  Andrew Huang        s1913999
  Paul Peters         s1453440
  Ruben van Erkelens  s1437267
  Karl Freeke         s1551973
*/

#ifndef POPUPCONTROLLER_H_
#define POPUPCONTROLLER_H_

#include "sheet.h"
#include "popupwindow.h"

class PopupController {

public:
	/**
	 * Constructor for the PopupController class.
	 * @param Popupwindow, the window.
	 * @param integer value for row position
	 * @param integer value for column position
	 */
	PopupController(PopupWindow window, const int & row, const int & col);
	/**
	 * Constructor for the PopupController class.
	 * @param Popupwindow, the window.
	*/
	PopupController(PopupWindow window);
	/**
	 * Loop for popupwindow that edits the cells
	 * 
	*/
	void editLoop();
	/**
	 * Loop for popupwindow that resizes the sheet.
	 * 
	*/
	void resizeLoop();
	/**
	 * Prints text in popupwindow.
	 * @param std::string value.
	*/
	void showText(const std::string & text);

private:
	PopupWindow window;
	std::string editString;
	int row, col;
	/**
	 * handles user input in the popupwindow.
	 * @param integer value from user.
	*/
	void handlePopup(int command);
	/**
	 * Writes string of popupwindow to the Sheets model.
	 * 
	*/
	void writeString();
	/**
	 * Backspace function in popupwindow.
	 * 
	*/
	void backspace();
	/**
	 * Adds character to string in popupwindow.
	 * @param character value.
	*/
	void addToString(char input);
	/**
	 * Formats string in popupwindow, to not exceed the window.
	 * @param std::string value.
	 * @param size_T vale for offset.
	 * @return std::string value,formatted.
	*/
	std::string format(const std::string & str, const size_t & offset);
	/**
	 * Asks user for input with a certain message for resize popupwindow.
	 *	@param std::string value for message,
	 *	@param integer value, varaible to resize  
	*/
	void getInt(const std::string & msg, int & getal);
	/**
	 * resizes sheet from the input of the resize popupwindow.
	 * 
	*/
	void inputSizeWindow();
};

#endif
