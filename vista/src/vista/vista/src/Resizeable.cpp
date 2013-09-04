/*
 * Resizeable.cpp
 *
 *  Created on: 04/09/2013
 *      Author: ezequiel
 */

#include "Resizeable.h"

namespace std {

Resizeable::Resizeable() {
	// TODO Auto-generated constructor stub

}

Resizeable::~Resizeable() {
	// TODO Auto-generated destructor stub


} /* namespace std */

void Resizeable::Resizear(int x, int y)
{
	this->w = this->w + x;
	this->h = this->h + y;

}
}
