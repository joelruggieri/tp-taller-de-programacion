/*
 * DropeableFactory.h
 *
 *  Created on: 29/08/2013
 *      Author: jonathan
 */

#ifndef DROPEABLEFACTORY_H_
#define DROPEABLEFACTORY_H_
#include "Dropeable.h"

class DropeableFactory {
private:
public:
	virtual ~DropeableFactory();
	virtual Dropeable * crear()=0;
};

#endif /* DROPEABLEFACTORY_H_ */
