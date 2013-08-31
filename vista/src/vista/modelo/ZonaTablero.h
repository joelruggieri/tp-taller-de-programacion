/*
 * ZonaTablero.h
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#ifndef ZONATABLERO_H_
#define ZONATABLERO_H_

#include "ZonaDragAndDrop.h"

class ZonaTablero: public ZonaDragAndDrop {
private:
	   bool dropTemplate(Dropeable * dragueable);
	   Dropeable * dragTemplate(float x, float y);
public:
	ZonaTablero(Cuerpo cuerpo);
	virtual ~ZonaTablero();

};

#endif /* ZONATABLERO_H_ */
