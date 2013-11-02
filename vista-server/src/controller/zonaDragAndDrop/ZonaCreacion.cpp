/*
 * ZonaCreacion.cpp
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#include "ZonaCreacion.h"
#include "../../modelo/Cuadrado.h"
#include "../RutasArchivos.h"
//ENTREGA3 UNIFICAR COORDENADAS CON LAS DEL TABLERO
ZonaCreacion::ZonaCreacion(list<ViewFiguraFactory*> * factories, float x, float margenSuperior) :
		Zona(NULL) {
	this->scroll = NULL;
//	this->viewCanvas->setAjustarTamanio(false);
	this->inicializar(factories, x, margenSuperior);
	this->margenSuperior = margenSuperior;
	//TODO HARCODEADA LA ALTURA DE LA BARRA DE HERRAMIENTAS
}
void ZonaCreacion::inicializar(list<ViewFiguraFactory*> * factories, float x, float margenSuperior) {
	float ancho = ANCHO_VIEW_DEF * 2;
	//50% de margen alrededor del panel
	float xInicial = x;
	float yInicial = margenSuperior + ANCHO_VIEW_DEF;
	float y = yInicial + 1;
	//ENTREGA3 PROBAR ESTO PERO YA DEBERIA ESTAR UNIFICADO CON EL SISTEMA DE COORDENADAS DEL TABLERO
	std::list<ViewFiguraFactory*>::const_iterator iterator;
	this->inicioCadena = NULL;
	this->ultimo = NULL;
	//por cada factory crea un eslabon.
	for (iterator = factories->begin(); iterator != factories->end(); ++iterator) {
		EslabonCreacion* eslabon = new EslabonCreacion(*iterator,
				new Cuadrado(xInicial, y, ANCHO_VIEW_DEF, ANCHO_VIEW_DEF), 1);
		this->agregarEslabon(eslabon);
		this->canvas.push_back(eslabon->getFactoryView());
		y -= DISTANCIA_ENTRE_ELEMENTOS;
	}

	y = factories->size() > 0 ? y + DISTANCIA_ENTRE_ELEMENTOS : y;
	float alto = (margenSuperior -y) + ANCHO_VIEW_DEF;
//	y = margenSuperior -( alto / 2);
	this->setCuerpo(new Cuadrado(x, margenSuperior - (alto / 2), ancho, alto));
	//las primeras 100 unidades no tienen scroll, sino lo creo.
	if (alto > ALTO_PANEL) {
		Cuadrado* flechaSuperior = new Cuadrado(x, margenSuperior - 2, ANCHO_VIEW_DEF * 2, 4);
		Cuadrado* flechaInferior = new Cuadrado(x, margenSuperior - (ALTO_PANEL - 2), ANCHO_VIEW_DEF * 2, 4);
		this->scroll = new Scroll(flechaSuperior, flechaInferior, 4, alto - ALTO_PANEL);
		list<View *>::iterator it;
		for (it = canvas.begin(); it != canvas.end(); ++it) {
			this->scroll->addScrolleable((*it));
		}
		//creo la vista del scroll.

		canvas.push_back(this->crearScrollView(flechaSuperior, flechaInferior, this->scroll));
	}
}

ScrollView* ZonaCreacion::crearScrollView(Cuadrado* c1, Cuadrado* c2, Scroll* scroll) {

	return new ScrollView(scroll, SLEEP_BOTONES_SCROLL);

}

bool ZonaCreacion::agregarTemplate(FiguraView* dragueable) {
	return false;

}

FiguraView * ZonaCreacion::getFiguraTemplate(float x, float y) {
	float corrimiento = 0;
	if (this->scroll != NULL) {
		corrimiento = this->scroll->getScroll();

	}
	return this->inicioCadena->atender(x, y + corrimiento, corrimiento);
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

void ZonaCreacion::dibujarse(list<ViewMsj*> & lista){
	list<View *>::iterator it;
	for (it = canvas.begin(); it != canvas.end(); ++it) {
		(*it)->dibujarse(lista);
	}
}

bool ZonaCreacion::click(float x, float y) {
	if (this->scroll != NULL) {
		return this->scroll->click(x, y);
	}
	return false;
}

bool ZonaCreacion::mouseScroll(float x, float y, int amountScrolled) {
	if (this->scroll != NULL) {
		Cuadrado c(this->getCuerpo()->getX(), (this->margenSuperior + ALTO_PANEL / 2), ANCHO_VIEW_DEF * 2, ALTO_PANEL);
		if (c.contacto(x, y)) {
			return this->scroll->mouseScroll(x, y, amountScrolled, x, x, x, x);
		}
	}
	return false;
}
