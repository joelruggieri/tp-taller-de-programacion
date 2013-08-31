/*
 * ZonaJuego.h
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#ifndef ZONAJUEGO_H_
#define ZONAJUEGO_H_

#include "ZonaDragAndDrop.h"

class ZonaJuego: public ZonaDragAndDrop {
private:
	ZonaDragAndDrop * zonaTablero;
	ZonaDragAndDrop * zonaCreacion;
public:
	ZonaJuego(Cuerpo cuerpo);
	virtual ~ZonaJuego();
};

#endif /* ZONAJUEGO_H_ */
