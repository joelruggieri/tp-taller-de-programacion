/*
 * Resizeable.cpp
 *
 *  Created on: 04/09/2013
 *      Author: ezequiel
 */

#include "Resizeable.h"

namespace CLIENTE {
Resizeable::Resizeable() {
	// TODO Auto-generated constructor stub

}

Resizeable::~Resizeable() {
	// TODO Auto-generated destructor stub


} /* namespace std */

Transformacion* Resizeable::getTl(){
	return tl;
}

void Resizeable::setTl(Transformacion* tl) {
	this->tl = tl;
}

}
