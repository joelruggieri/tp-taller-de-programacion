/*
 * ZonaCreacion.cpp
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#include "ZonaCreacion.h"
#include "../../modelo/Cuadrado.h"
#include "../Resizer.h"
#include "../../vista/Canvas.h"
#include "../../vista/FlechaScrollView.h"
#include "../../vista/CargadorDeTextures.h"
#include "../RutasArchivos.h"
#include "../../ConstantesVista.h"
#include "src/ConstantesComunicacion.h"
#include <iostream>
using namespace std;

namespace CLIENTE {

void ZonaCreacion::crearVista(ViewController* vc) {
	map<string, ConfigFactory> factories;
	factories.insert(pair<string, ConfigFactory>(string(TAG_FACTORY_BALANCIN), ConfigFactory(ID_FACTORY_BALANCIN, TAG_FACTORY_BALANCIN, PATH_VISTA_BALANCIN_F)));
	factories.insert(pair<string, ConfigFactory>(string(TAG_FACTORY_CARRITO), ConfigFactory(ID_FACTORY_CARRITO, TAG_FACTORY_CARRITO, PATH_VISTA_CARRITO)));
	factories.insert(pair<string, ConfigFactory>(string(TAG_FACTORY_BOLA), ConfigFactory(ID_FACTORY_BOLA, TAG_FACTORY_BOLA,	PATH_VISTA_BOLA)));
	factories.insert(pair<string, ConfigFactory>(string(TAG_FACTORY_CINTA), ConfigFactory(ID_FACTORY_CINTA, TAG_FACTORY_CINTA,PATH_VISTA_CINTA)));
	factories.insert(pair<string, ConfigFactory>(string(TAG_FACTORY_CORREA), ConfigFactory(ID_FACTORY_CORREA, TAG_FACTORY_CORREA,PATH_VISTA_CORREA)));
	factories.insert(pair<string, ConfigFactory>(string(TAG_FACTORY_ENGRANAJE),ConfigFactory(ID_FACTORY_ENGRANAJE, TAG_FACTORY_ENGRANAJE,PATH_VISTA_ENGRANAJE)));
	factories.insert(pair<string, ConfigFactory>(string(TAG_FACTORY_GLOBO), ConfigFactory(ID_FACTORY_GLOBO, TAG_FACTORY_GLOBO,PATH_VISTA_GLOBO)));
	factories.insert(pair<string, ConfigFactory>(string(TAG_FACTORY_MOTOR), ConfigFactory(ID_FACTORY_MOTOR, TAG_FACTORY_MOTOR,PATH_VISTA_MOTOR)));
	factories.insert(pair<string, ConfigFactory>(string(TAG_FACTORY_PELOTA), ConfigFactory(ID_FACTORY_PELOTA, TAG_FACTORY_PELOTA,PATH_VISTA_PELOTA)));
	factories.insert(pair<string, ConfigFactory>(string(TAG_FACTORY_SOGA), ConfigFactory(ID_FACTORY_PLATAFORMA, TAG_FACTORY_SOGA,PATH_VISTA_CUERDA)));
	factories.insert(pair<string, ConfigFactory>(string(TAG_FACTORY_PLATAFORMA),ConfigFactory(ID_FACTORY_SOGA, TAG_FACTORY_PLATAFORMA, PATH_VISTA_PLATAFORMA_F)));
	factories.insert(pair<string, ConfigFactory>(string(TAG_FACTORY_YUNQUE),ConfigFactory(ID_FACTORY_YUNQUE, TAG_FACTORY_YUNQUE, PATH_VISTA_YUNQUE)));
	factories.insert(pair<string, ConfigFactory>(string(TAG_FACTORY_CLAVO),ConfigFactory(ID_FACTORY_CLAVO, TAG_FACTORY_CLAVO, PATH_VISTA_CLAVO)));
	factories.insert(pair<string, ConfigFactory>(string(TAG_FACTORY_GANCHO),ConfigFactory(ID_FACTORY_GANCHO, TAG_FACTORY_GANCHO, PATH_VISTA_GANCHO)));
	factories.insert(pair<string, ConfigFactory>(string(TAG_FACTORY_POLEA),ConfigFactory(ID_FACTORY_POLEA, TAG_FACTORY_POLEA, PATH_VISTA_POLEA)));
	CargadorDeTextures * texturas = CargadorDeTextures::Instance();
	SDL_Texture* canvasTexture = texturas->cargarTexture(PATH_FONDO);
	canvasTexture = texturas->cargarTexture(PATH_ZONA_CREACION);
	View * view = new Canvas(110, 40, 20, 80, LAYER_CANVAS_CREACION, canvasTexture);
	vc->addView(ID_CANVAS_CREAC, view);
	view = new ViewConBorde(110, 40, 20, 80);
	vc->addView(ID_BORDE_CANVAS_CREAC, view);
	EslabonCreacion * siguiente = inicioCadena;
	while (siguiente != NULL) {
		std::map<string, ConfigFactory>::iterator it = factories.find(siguiente->getTag());
		if (it != factories.end()) {
			ConfigFactory config = it->second;
			vc->addViewScrolleable(config.id, siguiente->crearView(config.path));
		}
		siguiente = siguiente->getsiguiente();

	}


}

ZonaCreacion::ZonaCreacion(ViewController * vcontroller, list<string> & factoriestags, float x, float margenSuperior,
		ColaEventos * cola) {
	salida = cola;
	scroll = NULL;
	this->inicializar(vcontroller, factoriestags, x, margenSuperior);
	crearVista(vcontroller);
}
void ZonaCreacion::inicializar(ViewController * vcontroller, list<string> & factoriestags, float x,
		float margenSuperior) {
	this->margenSuperior = margenSuperior;
	float ancho = ANCHO_VIEW_DEF * 2;
//	//50% de margen alrededor del panel
	float xInicial = x;
	float yInicial = margenSuperior - ANCHO_VIEW_DEF;

	float y = yInicial - 1;

	std::list<string>::const_iterator iterator;
	this->inicioCadena = NULL;
	this->ultimo = NULL;
//	//por cada tag crea un eslabon.
	for (iterator = factoriestags.begin(); iterator != factoriestags.end(); ++iterator) {
		string msj = "Crea Eslabon en y = ";
		log.concatenar(msj, y);
		log.debug(msj);
		EslabonCreacion* eslabon = new EslabonCreacion(*iterator,
				new Cuadrado(xInicial, y, ANCHO_VIEW_DEF, ANCHO_VIEW_DEF));
		this->agregarEslabon(eslabon);
		y -= DISTANCIA_ENTRE_ELEMENTOS;
	}
	y = factoriestags.size() > 0 ? y + DISTANCIA_ENTRE_ELEMENTOS : y;
	float alto = (margenSuperior - y) + ANCHO_VIEW_DEF;
	//y = margenSuperior -( alto / 2);
	this->cuerpo = new Cuadrado(x, margenSuperior - (alto / 2), ancho, alto);
	//las primeras 100 unidades no tienen scroll, sino lo creo.
	if (alto > ALTO_PANEL_LOG) {
		Cuadrado* cScroll = new Cuadrado(this->cuerpo->getX(), 40, this->cuerpo->getAncho(), ALTO_PANEL_LOG);
		this->scroll = new Scroll(vcontroller, cScroll, 4, alto - ALTO_PANEL_LOG);
	}
}

ZonaCreacion::~ZonaCreacion() {
	delete this->inicioCadena;
	if (this->scroll != NULL) {
		delete this->scroll;
	}
}

void ZonaCreacion::agregarEslabon(EslabonCreacion* eslabon) {
	if (this->inicioCadena == NULL) {
		this->inicioCadena = eslabon;
		this->ultimo = eslabon;
	} else {
		this->ultimo->setSiguiente(eslabon);
		this->ultimo = eslabon;
	}
}

bool ZonaCreacion::click(float x, float y) {
	Cuadrado * cuerpo = scroll != NULL ? scroll->getCuerpo() : this->cuerpo;
//ENTREGA3 CHEQUEAR SI EL SCROLL RETORNA FALSE, IR A UNA FACTORY Y PEDIR EL TAG QUE TIENE PARA PODER ENVIAR EL MSJ AL SERVER.
	if (cuerpo->contacto(x, y)) {
		bool result = scroll == NULL ? false : scroll->click(x, y);
		float corrimientoScroll = scroll == NULL ? 0 : scroll->getScroll();
		if (!result) {
			std::string atender = inicioCadena->atender(x, y, corrimientoScroll);
			if (atender == "") {
				result = false;
			} else {
//				ENTREGA3 ENVIAR MENSAJE CREACION
				CreacionMsj* mje = new CreacionMsj(atender, x, y);
				salida->push(mje);
				cout << "Se clickea en una factory " + atender << endl;
			}
		}
		return result;
	}
	return false;
}
//			}
bool ZonaCreacion::mouseScroll(float x, float y, int amountScrolled) {
	if (this->scroll != NULL) {
		return this->scroll->mouseScroll(x, y, -1*amountScrolled);
	}
	return false;
}

bool ZonaCreacion::clickUp(float float1, float float2) {
	if (!this->cuerpo->contacto(float1, float2)) return false;
		ClickMsj* b = new ClickMsj(float1, float2, false, true, false, false);
		salida->push(b);
		return true;
}


}


