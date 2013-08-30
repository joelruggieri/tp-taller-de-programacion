/*
 * DropManager.h
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#ifndef DROPMANAGER_H_
#define DROPMANAGER_H_
#include "Dropeable.h"
#include "EslabonCreacion.h"
class DropManager {
	EslabonCreacion * inicioCadena;
	EslabonCreacion * ultimo;
public:
	DropManager();
	Dropeable * drag(float x, float y);
	virtual ~DropManager();
	void agregarEslabon(EslabonCreacion *);
};

#endif /* DROPMANAGER_H_ */
