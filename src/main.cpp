#include "cell.h"
#include "cellFormulaParser.h"
#include "util.h"
#include <iostream>
#include <string>

int main(void) {
	std::string input;

	std::cout << "Enter stuff\n";
	CellFormulaParser parser;
	while (std::cin >> input) {
		if(!parser.parse(input))
			std::cout << "parse error" << std::endl;
	}
}
