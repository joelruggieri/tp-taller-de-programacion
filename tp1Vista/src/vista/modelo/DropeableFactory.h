/*
 * DropeableFactory.h
 *
 *  Created on: 29/08/2013
 *      Author: jonathan
 */

#ifndef DROPEABLEFACTORY_H_
#define DROPEABLEFACTORY_H_
#include "Dropeable.h"
#include <string>
class DropeableFactory {
private:
	string etiqueta;
public:
	DropeableFactory(string etiqueta);
	virtual ~DropeableFactory();
	Dropeable * crear();
};

#endif /* DROPEABLEFACTORY_H_ */
