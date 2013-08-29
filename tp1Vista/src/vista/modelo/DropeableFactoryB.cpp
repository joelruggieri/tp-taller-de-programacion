/*
 * DropeableFactoryB.cpp
 *
 *  Created on: 29/08/2013
 *      Author: jonathan
 */

#include "DropeableFactoryB.h"

DropeableFactoryB::DropeableFactoryB() {
	// TODO Auto-generated constructor stub

}

DropeableFactoryB::~DropeableFactoryB() {
	// TODO Auto-generated destructor stub
}

Dropeable* DropeableFactoryB::crear() {
	return new Dropeable("b");
}
