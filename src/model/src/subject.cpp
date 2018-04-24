/*
  Programmeertechnieken opdracht 2
  Andrew Huang        s1913999
  Paul Peters         s1453440
  Ruben van Erkelens  s1437267
  Karl Freeke         s1551973
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

