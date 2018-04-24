/*
  Programmeertechnieken opdracht 2
  Andrew Huang        s1913999
  Paul Peters         s1453440
  Ruben van Erkelens  s1437267
  Karl Freeke         s1551973
*/

#ifndef SRC_TEST_TEST_H_
#define SRC_TEST_TEST_H_

#include <iostream>

#define WHITESPACE_SIZE 80

class Test {
public:

	template<typename T>
	void assertEquals(const std::string & message, const T & obj1,
			const T & obj2) {
		size_t length = WHITESPACE_SIZE - message.size();

		testAmount++;
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

	template<typename T, typename V>
	void assertEquals(const std::string & message, const T & obj1,
			const V & obj2) {
		size_t length = WHITESPACE_SIZE - message.size();

		testAmount++;
		std::cout << message << "...";
		if (length > 0) {
			for (size_t i = 0; i < length; i++)
				std::cout << ' ';
		}

		if (obj1 == static_cast<T>(obj2)) {
			std::cout << "Succes" << std::endl;
		} else {
			failed++;
			std::cout << "Failed: expected: " << obj2 << " got: " << obj1
					<< std::endl;
		}
	}

	void printStatistics() {
		std::cout << "\nResults: ";
		for (size_t i = 0; i < WHITESPACE_SIZE - 30; i++)
			std::cout << ' ';
		std::cout << testAmount << " Tests run, " << failed << " failed tests"
				<< std::endl;
	}
private:
	int testAmount = 0, failed = 0;

};

#endif /* SRC_TEST_TEST_H_ */
