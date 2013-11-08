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
#include "src/mensajes/userEvents/CreacionMsj.h"
#include "src/mensajes/userEvents/ClickMsj.h"
#include <map>
#include <string>
#include "src/Logger.h"
using namespace std;

namespace CLIENTE {
class ConfigFactory {
public:
	string tag;
	string path;
	int id;
public:
	ConfigFactory(int id, string tagCreacion,string textura){
		this->id = id;
		tag= tagCreacion;
		path = textura;
	}
};

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
	float margenSuperior;
	void agregarEslabon(EslabonCreacion* eslabon);
	void crearVista(ViewController * vc);
public:
	ZonaCreacion(ViewController * vcontroller, list<string> & factoriestags, float x, float margenSuperior, ColaEventos * cola);
	virtual ~ZonaCreacion();
	bool click(float x, float y);
	bool mouseScroll(float x, float y, int amountScrolled);
	bool enContacto(float posX, float posY);
	bool clickUp(float x, float y);
};
}
#endif /* ZONACREACION_H_ */
