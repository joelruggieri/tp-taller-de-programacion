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
ZonaCreacion::ZonaCreacion(list<ViewFiguraFactory*> * factories, float x,
		float margenSuperior, SDL_Texture* textura) :
		Zona(NULL) {
	Resizer * instance = Resizer::Instance();
	int xC = instance->resizearDistanciaLogicaX(x);
	int yC = instance->resizearPosicionLogicaY(margenSuperior + ALTO_PANEL/2);
	int wC = instance->resizearDistanciaLogicaX(ANCHO_VIEW_DEF * 2);
	int hC = instance->resizearDistanciaLogicaY(ALTO_PANEL);
	this->canvas = new Canvas(xC, yC, wC, hC, textura);
	this->scroll = NULL;
	this->viewCanvas = new ViewConBorde(canvas);
	this->viewCanvas->setAjustarTamanio(false);
	this->inicializar(factories, x, margenSuperior);
	this->margenSuperior = margenSuperior;
	//TODO HARCODEADA LA ALTURA DE LA BARRA DE HERRAMIENTAS
}
void ZonaCreacion::inicializar(list<ViewFiguraFactory*> * factories, float x,
		float margenSuperior) {
	//TODO ADAPTAR TAMANIO DE LA ZONA SEGUN LA CANTIDAD DE FACTORIES QUE VENGAN.
	float ancho = ANCHO_VIEW_DEF * 2;
	//50% de margen alrededor del panel
	float xInicial = x;
	float yInicial = margenSuperior + ANCHO_VIEW_DEF;
	float y = yInicial + 1;

	std::list<ViewFiguraFactory*>::const_iterator iterator;
	this->inicioCadena = NULL;
	this->ultimo = NULL;
	//por cada mapa crea un eslabon.
	for (iterator = factories->begin(); iterator != factories->end();
			++iterator) {
		EslabonCreacion* eslabon = new EslabonCreacion(*iterator,
				new Cuadrado(xInicial, y, ANCHO_VIEW_DEF, ANCHO_VIEW_DEF),
				1);
		this->agregarEslabon(eslabon);
		this->canvas->agregar(
				new ViewConFondo(new ViewConBorde(eslabon->getFactoryView())));
		y += DISTANCIA_ENTRE_ELEMENTOS;
	}

	y = factories->size() > 0 ? y - DISTANCIA_ENTRE_ELEMENTOS : y;
	float alto = (y - margenSuperior) + ANCHO_VIEW_DEF;
//	y = margenSuperior -( alto / 2);
	this->setCuerpo(
			new Cuadrado(x, margenSuperior + (alto / 2), ancho, alto));
	//las primeras 100 unidades no tienen scroll, sino lo creo.
	if (alto > ALTO_PANEL) {
		Cuadrado* flechaSuperior = new Cuadrado(x, margenSuperior + 2,
				ANCHO_VIEW_DEF * 2, 4);
		Cuadrado* flechaInferior = new Cuadrado(x, margenSuperior + ALTO_PANEL - 2,
				ANCHO_VIEW_DEF * 2, 4);
		this->scroll = new Scroll(flechaSuperior, flechaInferior, 2,
				alto - ALTO_PANEL);
		list<Dibujable *>::iterator it;
		list<Dibujable*> dibujables = this->canvas->getDibujables();
		for (it = dibujables.begin(); it != dibujables.end(); ++it) {
			this->scroll->addScrolleable((View*) (*it));
		}
		//creo la vista del scroll.

		SDL_Texture * texturaFlecha =
				CargadorDeTextures::Instance()->cargarTexture(RUTA_FLECHA);
		canvas->agregar(
				this->crearScrollView(flechaSuperior, flechaInferior,
						this->scroll, texturaFlecha));
	}
}

ScrollView* ZonaCreacion::crearScrollView(Cuadrado* c1, Cuadrado* c2,
		Scroll* scroll, SDL_Texture * texturaFlecha) {
	Resizer * r = Resizer::Instance();
	int x, y, w, h;

	r->adaptarPosicionLogica(c1->getX(), c1->getY(), x, y);
	r->adaptarDimensionLogica(c1->getAncho(), c1->getAlto(), w, h);
	FlechaScrollView * flecha1 = new FlechaScrollView(x, y, w, h, texturaFlecha,
			false);

	r->adaptarPosicionLogica(c2->getX(), c2->getY(), x, y);
	r->adaptarDimensionLogica(c2->getAncho(), c2->getAlto(), w, h);
	FlechaScrollView * flecha2 = new FlechaScrollView(x, y, w, h, texturaFlecha,
			true);

	return new ScrollView(flecha1, flecha2, scroll, SLEEP_BOTONES_SCROLL);

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
	delete this->viewCanvas;
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
//	this->canvas->dibujarse(renderer);
	this->viewCanvas->dibujarse(renderer);
}


void ZonaCreacion::dibujarse(SDL_Renderer* renderer, SDL_Rect&) {
	this->dibujarse(renderer);
}

bool ZonaCreacion::click(float x, float y) {
	if (this->scroll != NULL) {
		return this->scroll->click(x, y);
	}
	return false;
}

bool ZonaCreacion::mouseScroll(float x, float y, int amountScrolled) {
	if (this->scroll != NULL) {
		Cuadrado c(this->getCuerpo()->getX(), (this->margenSuperior + ALTO_PANEL/2),
				ANCHO_VIEW_DEF * 2, ALTO_PANEL);
		if (c.contacto(x,y)) {
			return this->scroll->mouseScroll(x, y, amountScrolled, x, x, x, x);
		}
	}
	return false;
}
