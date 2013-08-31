/*
 * ZonaDragAndDrop.h
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#ifndef ZONADRAGANDDROP_H_
#define ZONADRAGANDDROP_H_

#include "Cuerpo.h"
#include "Dropeable.h"
class ZonaDragAndDrop {
private:
	Cuerpo cuerpo;
protected:
	   virtual bool dropTemplate(Dropeable * dragueable) = 0;
	   virtual Dropeable * dragTemplate(float x, float y) = 0;
public:
	ZonaDragAndDrop(Cuerpo espacio);
	virtual ~ZonaDragAndDrop();
	//retorna true si se hizo cargo de la peticion.
	bool drop(Dropeable * dragueable);
	// crea un dropeable.
	Dropeable * drag(float x, float y);

};

#endif /* ZONADRAGANDDROP_H_ */
