/*
  Programmeertechnieken opdracht 2
  Andrew Huang        s1913999
  Paul Peters         s1453440
  Ruben van Erkelens  s1437267
  Karl Freeke         s1551973
*/

#ifndef INCLUDE_SHEETVIEW_H_
#define INCLUDE_SHEETVIEW_H_

#include <curses.h>
#include "cellAddress.h"



class SheetView {

private:
	WINDOW *win;
	CellAddress cursorLocation;
	std::string INFORMATION = "q: Exit  r: Resize sheet  h: Show formulas  ENTER: edit cell  BACKSPACE: delete cell";
	

	/**
	 * Prints string and higlights the cell.
	 * @param string value
	 */
	void drawHighlight(const char* string);
	 /**
	 * Prints the header: column and row names.
	 */
	void drawHeader();
	/**
	 * Prints the cells with value.
	 */
	void drawCells();
	/**
	 * Prints help shortkeys.
	 */
	void drawHelp();
	/**
	 * Draws the cursor at its location.
	 */
	void drawCursor();
	/**
	 * Converts column number to alphabetic notation.
	 * @return string value.
	 * @param integer value.
	 */
	std::string numberToAlpha(const int & num);
	/**
	 * Formats string to be written in cell.
	 * @return string value.
	 * @param string value.
	 */
	std::string formatter(const std::string & cellstring);

public:
	/**
	 * Constructor for the SheetView class.
	 */
	SheetView();
	/**
	 * Destructor for the Cell class.
	 */
	~SheetView();
	/**
	 * Gets input from user.
	 * @return integer value.
	 */
	int getInput();
	/**
	 * Intitializes sheet view with certain rows and columns.
	 * @param integer value for rows.
	 * @param integer value for columns.
	 */
	void initialize(const int & numRows, const int & numCols);
	/**
	 * Exits curses and deallocates sheet .
	 */
	void exit();
	/**
	 * Erases and refreshes sheet.
	 */
	void clear();
	/**
	 * Draws header, help, cells and cursor.
	 */
	void draw();
	/**
	 * Removes the help shortkeys.
	 */
	void removeHelp();
	/**
	 * Returns Celladdress of cursorlocation.
	 * @return Celladdress value.
	 */
	CellAddress getCursor();
	/**
	 * sets cursor at new location.
	 *	@param Cursorlocation value.
	 */
	void setCursor(const CellAddress newLocation);


};

#endif
