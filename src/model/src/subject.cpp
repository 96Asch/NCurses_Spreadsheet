/*
 * subject.cpp
 *
 *  Created on: Apr 6, 2018
 *      Author: asch
 */

#include "subject.h"
#include <algorithm>

Subject::Subject() {
}

Subject::~Subject() {
}

void Subject::attach(Observer* observer) {
	observers.push_back(observer);
}

void Subject::detach(Observer* observer) {
	observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

