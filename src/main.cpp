#include <stdio.h>
#include <stdlib.h>
#include "cell.h"
#include <iostream>
#include <string>

int main(void) {
	std::string input;
	
	std::cout << "Enter stuff\n";
	while (std::cin >> input) {
	
	Cell cell;
	
	cell.readString(input);
	
	std::cout << cell.getEditString() << std::endl;
  }
}
