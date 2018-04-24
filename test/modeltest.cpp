/*
  Programmeertechnieken opdracht 2
  Andrew Huang        s1913999
  Paul Peters         s1453440
  Ruben van Erkelens  s1437267
  Karl Freeke         s1551973
*/

#include "sheet.h"
#include "cellFormula.h"
#include "cellValue.h"
#include "cellAddress.h"
#include "range.h"
#include <iostream>
#include "cell.h"
#include "test.h"


void testFormula(Test & tester) {
	std::cout << "\n++++ FORMULA TEST CASE ++++" << std::endl;
	Cell cell;
	std::string error = "ERR";
	Sheet::getInstance().getCell(0, 0).set(new CellValue<int>(2));
	Sheet::getInstance().getCell(0, 1).set(new CellValue<int>(5));

	cell.set(new CellFormula("=8*8"));
	tester.assertEquals("Testing formula =8*8 = 64", cell.getInt(), 64);

	cell.set(new CellFormula("=8/8"));
	tester.assertEquals("Testing formula =8/8 = 1", cell.getInt(), 1);

	cell.set(new CellFormula("=55.5+44.5"));
	tester.assertEquals("Testing formula =55.5+44.5 = 100", cell.getFloat(), 100.0f);

	cell.set(new CellFormula("=A1"));
	tester.assertEquals("Testing formula =A1 = 2", cell.getInt(), 2);

	cell.set(new CellFormula("=B1"));
	tester.assertEquals("Testing formula =A1 = 5", cell.getInt(), 5);

	cell.set(new CellFormula("=B1+A1"));
	tester.assertEquals("Testing formula =B1+A1 = 7", cell.getInt(), 7);

	cell.set(new CellFormula("=B1*A1"));
	tester.assertEquals("Testing formula =B1*A1 = 10", cell.getInt(), 10);

	cell.set(new CellFormula("=B1/A1"));
	tester.assertEquals("Testing formula =B1/A1 = 2.5", cell.getFloat(), 2.5f);

	cell.set(new CellFormula("=s121a"));
	tester.assertEquals("Testing formula =s121a = ERR", cell.getDrawString(), "ERR");

	cell.set(new CellFormula("=A1+B1+8+8+8+8+8"));
	tester.assertEquals("Testing formula =A1+B1+8+8+8+8+8 = 47", cell.getInt(), 47);

	cell.set(new CellFormula("=(A1*B1)/0"));
	tester.assertEquals("Testing formula =(A1*B1)/0 = 0", cell.getInt(), 0);
	tester.assertEquals("Testing formula =(A1*B1)/0 = ERR", cell.getDrawString(),
			"ERR");

	Sheet::getInstance().getCell(1, 0).set(new CellValue<int>(1));
	Sheet::getInstance().getCell(1, 1).set(new CellValue<int>(2));

	cell.set(new CellFormula("=SUM(A1:B2)"));
	tester.assertEquals("Testing formula =SUM(A1:B2) = 10", cell.getInt(), 10);

	cell.set(new CellFormula("=AVG(A1:B2)"));
	tester.assertEquals("Testing formula =AVG(A1:B2) = 2.5", cell.getFloat(), 2.5f);

	cell.set(new CellFormula("=COUNT(A1:B2)"));
	tester.assertEquals("Testing formula =COUNT(A1:B2) = 4", cell.getInt(), 4);

	cell.set(new CellFormula("=SUM(A1:B2)+6-(4-5)"));
	tester.assertEquals("Testing formula =SUM(A1:B2)+6-(4-5) = 17", cell.getInt(), 17);

	cell.set(new CellFormula("=COUNT(A1:B2)*6-(4-5)"));
	tester.assertEquals("Testing formula =COUNT(A1:B2)*6-(4-5) = 25", cell.getInt(),
			25);

	cell.set(new CellFormula("=AVG(A1:B2)*4"));
	tester.assertEquals("Testing formula =AVG(A1:B2)*4 = 10", cell.getInt(), 10);

	cell.set(new CellFormula("=AVG(A1:B2)-SUM(A1:B2)"));
	tester.assertEquals("Testing formula =AVG(A1:B2)-SUM(A1:B2) = -7", cell.getInt(),
			-7);

	Sheet::getInstance().getCell(1, 0).set(CellValueBase::cellValueFactory("Hello World"));
	cell.set(CellValueBase::cellValueFactory("=A2"));
	tester.assertEquals("Testing formula =B2 = 0", cell.getInt(), 0);
	tester.assertEquals("Testing formula =B2 = Hello World", cell.getDrawString(), "Hello World");

	cell.set(CellValueBase::cellValueFactory("=SUM(A1:B2)"));
	tester.assertEquals("Testing formula =SUM(A1:B2), A2(string), = 2+5+2=9", cell.getFloat(), 9);
	tester.assertEquals("Testing formula =SUM(A1:B2), A2(string), = ERR", cell.getDrawString(), "ERR");

	Sheet::getInstance().getCell(0, 0).set(CellValueBase::cellValueFactory("=A1"));
	tester.assertEquals("Testing formula =A1 self reference", Sheet::getInstance().getCell(0, 0).getDrawString(), "ERR");

	Sheet::getInstance().getCell(2, 0).set(CellValueBase::cellValueFactory("=C2"));
	Sheet::getInstance().getCell(2, 1).set(CellValueBase::cellValueFactory("=C1"));

	tester.assertEquals("Testing formula =C2, circular reference ", Sheet::getInstance().getCell(2, 0).getDrawString(), "ERR");
}

