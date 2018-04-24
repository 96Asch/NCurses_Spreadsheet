/*
  Programmeertechnieken opdracht 2
  Andrew Huang        s1913999
  Paul Peters         s1453440
  Ruben van Erkelens  s1437267
  Karl Freeke         s1551973
*/

#ifndef SRC_UTIL_OBSERVER_H_
#define SRC_UTIL_OBSERVER_H_

#include "cell.h"

class Observer {
public:

	/**
	 * Constructor for the Observer class
	 */
	Observer(){};

	/**
	 * Destructor for the Observer class.
	 */
	virtual ~Observer(){};

	/**
	 * Updates this class.
	 */
	virtual void update() = 0;
};

#endif /* SRC_UTIL_OBSERVER_H_ */
