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
#include "../controller/ViewController.h"
#include <list>
using namespace std;
namespace CLIENTE {
class Scroll : public Observable{

private:
	int velocidad;
	int posicion;
	Cuadrado * sup, *inf;
	int max;
	list<View*> scrolleables;
	ViewController * controller;
	int ultimoClick;
	void desplazarBarra(int sentido);
public:
	Scroll(ViewController * controller, Cuadrado * flechaSup, Cuadrado* flechaInf,int velocidad, int max);
	virtual ~Scroll();
	bool click(float x, float y);
//	int getScrollPixels();
	float getScroll();
	void addScrolleable(View *);
	int getltimoClick() const;
	bool mouseScroll(float x, float y, int amountScrolled, int xC, int yC, int w, int h);
};
}
#endif /* SCROLL_H_ */
