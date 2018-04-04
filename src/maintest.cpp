#include "sheet.h"
#include "cellFormula.h"
#include "cellValue.h"
#include "cellAddress.h"
#include <iostream>
#include "cell.h"


template <typename T>
void assertEquals (const T & obj1, const T & obj2) {
  if (obj1 == obj2)
    std::cout << "Succes" << std::endl;
  else 
    std::cout << "Failed: expected:" << obj2 << " got: " << obj1  << std::endl;
}

void testCell() {
  Cell cell;
  std::string empty = "";
  std::cout << "Testing empty: ";
  assertEquals(cell.getDrawString(), empty);
  
  std::string seven = "7";
  std::cout << "Testing int 7: ";
  cell.set(new CellValue<int>(7));
  assertEquals(cell.getDrawString(), seven);
  assertEquals(cell.getInt(), 7);
  
  seven = "-7";
  std::cout << "Testing int -7: ";
  cell.set(new CellValue<int>(-7));
  assertEquals(cell.getDrawString(), seven);
  assertEquals(cell.getInt(), -7);
  
  std::string absurd = "9999999999.9999999999";
  std::cout << "Testing float 9999999999.9999999999: ";
  cell.set(new CellValue<float>(9999999999.9999999999f));
  assertEquals(cell.getDrawString(), absurd);
  assertEquals(cell.getFloat(), 9999999999.9999999999f);
  
  absurd = "-9999999999.9999999999";
  std::cout << "Testing float -9999999999.9999999999: ";
  cell.set(new CellValue<float>(-9999999999.9999999999f));
  assertEquals(cell.getDrawString(), absurd);
  assertEquals(cell.getFloat(), -9999999999.9999999999f);
  
  std::string onzin = "AaBb123456789,./;'[]";
  std::cout << "Testing string AaBb123456789,./;'[]: ";
  cell.set(new CellValue<std::string>("AaBb123456789,./;'[]"));
  assertEquals(cell.getDrawString(), onzin);
  assertEquals(cell.getFloat(), 0.0f);
  
  
  Sheet sheet;
  sheet.getCell(0,0).set(new CellValue<int>(2));
  sheet.getCell(0,1).set(new CellValue<int>(5));
  
  std::cout << "Testing formula =A1: ";
  cell.set(new CellFormula(sheet, "=A1"));
  assertEquals(cell.getInt(), 2);
  
  std::cout << "Testing formula =B1: ";
  cell.set(new CellFormula(sheet, "=B1"));
  assertEquals(cell.getInt(), 5);
  
  std::cout << "Testing formula =B1+A1: ";
  cell.set(new CellFormula(sheet, "=B1+A1"));
  assertEquals(cell.getInt(), 7);
  
  std::cout << "Testing formula =B1*A1: ";
  cell.set(new CellFormula(sheet, "=B1*A1"));
  assertEquals(cell.getInt(), 10);
  
  std::cout << "Testing formula =B1/A1: ";
  cell.set(new CellFormula(sheet, "=B1/A1"));
  assertEquals(cell.getFloat(), 2.5f);
  
  
  CellAddress add("A1");
  
  std::cout << add.getRow() << add.getColumn() << std::endl;
  
}


int main(void) {
	testCell();
	return 0;
}

