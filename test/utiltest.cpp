/*
 * utiltest.cpp
 *
 *  Created on: Apr 5, 2018
 *      Author: asch
 */

#include "util.h"
#include "test.h"
#include <string>
#include <iostream>

//void testSplitAddress(const std::string & address, size_t & index) ???

void testUtil(Test & tester) {
  std::string error = "ERR";
  
  //TESTING splitAddress(const std::string & address, size_t & index)
  size_t index = 0; //size_t is needed for splitAddress()
  int index2 = 0; //int is needed for assertEquals()
  
  std::string testString = "AB12";
  splitAddress(testString, index);
  index2 = index;
  tester.assertEquals("Testing splitAddress: AA11", 2, index2);
  
  testString = "AAAAAAAAAA12";
  splitAddress(testString, index);
  index2 = index;
  tester.assertEquals("Testing splitAddress: AAAAAAAAAA11", 10, index2);

  //TESTING contains(const std::string & src, const char & c, int & occurence)
  testString = "abcdefghijklmnopqrstuvqxyz";
  char testChar = 'A';
  bool test = false; //expected result
  int testje = 0;
  tester.assertEquals("Testing contains: A in abcdefghijklmnopqrstuvqxyz", contains(testString, testChar, testje), false);
  
  testString = "ABCDEFGHIJKLMNOPQRSTUVQXYZ";
  testChar = 'a';
  test = false; //expected result
  testje = 0;
  tester.assertEquals("Testing contains: a in ABCDEFGHIJKLMNOPQRSTUVQXYZ", contains(testString, testChar, testje), test);
  
  testString = "ABCDEFGHIJKLMNOPQRSTUVQXYZ";
  testChar = 'A';
  test = true; //expected result
  testje = 0;
  tester.assertEquals("Testing contains: A in ABCDEFGHIJKLMNOPQRSTUVQXYZ", contains(testString, testChar, testje), test);
  
  testString = "0123456789";
  testChar = '0';
  test = true; //expected result
  testje = 0;
  tester.assertEquals("Testing contains: A in ABCDEFGHIJKLMNOPQRSTUVQXYZ", contains(testString, testChar, testje), test);
  
  testString = "0123456789";
  testChar = 'A';
  test = false; //expected result
  testje = 0;
  tester.assertEquals("Testing contains: A in ABCDEFGHIJKLMNOPQRSTUVQXYZ", contains(testString, testChar, testje), test);
  
  //TESTING isCellAddress(const std::string & address)
  testString = "AAA1";
  test = true;
  tester.assertEquals("Testing isCellAddress: AAAAAAAAA1", isCellAddress(testString), test);
  
  testString = "A999";
  test = true;
  tester.assertEquals("Testing isCellAddress: A999999999", isCellAddress(testString), test);
  
  testString = "aA1";
  test = false;
  tester.assertEquals("Testing isCellAddress: aA1", isCellAddress(testString), test);
  
  testString = "Aa1";
  test = false;
  tester.assertEquals("Testing isCellAddress: Aa1", isCellAddress(testString), test);
  
  testString = "a1";
  test = false;
  tester.assertEquals("Testing isCellAddress: a1", isCellAddress(testString), test);
  
  testString = "A?";
  test = false;
  tester.assertEquals("Testing isCellAddress: A?  ", isCellAddress(testString), test); 
}


int main(void) {
	Test tester;
  testUtil(tester);

	tester.printStatistics();
	return 0;
}


/*
void splitAddress(const std::string & address, size_t & index);
bool contains(const std::string & src, const char & c, int & occurence);
bool isCellAddress(const std::string & address);
bool isOperator(const std::string & str);
bool isOperator(const char & c);
bool isInteger(const float & val);
*/
