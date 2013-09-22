/*
 * Scroll.h
 *
 *  Created on: 12/09/2013
 *      Author: jonathan
 */

#ifndef SCROLL_H_
#define SCROLL_H_
#include "src/figura/FiguraCompuesta.h"
#include "src/figura/Figura.h"
#include "../vista/View.h"
#include "Observable.h"
#include <map>
#include <list>
using namespace std;

class Scroll : public Observable{

private:
	FiguraCompuesta * figura;
	int velocidad;
	int posicion;
	int max;
	map<Figura*, int> signado;
	list<View*> scrolleables;
	void actualizarVistas(int corrimiento);
	int ultimoClick;
	void desplazarBarra(int sentido);
public:
	Scroll(Figura * flechaSup, Figura* flechaInf,int velocidad, int max);
	virtual ~Scroll();
	bool click(float x, float y);
//	int getScrollPixels();
	float getScroll();
	void addScrolleable(View *);
	int getltimoClick() const;
	bool mouseScroll(float x, float y, int amountScrolled, int xC, int yC, int w, int h);
};

#endif /* SCROLL_H_ */
