/*
 * subject.h
 *
 *  Created on: Apr 6, 2018
 *      Author: asch
 */

#ifndef SRC_UTIL_INCLUDE_SUBJECT_H_
#define SRC_UTIL_INCLUDE_SUBJECT_H_

#include <vector>
#include "observer.h"

class Subject {
public:
	Subject();
	virtual ~Subject();

	virtual void notify(int row, int col) = 0;
	void attach(Observer* observer);
	void detach(Observer* observer);
	std::vector<Observer*> observers;
};

#endif /* SRC_UTIL_INCLUDE_SUBJECT_H_ */
