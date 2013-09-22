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
#include "../../vista/FlechaScrollView.h"
#include "../../vista/CargadorDeTextures.h"
#include "../RutasArchivos.h"
#include "../../vista/ViewConFondo.h"
ZonaCreacion::ZonaCreacion(list<ViewFiguraFactory*> * factories, float x,
		float margenSuperior, SDL_Texture* textura) :
		Zona(NULL) {
	Resizer * instance = Resizer::Instance();
	int xC = instance->resizearDistanciaLogicaX(x);
	int yC = instance->resizearPosicionLogicaY(70);
	int wC = instance->resizearDistanciaLogicaX(ANCHO_VIEW_DEF * 2);
	int hC = instance->resizearDistanciaLogicaY(100);
	this->canvas = new Canvas(xC, yC, wC, hC, textura);
	this->scroll = NULL;
	this->viewCanvas = new ViewConBorde(canvas);
	this->viewCanvas->setAutoAjustar(true);
	this->inicializar(factories, x, margenSuperior);
	this->margenSuperior = margenSuperior;
	//TODO HARCODEADA LA ALTURA DE LA BARRA DE HERRAMIENTAS
}
void ZonaCreacion::inicializar(list<ViewFiguraFactory*> * factories, float x,
		float margenSuperior) {
	//TODO ADAPTAR TAMANIO DE LA ZONA SEGUN LA CANTIDAD DE FACTORIES QUE VENGAN.
	float ancho = ANCHO_VIEW_DEF * 2;
	//50% de margen alrededor de todo el panel
	float xInicial = x;
	float yInicial = margenSuperior - ANCHO_VIEW_DEF;
	float y = yInicial - 1;

	std::list<ViewFiguraFactory*>::const_iterator iterator;
	this->inicioCadena = NULL;
	this->ultimo = NULL;
	//por cada factory crea un eslabon.
	for (iterator = factories->begin(); iterator != factories->end();
			++iterator) {
		EslabonCreacion* eslabon = new EslabonCreacion(*iterator,
				new Cuadrado(xInicial, y,0, ANCHO_VIEW_DEF, ANCHO_VIEW_DEF), 1);
		this->agregarEslabon(eslabon);
		this->canvas->agregar(new ViewConFondo( new ViewConBorde(eslabon->getFactoryView())));
		y -= 15;
	}

	y = factories->size() > 0 ? y + 15 : y;
	float alto = (margenSuperior -y) + ANCHO_VIEW_DEF;
//	y = margenSuperior -( alto / 2);
	this->setCuerpo(new Cuadrado(x, margenSuperior -( alto / 2),0, ancho, alto));
	//las primeras 100 unidades no tienen scroll, sino lo creo.
	if (alto > 100) {
		this->scroll = new Scroll(new Cuadrado(x, margenSuperior - 2,0, ANCHO_VIEW_DEF * 2, 4),
				new Cuadrado(x, margenSuperior - 98,0, ANCHO_VIEW_DEF * 2, 4), 2, alto - 100);
		list<Dibujable *>::iterator it;
		list<Dibujable*> dibujables = this->canvas->getDibujables();
		for (it = dibujables.begin(); it != dibujables.end(); ++it) {
			this->scroll->addScrolleable((View*) (*it));
		}
		//creo la vista del scroll.

		SDL_Texture * texturaFlecha =
				CargadorDeTextures::Instance()->cargarTexture(RUTA_FLECHA);
		canvas->agregar(this->crearScrollView(x,margenSuperior,this->scroll,texturaFlecha));
	}
}



ScrollView* ZonaCreacion::crearScrollView(int x, int y,Scroll* scroll, SDL_Texture * texturaFlecha) {
	Resizer * r = Resizer::Instance();
	FlechaScrollView * flecha1 = new FlechaScrollView(r->resizearDistanciaLogicaX(x),
			r->resizearPosicionLogicaY(y - 1),
			r->resizearDistanciaLogicaX(ANCHO_VIEW_DEF * 2),
			r->resizearDistanciaLogicaY(4), texturaFlecha);
	FlechaScrollView * flecha2 =new FlechaScrollView(r->resizearDistanciaLogicaX(x),
			r->resizearPosicionLogicaY(y - 99),
			r->resizearDistanciaLogicaX(ANCHO_VIEW_DEF * 2),
			r->resizearDistanciaLogicaY(4), texturaFlecha,true);
	return new ScrollView(flecha1,flecha2,scroll,20);

}

bool ZonaCreacion::agregarTemplate(FiguraView* dragueable) {
	return false;

}

FiguraView * ZonaCreacion::getFiguraTemplate(float x, float y) {
	float corrimiento = 0;
	if (this->scroll != NULL) {
		corrimiento = this->scroll->getScroll();

	}
	return this->inicioCadena->atender(x, y - corrimiento, -1*corrimiento);
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

bool ZonaCreacion::removerFigura(FiguraView* figura) {
	return false;
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

bool ZonaCreacion::mouseScroll(float x, float y, int amountScrolled){
	if (this->scroll != NULL){
		Resizer* r = Resizer::Instance();
		int alto = 100;
		//Normalizo el centro en Y sacando la parte cubierta por el toolBar.
		return this->scroll->mouseScroll(x, y , amountScrolled,
				r->resizearDistanciaPixelX(this->canvas->getXCentro()), (this->margenSuperior+this->margenSuperior - alto) / 2,
				r->resizearDistanciaPixelX(this->canvas->getW()), alto);
	}
	return false;
}
