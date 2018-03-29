/*
 * cellAddress.cpp
 *
 *  Created on: Mar 22, 2018
 *      Author: asch
 */

#include "cellAddress.h"
#include <iostream>
#include <cmath>

CellAddress::CellAddress(std::string address) {
	// TODO Auto-generated constructor stub
  init (address);
}

CellAddress::~CellAddress() {
	// TODO Auto-generated destructor stub
}

int CellAddress::letterToInt(char c){
  return c - 64; 
}

void CellAddress::columnToNumber (std::string letter) {
  column = 0; 
  int multiplier;
  int exp = 0;
  for (int i = letter.size() - 1; i >= 0 ; i--, exp++){
    multiplier = letterToInt(letter[i]);
    column += multiplier * std::pow(26,exp);
  }

  std::cout<<" column:"<<column<<std::endl;
  std::cout<<" letter: " << letter<<std::endl;
}//columnToNumber

void CellAddress::rowToIndex(std::string rowNumber){
  row = std::stoi(rowNumber) - 1;
}

int CellAddress::getRow(){
  return row;
}

int CellAddress::getColumn() {
  return column;
}

void CellAddress::init(std::string address){
  for (size_t i = 0; i < address.length(); i++){
    if (isdigit(address[i])) {
        columnToNumber(address.substr(0,i));
        rowToIndex(address.substr(i));
        break;
    } 
  }
}
