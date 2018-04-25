/*
  Programmeertechnieken opdracht 2
  Andrew Huang        s1913999
  Paul Peters         s1453440
  Ruben van Erkelens  s1437267
  Karl Freeke         s1551973
*/

#ifndef INCLUDE_POPUPWINDOW_H_
#define INCLUDE_POPUPWINDOW_H_

#include <curses.h>
#include "cellAddress.h"

class PopupWindow {

private:
	WINDOW *popupwin;
	size_t height, width;
	int posX, posY;

public:
	/**
	 *	Constructor of PopupWindow class.
	 * @param integer value for height.
	 * @param integer value for width.
	 *	@param integer value for position X .
	 * @param integer value for position Y.
	 */
	PopupWindow(const int & height, const int & width, const int & posX, const int & posY);
	/**
	 * Initializes popupwindow.
	 */
	void initialize();
	/**
	 *	Draws borders of popupwindow.
	 */
	void drawWindow();
	/**
	 *	Exits curses and deallocates popupwindow.
	 *	
	 */
	void exit();
	/**
	 *	Gets input from user.
	 *	@return integer value.
	 */
	int getInput();
	/**
	 *	Gets height of popupwindow.
	 * @return size_t value
	 */
	size_t getHeight() const;
	/**
	 *	gets width of popupwindow.
	 */
	size_t getWidth() const;
	/**
	 *
	 */
	void drawString(const std::string & inputString);
};

#endif