void testCell(Test & tester) {
	std::cout << "\n++++ CELL TEST CASE ++++" << std::endl;
	Cell cell;

	tester.assertEquals("Testing uninitialized cell", cell.getDrawString(), "");

	std::string seven = "7";
	cell.set(new CellValue<int>(7));
	tester.assertEquals("Testing cell value is 7 (string)", cell.getDrawString(),
			seven);
	tester.assertEquals("Testing cell value is 7 (int)", cell.getInt(), 7);

	seven = "-7";
	cell.set(new CellValue<int>(-7));
	tester.assertEquals("Testing cell value is -7 (string)", cell.getDrawString(),
			seven);
	tester.assertEquals("Testing cell value is -7 (int)", cell.getInt(), -7);

	std::string onzin = "AaBb123456789,./;'[]";
	cell.set(new CellValue<std::string>("AaBb123456789,./;'[]"));
	tester.assertEquals("Testing cell value is AaBb123456789,./;'[] (string)",
			cell.getDrawString(), onzin);
	tester.assertEquals("Testing cell value is AaBb123456789,./;'[] (float)",
			cell.getFloat(), 0.0f);

	cell.set(CellValueBase::cellValueFactory("d"));
	tester.assertEquals("Testing cellValueFactory value: d", cell.getEditString(), "d");

	cell.set(CellValueBase::cellValueFactory("8"));
	tester.assertEquals("Testing cellValueFactory value: 8", cell.getInt(), 8);

	cell.set(CellValueBase::cellValueFactory("8.4"));
	tester.assertEquals("Testing cellValueFactory value: 8.4", cell.getFloat(), 8.4);

	cell.set(CellValueBase::cellValueFactory("=9"));
	tester.assertEquals("Testing cellValueFactory value: =9", cell.getInt(), 9);
}

void testCellAddress(Test & tester) {
	std::cout << "\n++++ CELLADDRESS TEST CASE ++++" << std::endl;
	CellAddress address;
	address.createFromReference("A1");

	tester.assertEquals("Testing CellAddress = A1, Column = 0", address.getColumn(),
			0);
	tester.assertEquals("Testing CellAddress = A1, Row = 0", address.getRow(), 0);

	address.createFromReference("G5");
	tester.assertEquals("Testing CellAddress = G5, Column = 6", address.getColumn(),
			6);
	tester.assertEquals("Testing CellAddress = G5, Row = 4", address.getRow(), 4);

	CellAddress faulty("AaAA");

//	tester.assertEquals("Testing CellAddress = AaAA, Row = 0", faulty.getRow(), 0);
//	tester.assertEquals("Testing CellAddress = AaAA, Col = 0", faulty.getColumn(), 0);
}

void testRange(Test & tester) {
	std::cout << "\n++++ RANGE TEST CASE ++++" << std::endl;

	Sheet::getInstance().getCell(0, 0).set(new CellValue<int>(1));
	Sheet::getInstance().getCell(1, 0).set(new CellValue<int>(2));
	Sheet::getInstance().getCell(2, 0).set(new CellValue<int>(3));
	Sheet::getInstance().getCell(3, 0).set(new CellValue<int>(4));
	Range range;

	Range::iterator it = range.rangeFromString("A1:A4")->begin();

	tester.assertEquals("Testing Range: A1:A4, A1 = 1 ", it->getInt(), 1);
	tester.assertEquals("Testing Range: A1:A4, A2 = 2 ", (++it)->getInt(), 2);
	tester.assertEquals("Testing Range: A1:A4, A3 = 3 ", (++it)->getInt(), 3);
	tester.assertEquals("Testing Range: A1:A4, A4 = 4 ", (++it)->getInt(), 4);

	CellAddress a1("B2"), a2("C3");
	it = range.createRange(a1, a2)->begin();

	Sheet::getInstance().getCell(1, 1).set(new CellValue<float>(9.6f));
	Sheet::getInstance().getCell(2, 1).set(new CellValue<int>(2));
	Sheet::getInstance().getCell(1, 2).set(new CellValue<std::string>("Hello"));
	Sheet::getInstance().getCell(2, 2).set(new CellValue<int>(99));

	tester.assertEquals("Testing Range: B2:C3, B2 = 9.6f ", it->getFloat(), 9.6f);
	tester.assertEquals("Testing Range: B2:C3, B3 = 2 ", (++it)->getInt(), 2);
	std::string check = "Hello";
	tester.assertEquals("Testing Range: B2:C3, C2 = Hello ", (++it)->getEditString(),
			check);
	tester.assertEquals("Testing Range: B2:C3, C3 = 99 ", (++it)->getInt(), 99);
	tester.assertEquals("Testing Range: B2:C3, C4 = 0 ", (++it)->getInt(), 0);

}

int main(void) {
	Test tester;
	testCell(tester);
	testFormula(tester);
	testCellAddress(tester);
	testRange(tester);
	tester.printStatistics();
	return 0;
}

