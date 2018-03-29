#include "cell.h"
#include "cellAddress.h"
#include "cellFormula.h"
#include "util.h"
#include <iostream>
#include <string>
#include <cellAddress.h>

int main(void) {
	std::string input;

  CellAddress cell("AB32");
  
  std::cout<<cell.getColumn()<<std::endl;

	std::cout << "Enter stuff\n";
	std::cin >> input;
	CellFormula formula(input);
	std::cout 	<< "Edit String: " << formula.getEditString() << "\n"
				<< "Draw String: " << formula.getDrawString() << "\n"
				<< "Output Parsed Formula: ";
				formula.print();
	std::cout 	<< "\nEvaluation Result Int: " << formula.getInt() << "\n"
				<< "Evaluation Result Float: " << formula.getFloat() << std::endl;
}
