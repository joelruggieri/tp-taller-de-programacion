/*
 * DropeableFactoryA.h
 *
 *  Created on: 29/08/2013
 *      Author: jonathan
 */

#ifndef DROPEABLEFACTORYA_H_
#define DROPEABLEFACTORYA_H_

#include "DropeableFactory.h"

class DropeableFactoryA: public DropeableFactory {
public:
	DropeableFactoryA();
	virtual ~DropeableFactoryA();
	Dropeable * crear();
};

#endif /* DROPEABLEFACTORYA_H_ */
