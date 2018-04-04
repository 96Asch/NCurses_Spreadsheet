#include "sheet.h"
#include "cell.h"
#include <iostream>

int main(void) {
	Sheet sheet;
	sheet.getCell(0, 0).readFloat(4);
	std::cout << sheet.getCell(0, 0).getFloat() << std::endl;
	return 0;
}
