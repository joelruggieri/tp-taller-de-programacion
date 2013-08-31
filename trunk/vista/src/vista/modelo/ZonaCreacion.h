/*
 * ZonaCreacion.h
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#ifndef ZONACREACION_H_
#define ZONACREACION_H_

#include "ZonaDragAndDrop.h"
#include "EslabonCreacion.h"

class ZonaCreacion: public ZonaDragAndDrop {
private:
	EslabonCreacion * inicioCadena;
	EslabonCreacion * ultimo;
	bool dropTemplate(Dropeable * dragueable);
	Dropeable * dragTemplate(float x, float y);
public:
	ZonaCreacion(Cuerpo cuerpo);
	virtual ~ZonaCreacion();
	void agregarEslabon(EslabonCreacion* eslabon);
};

#endif /* ZONACREACION_H_ */
