/*
 * Scroll.h
 *
 *  Created on: 12/09/2013
 *      Author: jonathan
 */

#ifndef SCROLL_H_
#define SCROLL_H_
#include "Cuadrado.h"
#include "../vista/View.h"
#include "Observable.h"
#include <list>
using namespace std;

class Scroll : public Observable{

private:
	float velocidad;
	float posicion;
	Cuadrado * sup, *inf;
	float max;
	list<View*> scrolleables;
	void actualizarVistas(float corrimiento);
	float ultimoClick;
	void desplazarBarra(float sentido);
public:
	Scroll(Cuadrado * flechaSup, Cuadrado* flechaInf,float velocidad, float max);
	virtual ~Scroll();
	bool click(float x, float y);
//	int getScrollPixels();
	float getScroll();
	void addScrolleable(View *);
	int getltimoClick() const;
	bool mouseScroll(float x, float y, float amountScrolled, float xC, float yC, float w, float h);
};

#endif /* SCROLL_H_ */
