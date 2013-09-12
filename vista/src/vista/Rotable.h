/*
 * Rotable.h
 *
 *  Created on: 11/09/2013
 *      Author: jonathan
 */

#ifndef ROTABLE_H_
#define ROTABLE_H_
#include "figura/FiguraView.h"
class Rotable {
public:
	Rotable();
	virtual ~Rotable();
	virtual bool isRotando() = 0;
	virtual View * getRotado() = 0;
};

#endif /* ROTABLE_H_ */
