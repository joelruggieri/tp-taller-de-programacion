/*
 * Zona.h
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#ifndef ZONADRAGANDDROP_H_
#define ZONADRAGANDDROP_H_

#include "src/figura/Figura.h"
#include "src/figura/Cuadrado.h"
#include "../../vista/figura/FiguraView.h"
#include "../../vista/Dibujable.h"
#include <list>
using namespace std;

class Zona: public Dibujable {
private:
	Cuadrado *cuerpo;
	float scrollY;
protected:
	virtual bool agregarTemplate(FiguraView * figura) = 0;
	// clickea en el area y retorna true si hubo alguna accion.
	virtual bool clickTemplate(float x, float y) = 0;
	void setCuerpo(Cuadrado * cuerpo);

public:
	Zona(Cuadrado* cuadrado);
	virtual ~Zona();
	//retorna true si se hizo cargo de la peticion.
	bool agregarFigura(FiguraView*);
	//retorna true si se hizo cargo de la peticion.
	virtual bool removerFigura(FiguraView*) = 0;

	// clickea en el area y retorna true si hubo alguna accion.
	bool click(int, int);
	float getScrollY() const;
	void setScrollY(float);
	list<FiguraView *> getFiguras();
	virtual void dibujarse(SDL_Renderer *) = 0;
	Cuadrado*& getCuerpo();
};

#endif /* ZONADRAGANDDROP_H_ */
