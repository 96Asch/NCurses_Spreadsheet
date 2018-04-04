#include "sheet.h"
#include "cellFormula.h"
#include "cellValue.h"
#include "cellAddress.h"
#include <iostream>
#include "cell.h"

static int testCounter;
static int failed;
const int whitespaceSize = 100;

template<typename T>
void assertEquals(const std::string & message, const T & obj1, const T & obj2) {
	size_t length = whitespaceSize - message.size();

	testCounter++;
	std::cout << message << "...";
	if(length > 0) {
		for (size_t i = 0; i < length; i++)
			std::cout << ' ';
	}

	if (obj1 == obj2) {
		std::cout << "Succes" << std::endl;
	}
	else {
		failed++;
		std::cout << "Failed: expected:" << obj2 << " got: " << obj1
				<< std::endl;
	}
}

void testFormula() {
	Sheet sheet;
	Cell cell;
	sheet.getCell(0, 0).set(new CellValue<int>(2));
	sheet.getCell(0, 1).set(new CellValue<int>(5));

	cell.set(new CellFormula(sheet, "=A1"));
	assertEquals("Testing formula =A1 = 2", cell.getInt(), 2);

	cell.set(new CellFormula(sheet, "=B1"));
	assertEquals("Testing formula =A1 = 5", cell.getInt(), 5);

	cell.set(new CellFormula(sheet, "=B1+A1"));
	assertEquals("Testing formula =B1+A1 = 7", cell.getInt(), 7);

	cell.set(new CellFormula(sheet, "=B1*A1"));
	assertEquals("Testing formula =B1*A1 = 10", cell.getInt(), 10);

	cell.set(new CellFormula(sheet, "=B1/A1"));
	assertEquals("Testing formula =B1/A1 = 2.5", cell.getFloat(), 2.5f);
}

void testCell() {
	Cell cell;

	std::string empty = "";
	assertEquals("Testing uninitialized cell", cell.getDrawString(), empty);

	std::string seven = "7";
	cell.set(new CellValue<int>(7));
	assertEquals("Testing cell value is 7 (string)", cell.getDrawString(),
			seven);
	assertEquals("Testing cell value is 7 (int)", cell.getInt(), 7);

	seven = "-7";
	cell.set(new CellValue<int>(-7));
	assertEquals("Testing cell value is -7 (string)", cell.getDrawString(),
			seven);
	assertEquals("Testing cell value is -7 (int)", cell.getInt(), -7);

	std::string onzin = "AaBb123456789,./;'[]";
	cell.set(new CellValue<std::string>("AaBb123456789,./;'[]"));
	assertEquals("Testing cell value is AaBb123456789,./;'[] (string)",
			cell.getDrawString(), onzin);
	assertEquals("Testing cell value is AaBb123456789,./;'[] (float)",
			cell.getFloat(), 0.0f);

	testFormula();

}

void printStats() {
	std::cout << "\nResults: ";
	for(size_t i = 0; i < whitespaceSize-30; i++)
		std::cout << ' ';
	std::cout << testCounter << " Tests run, " << failed << " failed tests" << std::endl;
}

int main(void) {
	testCell();
	printStats();
	return 0;
}

