/*
 * Observer.h
 *
 *  Created on: Apr 6, 2018
 *      Author: asch
 */

#ifndef SRC_UTIL_OBSERVER_H_
#define SRC_UTIL_OBSERVER_H_

#include "cell.h"

class Observer {
public:
	Observer(){};
	virtual ~Observer(){};
	virtual void update() = 0;
};

#endif /* SRC_UTIL_OBSERVER_H_ */
