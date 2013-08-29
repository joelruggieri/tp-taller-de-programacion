/*
 * DropeableFactoryA.cpp
 *
 *  Created on: 29/08/2013
 *      Author: jonathan
 */

#include "DropeableFactoryA.h"

DropeableFactoryA::DropeableFactoryA() {
	// TODO Auto-generated constructor stub

}

DropeableFactoryA::~DropeableFactoryA() {
	// TODO Auto-generated destructor stub
}

Dropeable* DropeableFactoryA::crear() {
	return new Dropeable("a");
}
