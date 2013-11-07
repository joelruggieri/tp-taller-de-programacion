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
#include "../controller/ViewController.h"
#include "../vista/FlechaScrollView.h"
#include <list>
using namespace std;
namespace CLIENTE {
class Scroll {

private:
	int velocidad;
	int posicion;
	Cuadrado * sup, *inf;
	Cuadrado* cuerpo;
	int max;
	list<View*> scrolleables;
	ViewController * controller;
	int ultimoClick;
	void desplazarBarra(int sentido);
	void crearVista(ViewController * vc);
public:
	Scroll(ViewController * controller,Cuadrado* cuerpo,int velocidad, int max);
	virtual ~Scroll();
	bool click(float x, float y);
//	int getScrollPixels();
	float getScroll();
	void addScrolleable(View *);
	int getltimoClick() const;
	bool mouseScroll(float x, float y, int amountScrolled);
};
}
#endif /* SCROLL_H_ */
