#include "cell.h"
#include "cellAddress.h"
#include "cellFormula.h"
#include "util.h"
#include <iostream>
#include <string>

int main(void) {
	std::string input;

	std::cout << "Enter stuff\n";
	std::cin >> input;
	CellFormula formula(input);
	std::cout << "Raw Formula: " << formula.getEditString() << "\n"
				<< "Output: " << formula.getDrawString() << "\n"
				<< "Output Parsed Formula: ";
	formula.print();
	std::cout << std::endl;
}
