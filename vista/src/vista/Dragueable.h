/*
 * Dragueable.h
 *
 *  Created on: 06/09/2013
 *      Author: ezequiel
 */

#ifndef DRAGUEABLE_H_
#define DRAGUEABLE_H_
#include "Dibujable.h"
#include "Resizeable.h"
#include "View.h"

class Dragueable{
public:
	virtual ~Dragueable();
	virtual bool isDragging() = 0;
	virtual View * getDragueado() = 0;
};

#endif /* DRAGUEABLE_H_ */
