/*
 * DropeableFactoryB.h
 *
 *  Created on: 29/08/2013
 *      Author: jonathan
 */

#ifndef DROPEABLEFACTORYB_H_
#define DROPEABLEFACTORYB_H_

#include "DropeableFactory.h"

class DropeableFactoryB: public DropeableFactory {
public:
	DropeableFactoryB();
	virtual ~DropeableFactoryB();
	Dropeable * crear();
};

#endif /* DROPEABLEFACTORYB_H_ */
