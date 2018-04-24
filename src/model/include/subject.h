/*
  Programmeertechnieken opdracht 2
  Andrew Huang        s1913999
  Paul Peters         s1453440
  Ruben van Erkelens  s1437267
  Karl Freeke         s1551973
*/

#ifndef SRC_UTIL_INCLUDE_SUBJECT_H_
#define SRC_UTIL_INCLUDE_SUBJECT_H_

#include <vector>
#include "observer.h"
#include "cell.h"

class Subject {
public:
	Subject();
	virtual ~Subject();

	virtual void notify() = 0;
	void attach(Observer* observer);
	void detach(Observer* observer);
	std::vector<Observer*> observers;
};

#endif /* SRC_UTIL_INCLUDE_SUBJECT_H_ */
