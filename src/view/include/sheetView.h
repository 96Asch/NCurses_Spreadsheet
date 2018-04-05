

#ifndef INCLUDE_SHEETVIEW_H_
#define INCLUDE_SHEETVIEW_H_


#include <curses.h>




class SheetView{

	private:
		WINDOW *win;
	
	public:
		SheetView();
		~SheetView();
		
		void initialize();
		void draw();
	




};


#endif
