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
#include "../../vista/ScrollView.h"
#include "../../vista/CargadorDeTextures.h"
#include "../RutasArchivos.h"
ZonaCreacion::ZonaCreacion(list<ViewFiguraFactory*> * factories, float x,
		float margenSuperior, SDL_Texture* textura) :
		Zona(NULL) {
	Resizer * instance = Resizer::Instance();
	int xC = instance->resizearDistanciaLogicaX(x);
	int yC = instance->resizearDistanciaLogicaY(50);
	int wC = instance->resizearDistanciaLogicaX(ANCHO_VIEW_DEF * 2);
	int hC = instance->resizearDistanciaLogicaY(100);
	this->canvas = new Canvas(xC, yC, wC, hC, textura);
	this->canvas->setBorder(true);
	this->scroll = NULL;
	this->inicializar(factories, x, margenSuperior);
	//TODO HARCODEADA LA ALTURA DE LA BARRA DE HERRAMIENTAS
}
void ZonaCreacion::inicializar(list<ViewFiguraFactory*> * factories, float x,
		float margenSuperior) {
	//TODO ADAPTAR TAMANIO DE LA ZONA SEGUN LA CANTIDAD DE FACTORIES QUE VENGAN.
	float ancho = ANCHO_VIEW_DEF * 2;
	//50% de margen alrededor de todo el panel
	float xInicial = x;
	float yInicial = margenSuperior + ANCHO_VIEW_DEF;
	float y = yInicial + 1;

	std::list<ViewFiguraFactory*>::const_iterator iterator;
	this->inicioCadena = NULL;
	this->ultimo = NULL;
	//por cada factory crea un eslabon.
	for (iterator = factories->begin(); iterator != factories->end();
			++iterator) {
		EslabonCreacion* eslabon = new EslabonCreacion(*iterator,
				new Cuadrado(xInicial, y, ANCHO_VIEW_DEF, ANCHO_VIEW_DEF), 1);
		this->agregarEslabon(eslabon);
		this->canvas->agregar(eslabon->getFactoryView());
		y += 12;
	}

	y = factories->size() > 0 ? y - 12 : y;
	float alto = (y - margenSuperior) + ANCHO_VIEW_DEF;
	this->setCuerpo(new Cuadrado(x, (margenSuperior + alto) / 2, ancho, alto));
	//las primeras 100 unidades no tienen scroll, sino lo creo.
	if (alto > 100) {
		this->scroll = new Scroll(new Cuadrado(x, 2, ANCHO_VIEW_DEF * 2, 4),
				new Cuadrado(x, 98, ANCHO_VIEW_DEF * 2, 4), 2, alto - 100);
		list<Dibujable *>::iterator it;
		list<Dibujable*> dibujables = this->canvas->getDibujables();
		for (it = dibujables.begin(); it != dibujables.end(); ++it) {
			this->scroll->addScrolleable((View*) (*it));
		}
		//creo la vista del scroll.
		Resizer * r = Resizer::Instance();
		SDL_Texture * texturaFlecha =
				CargadorDeTextures::Instance()->cargarTexture(RUTA_FLECHA);
		canvas->agregar(
				new ScrollView(r->resizearDistanciaLogicaX(x),
						r->resizearDistanciaLogicaY(2),
						r->resizearDistanciaLogicaX(ANCHO_VIEW_DEF * 2),
						r->resizearDistanciaLogicaY(4), texturaFlecha));
		canvas->agregar(
				new ScrollView(r->resizearDistanciaLogicaX(x),
						r->resizearDistanciaLogicaY(98),
						r->resizearDistanciaLogicaX(ANCHO_VIEW_DEF * 2),
						r->resizearDistanciaLogicaY(4), texturaFlecha,true));
	}
}
bool ZonaCreacion::agregarTemplate(FiguraView* dragueable) {
	return false;

}

FiguraView * ZonaCreacion::getFiguraTemplate(float x, float y) {
	float corrimiento = 0;
	if (this->scroll != NULL) {
		corrimiento = this->scroll->getScroll();

	}
	return this->inicioCadena->atender(x, y + corrimiento);
}

ZonaCreacion::~ZonaCreacion() {
	delete this->inicioCadena;
	delete this->canvas;
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

void ZonaCreacion::dibujarse(SDL_Renderer* renderer) {
	this->canvas->dibujarse(renderer);
}

bool ZonaCreacion::removerFigura(FiguraView* figura) {
	return false;
}

bool ZonaCreacion::click(float x, float y) {
	if (this->scroll != NULL) {
		return this->scroll->click(x, y);
	}
	return false;
}

