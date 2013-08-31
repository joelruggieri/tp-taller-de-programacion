/*
 * DropManager.h
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 *
 *      TODO ESTE TIPO DEBERÍA HACER LOS PIXELS DE LA PANTALLA NO DEBERÍAN LLEGAR A LAS ZONAS.
 */

#ifndef DROPMANAGER_H_
#define DROPMANAGER_H_
#include "../modelo/Dropeable.h"
class DropManager {
public:
	DropManager();
	Dropeable * drag(float x, float y);
	virtual ~DropManager();
};

#endif /* DROPMANAGER_H_ */
