/*
 * Resizeable.h
 *
 *  Created on: 04/09/2013
 *      Author: ezequiel
 */

#ifndef RESIZEABLE_H_
#define RESIZEABLE_H_
#include "Posicionable.h"

namespace std {

class Resizeable : virtual public Posicionable {
public:
	Resizeable();
	void Resizear(int x, int y);
	virtual ~Resizeable();
};

} /* namespace std */
#endif /* RESIZEABLE_H_ */
