/*
 * Zona.h
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#ifndef ZONADRAGANDDROP_H_
#define ZONADRAGANDDROP_H_

#include "../../modelo/Cuadrado.h"
#include "../../vista/figura/FiguraView.h"
#include "../../vista/Dibujable.h"
#include <list>
using namespace std;

class Zona: public Dibujable {
private:
	Cuadrado *cuerpo;
protected:
	virtual bool agregarTemplate(FiguraView * figura) = 0;
	// clickea en el area y retorna true si hubo alguna accion.
	virtual FiguraView * getFiguraTemplate(float x, float y) = 0;
	void setCuerpo(Cuadrado * cuerpo);

public:
	Zona(Cuadrado* cuadrado);
	virtual ~Zona();
	//retorna true si se hizo cargo de la peticion.
	bool agregarFigura(FiguraView*);
	//retorna true si se hizo cargo de la peticion.

	// puede estar recibiendo en unidades logicas.
	virtual FiguraView * getVista(float, float);
	virtual void dibujarse(list<ViewMsj*> & lista) = 0;
	Cuadrado*& getCuerpo();
	virtual bool click(float x, float y) = 0;
	virtual bool mouseScroll(float x, float y, int amountScrolled) = 0;
};

#endif /* ZONADRAGANDDROP_H_ */

