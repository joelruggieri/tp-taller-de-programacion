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
#include <map>
#include <list>
using namespace std;

class Scroll {

private:
	FiguraCompuesta * figura;
	int velocidad;
	int posicion;
	int max;
	map<Figura*, int> signado;
	list<View*> scrolleables;
	void actualizarVistas(int corrimiento);
public:
	Scroll(Figura * flechaSup, Figura* flechaInf,int velocidad, int max);
	virtual ~Scroll();
	bool click(float x, float y);
	int getScrollPixels();
	float getScroll();
	void addScrolleable(View *);
};

#endif /* SCROLL_H_ */
