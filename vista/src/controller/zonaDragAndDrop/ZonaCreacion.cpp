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
#include "../../vista/ViewConFondo.h"
#include "../../ConstantesVista.h"

namespace CLIENTE {
ZonaCreacion::ZonaCreacion(ViewController * vcontroller, list<string> & factoriestags, float x,
		float margenSuperior, ColaEventos * cola){
	salida  = cola;
	scroll = NULL;
	this->inicializar(vcontroller, factoriestags, x, margenSuperior);
}
void ZonaCreacion::inicializar(ViewController * vcontroller, list<string> & factoriestags, float x,
		float margenSuperior) {
	this->margenSuperior = margenSuperior;
//	//TODO ADAPTAR TAMANIO DE LA ZONA SEGUN LA CANTIDAD DE FACTORIES QUE VENGAN.
	float ancho = ANCHO_VIEW_DEF * 2;
//	//50% de margen alrededor del panel
	float xInicial = x;
	float yInicial = margenSuperior - ANCHO_VIEW_DEF;

	float y = yInicial - 1;

	std::list<string>::const_iterator iterator;
	this->inicioCadena = NULL;
	this->ultimo = NULL;
//	//por cada mapa crea un eslabon.
	for (iterator = factoriestags.begin(); iterator != factoriestags.end();
			++iterator) {
		string msj= "Crea Eslabon en y = ";
		log.concatenar(msj, y);
		log.debug(msj);
		EslabonCreacion* eslabon = new EslabonCreacion(*iterator,
				new Cuadrado(xInicial, y, ANCHO_VIEW_DEF, ANCHO_VIEW_DEF));
		this->agregarEslabon(eslabon);
//		this->canvas->agregar(
//				new ViewConFondo(new ViewConBorde(eslabon->getFactoryView())));
		y -= DISTANCIA_ENTRE_ELEMENTOS;
	}
//
	y = factoriestags.size() > 0 ? y + DISTANCIA_ENTRE_ELEMENTOS : y;
	float alto = (margenSuperior - y) + ANCHO_VIEW_DEF;
	//y = margenSuperior -( alto / 2);
	this->cuerpo= new Cuadrado(x, margenSuperior - (alto / 2), ancho, alto);
	//las primeras 100 unidades no tienen scroll, sino lo creo.
	if (alto > ALTO_PANEL_LOG) {
		log.debug("Se crea scroll");
		string msj = "Fecha Superior en ";
		log.concatenar(msj, margenSuperior - 2);
		log.debug(msj);
		Cuadrado* flechaSuperior = new Cuadrado(x, margenSuperior - 2,
				ANCHO_VIEW_DEF * 2, 4);
		msj = "Fecha Inferior en ";
		log.concatenar(msj, margenSuperior - ALTO_PANEL_LOG + 2);
		log.debug(msj);
		Cuadrado* flechaInferior = new Cuadrado(x, margenSuperior - ALTO_PANEL_LOG + 2,
				ANCHO_VIEW_DEF * 2, 4);
		this->scroll = new Scroll(vcontroller,flechaSuperior, flechaInferior, 4,
				alto - ALTO_PANEL_LOG);
	//	list<Dibujable *>::iterator it;
//		list<Dibujable*> dibujables = this->canvas->getDibujables();
//		for (it = dibujables.begin(); it != dibujables.end(); ++it) {
//			this->scroll->addScrolleable((View*) (*it));
//		}
		//creo la vista del scroll.

//		SDL_Texture * texturaFlecha =
//				CargadorDeTextures::Instance()->cargarTexture(RUTA_FLECHA);
//		canvas->agregar(
//				this->crearScrollView(flechaSuperior, flechaInferior,
//						this->scroll, texturaFlecha));
	}
}

ScrollView* ZonaCreacion::crearScrollView(Cuadrado* c1, Cuadrado* c2,
		Scroll* scroll, SDL_Texture * texturaFlecha) {
//	Resizer * r = Resizer::Instance();
//	int x, y, w, h;
//
//	r->adaptarPosicionLogica(c1->getX(), c1->getY(), x, y);
//	r->adaptarDimensionLogica(c1->getAncho(), c1->getAlto(), w, h);
//	FlechaScrollView * flecha1 = new FlechaScrollView(x, y, w, h, texturaFlecha,
//			false);
//
//	r->adaptarPosicionLogica(c2->getX(), c2->getY(), x, y);
//	r->adaptarDimensionLogica(c2->getAncho(), c2->getAlto(), w, h);
//	FlechaScrollView * flecha2 = new FlechaScrollView(x, y, w, h, texturaFlecha,
//			true);
//
//	return new ScrollView(flecha1, flecha2, scroll, SLEEP_BOTONES_SCROLL);
	return NULL;


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

//	inicioCadena->atender(x,y);


	//ENTREGA3 CHEQUEAR SI EL SCROLL RETORNA FALSE, IR A UNA FACTORY Y PEDIR EL TAG QUE TIENE PARA PODER ENVIAR EL MSJ AL SERVER.
//	float corrimiento = 0;
//	if (this->scroll != NULL) {
//		corrimiento = this->scroll->getScroll();
//
//	}
//	return this->inicioCadena->atender(x, y + corrimiento, corrimiento);
	if (this->scroll != NULL) {
		return this->scroll->click(x, y);
	}
	return false;
}

bool ZonaCreacion::mouseScroll(float x, float y, int amountScrolled) {
	if (this->scroll != NULL) {
		Cuadrado c(cuerpo->getX(), (this->margenSuperior + ALTO_PANEL_LOG/2),
				ANCHO_VIEW_DEF * 2, ALTO_PANEL_LOG);
		if (c.contacto(x,y)) {
			return this->scroll->mouseScroll(x, y, amountScrolled, x, x, x, x);
		}
	}
	return false;
}
}
