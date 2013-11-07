/*
 * ZonaCreacion.h
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#ifndef ZONACREACION_H_
#define ZONACREACION_H_

#include "EslabonCreacion.h"
#include "../viewFactory/ViewFiguraFactory.h"
#include <list>
#include "../../vista/Canvas.h"
#include "../../modelo/Scroll.h"
#include "../../vista/ScrollView.h"
#include "../../vista/ViewConBorde.h"
#include "../../modelo/Cuadrado.h"
#include <list>
#include <src/threading/ColaEventos.h>
#include "../../controller/ViewController.h"
#include <map>
#include "src/Logger.h"
using namespace std;

namespace CLIENTE {
class ZonaCreacion {
private:
	Logger log;
	EslabonCreacion * inicioCadena;
	EslabonCreacion * ultimo;
	static const int ANCHO_VIEW_DEF = 10;
	static const int DISTANCIA_ENTRE_ELEMENTOS = 15;
	static const int SLEEP_BOTONES_SCROLL = 10;
	Cuadrado *cuerpo;
	ColaEventos * salida;
	void inicializar(ViewController * vcontroller, list<string> &, float x, float margenSuperior);
	Scroll * scroll;
	ScrollView * crearScrollView(Cuadrado* c1, Cuadrado* c2,Scroll* scroll, SDL_Texture * texturaFlecha);
	float margenSuperior;
	void agregarEslabon(EslabonCreacion* eslabon);
	void crearVista(ViewController * vc);
public:
	ZonaCreacion(ViewController * vcontroller, list<string> & factoriestags, float x, float margenSuperior, ColaEventos * cola);
	virtual ~ZonaCreacion();
	bool click(float x, float y);
	bool mouseScroll(float x, float y, int amountScrolled);
	bool enContacto(float posX, float posY);
};
}
#endif /* ZONACREACION_H_ */
