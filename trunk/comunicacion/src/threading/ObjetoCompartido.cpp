/*
 * ObjetoCompartido.cpp
 *
 *  Created on: 26/10/2013
 *      Author: joel
 */

#include "ObjetoCompartido.h"

ObjetoCompartido::ObjetoCompartido() {
	// TODO Auto-generated constructor stub

}

ObjetoCompartido::~ObjetoCompartido() {
	// TODO Auto-generated destructor stub
}

void ObjetoCompartido::lock() {
	this->traba.lock();
}

void ObjetoCompartido::unlock() {
	this->traba.unlock();
}
