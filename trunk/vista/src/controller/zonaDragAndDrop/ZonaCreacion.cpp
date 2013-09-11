/*
 * ZonaCreacion.cpp
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#include "ZonaCreacion.h"
#include "src/figura/Cuadrado.h"
#include "../Resizer.h"
#include "../../vista/Canvas.h"

ZonaCreacion::ZonaCreacion(list<ViewFiguraFactory*> * factories, float x, float margenSuperior, SDL_Texture* textura) :
		Zona(NULL) {
	Resizer * instance = Resizer::Instance();
	int xC = instance->resizearDistanciaLogicaX(x);
	int yC =instance->resizearDistanciaLogicaY(50);
	int wC = instance->resizearDistanciaLogicaX(ANCHO_VIEW_DEF *2);
	int hC =instance->resizearDistanciaLogicaY(100);
	this->canvas = new Canvas(xC,yC,wC,hC,textura);
	this->canvas->setBorder(true);

	this->inicializar(factories, x, margenSuperior);
	//TODO HARCODEADA LA ALTURA DE LA BARRA DE HERRAMIENTAS
}
void ZonaCreacion::inicializar(list<ViewFiguraFactory*> * factories, float x, float margenSuperior) {
	//TODO ADAPTAR TAMANIO DE LA ZONA SEGUN LA CANTIDAD DE FACTORIES QUE VENGAN.
	float ancho = ANCHO_VIEW_DEF *2;
	//50% de margen alrededor de todo el panel
	float xInicial = x;
	float yInicial = margenSuperior +  ANCHO_VIEW_DEF ;
	float y = yInicial;

	std::list<ViewFiguraFactory*>::const_iterator iterator;
	this->inicioCadena = NULL;
	this->ultimo = NULL;
	//por cada factory crea un eslabon.
	for (iterator = factories->begin(); iterator != factories->end(); ++iterator) {
		EslabonCreacion* eslabon = new EslabonCreacion(*iterator,
				new Cuadrado(xInicial, y, ANCHO_VIEW_DEF, ANCHO_VIEW_DEF), 1);
		this->agregarEslabon(eslabon);
		this->canvas->agregar(eslabon->getFactoryView());
		y += 12;
	}

	y = factories->size() > 0 ? y-12: y;
	float alto = (y - margenSuperior) + ANCHO_VIEW_DEF;
	this->setCuerpo(new Cuadrado(x,(margenSuperior + alto) / 2, ancho, alto));

}
bool ZonaCreacion::agregarTemplate(FiguraView* dragueable) {
	return false;

}

bool ZonaCreacion::clickTemplate(float x, float y) {
	return this->inicioCadena->atender(x, y);
}

ZonaCreacion::~ZonaCreacion() {
	delete this->inicioCadena;
	delete this->canvas;
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

void ZonaCreacion::dibujarse(SDL_Renderer* renderer) {
	this->canvas->dibujarse(renderer);
}

bool ZonaCreacion::removerFigura(FiguraView* figura) {
	return false;
}
