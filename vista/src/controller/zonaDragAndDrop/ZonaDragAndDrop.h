/*
 * ZonaDragAndDrop.h
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#ifndef ZONADRAGANDDROP_H_
#define ZONADRAGANDDROP_H_

#include "src/figura/Cuadrado.h"

#include <list>
using namespace std;

class FiguraView;
class ZonaDragAndDrop {
private:
	Cuadrado *cuerpo;
	float scrollY;
protected:
	   virtual bool dropTemplate(FiguraView * figura) = 0;
	   virtual FiguraView * dragTemplate(float x, float y) = 0;
public:
	ZonaDragAndDrop(Cuadrado* cuadrado);
	virtual ~ZonaDragAndDrop();
	//retorna true si se hizo cargo de la peticion.
	bool drop(FiguraView*);
	// crea una vista.
	FiguraView * drag(float, float);
	float getScrollY() const;
	void setScrollY(float );
	list<FiguraView *> getFiguras();
};

#endif /* ZONADRAGANDDROP_H_ */
