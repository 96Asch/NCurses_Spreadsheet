#include "sheet.h"
#include "cellFormula.h"
#include "cellValue.h"
#include "cellAddress.h"
#include "range.h"
#include <iostream>
#include "cell.h"

static int testCounter;
static int failed;
const int whitespaceSize = 60;

template<typename T>
void assertEquals(const std::string & message, const T & obj1, const T & obj2) {
	size_t length = whitespaceSize - message.size();

	testCounter++;
	std::cout << message << "...";
	if (length > 0) {
		for (size_t i = 0; i < length; i++)
			std::cout << ' ';
	}

	if (obj1 == obj2) {
		std::cout << "Succes" << std::endl;
	} else {
		failed++;
		std::cout << "Failed: expected: " << obj2 << " got: " << obj1
				<< std::endl;
	}
}

void testFormula() {
	std::cout << "\n++++ FORMULA TEST CASE ++++" << std::endl;
	Cell cell;
	std::string error = "ERR";
	Sheet::getInstance().getCell(0, 0).set(new CellValue<int>(2));
	Sheet::getInstance().getCell(0, 1).set(new CellValue<int>(5));

	cell.set(new CellFormula("=8*8"));
	assertEquals("Testing formula =8*8 = 64", cell.getInt(), 64);

	cell.set(new CellFormula("=8/8"));
	assertEquals("Testing formula =8/8 = 1", cell.getInt(), 1);

	cell.set(new CellFormula("=A1"));
	assertEquals("Testing formula =A1 = 2", cell.getInt(), 2);

	cell.set(new CellFormula("=B1"));
	assertEquals("Testing formula =A1 = 5", cell.getInt(), 5);

	cell.set(new CellFormula("=B1+A1"));
	assertEquals("Testing formula =B1+A1 = 7", cell.getInt(), 7);

	cell.set(new CellFormula("=B1*A1"));
	assertEquals("Testing formula =B1*A1 = 10", cell.getInt(), 10);

	cell.set(new CellFormula("=B1/A1"));
	assertEquals("Testing formula =B1/A1 = 2.5", cell.getFloat(), 2.5f);

	cell.set(new CellFormula("=s121a"));
	assertEquals("Testing formula =s121a = ERR", cell.getDrawString(), error);

	cell.set(new CellFormula("=A1+B1+8+8+8+8+8"));
	assertEquals("Testing formula =A1+B1+8+8+8+8+8 = 47", cell.getInt(), 47);

	cell.set(new CellFormula("=(A1*B1)/0"));
	assertEquals("Testing formula =(A1*B1)/0 = 0", cell.getInt(), 0);
	assertEquals("Testing formula =(A1*B1)/0 = ERR", cell.getDrawString(),
			error);

	Sheet::getInstance().getCell(1, 0).set(new CellValue<int>(1));
	Sheet::getInstance().getCell(1, 1).set(new CellValue<int>(2));

	cell.set(new CellFormula("=SUM(A1:B2)"));
	assertEquals("Testing formula =SUM(A1:B2) = 10", cell.getInt(), 10);

	cell.set(new CellFormula("=AVG(A1:B2)"));
	assertEquals("Testing formula =AVG(A1:B2) = 2.5", cell.getFloat(), 2.5f);

	cell.set(new CellFormula("=COUNT(A1:B2)"));
	assertEquals("Testing formula =COUNT(A1:B2) = 4", cell.getInt(), 4);

	cell.set(new CellFormula("=SUM(A1:B2)+6-(4-5)"));
	assertEquals("Testing formula =SUM(A1:B2)+6-(4-5) = 17", cell.getInt(), 17);

	cell.set(new CellFormula("=COUNT(A1:B2)*6-(4-5)"));
	assertEquals("Testing formula =COUNT(A1:B2)*6-(4-5) = 25", cell.getInt(),
			25);

	cell.set(new CellFormula("=AVG(A1:B2)*4"));
	assertEquals("Testing formula =AVG(A1:B2)*4 = 10", cell.getInt(), 10);

	cell.set(new CellFormula("=AVG(A1:B2)-SUM(A1:B2)"));
	assertEquals("Testing formula =AVG(A1:B2)-SUM(A1:B2) = -7", cell.getInt(),
			-7);
}

void testCell() {
	std::cout << "\n++++ CELL TEST CASE ++++" << std::endl;
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

void testCellAddress() {
	std::cout << "\n++++ CELLADDRESS TEST CASE ++++" << std::endl;
	CellAddress address;
	address.createFromReference("A1");

	assertEquals("Testing CellAddress = A1, Column = 0", address.getColumn(),
			0);
	assertEquals("Testing CellAddress = A1, Row = 0", address.getRow(), 0);

	address.createFromReference("G5");
	assertEquals("Testing CellAddress = G5, Column = 6", address.getColumn(),
			6);
	assertEquals("Testing CellAddress = G5, Row = 4", address.getRow(), 4);
}

void testRange() {
	std::cout << "\n++++ RANGE TEST CASE ++++" << std::endl;

	Sheet::getInstance().getCell(0, 0).set(new CellValue<int>(1));
	Sheet::getInstance().getCell(1, 0).set(new CellValue<int>(2));
	Sheet::getInstance().getCell(2, 0).set(new CellValue<int>(3));
	Sheet::getInstance().getCell(3, 0).set(new CellValue<int>(4));
	Range range;

	Range::iterator it = range.rangeFromString("A1:A4")->begin();

	assertEquals("Testing Range: A1:A4, A1 = 1 ", it->getInt(), 1);
	assertEquals("Testing Range: A1:A4, A2 = 2 ", (++it)->getInt(), 2);
	assertEquals("Testing Range: A1:A4, A3 = 3 ", (++it)->getInt(), 3);
	assertEquals("Testing Range: A1:A4, A4 = 4 ", (++it)->getInt(), 4);

	CellAddress a1("B2"), a2("C3");
	it = range.createRange(a1, a2)->begin();

	Sheet::getInstance().getCell(1, 1).set(new CellValue<float>(9.6f));
	Sheet::getInstance().getCell(2, 1).set(new CellValue<int>(2));
	Sheet::getInstance().getCell(1, 2).set(new CellValue<std::string>("Hello"));
	Sheet::getInstance().getCell(2, 2).set(new CellValue<int>(99));

	assertEquals("Testing Range: B2:C3, B2 = 9.6f ", it->getFloat(), 9.6f);
	assertEquals("Testing Range: B2:C3, B3 = 2 ", (++it)->getInt(), 2);
	std::string check = "Hello";
	assertEquals("Testing Range: B2:C3, C2 = Hello ", (++it)->getEditString(),
			check);
	assertEquals("Testing Range: B2:C3, C3 = 99 ", (++it)->getInt(), 99);
	assertEquals("Testing Range: B2:C3, C4 = 0 ", (++it)->getInt(), 0);
}

void printStats() {
	std::cout << "\nResults: ";
	for (size_t i = 0; i < whitespaceSize - 30; i++)
		std::cout << ' ';
	std::cout << testCounter << " Tests run, " << failed << " failed tests"
			<< std::endl;
}

int main(void) {
	testCell();
	testCellAddress();
	testRange();
	printStats();
	return 0;
}

