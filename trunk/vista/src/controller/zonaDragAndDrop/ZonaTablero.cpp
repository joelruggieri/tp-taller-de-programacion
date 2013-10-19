/*
 * ZonaTablero.cpp
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#include "ZonaTablero.h"
#include "../Resizer.h"
#include "src/Logger.h"
#include <src/figura/Figura.h>
//UN CUADRADO DE 100X100 CENTRADO EN X,Y
ZonaTablero::ZonaTablero(float x, float y , SDL_Texture * imagenFondo):Zona(new Cuadrado(x,y,100,100)) {
	Resizer * instance = Resizer::Instance();
	//TODO HARCODEADA LA ALTURA DE LA BARRA DE HERRAMIENTAS
	int xC = instance->resizearDistanciaLogicaX(x);
	int yC =instance->resizearPosicionLogicaY(y);
	int wC = instance->resizearDistanciaLogicaX(100);
	int hC =instance->resizearDistanciaLogicaY(100);
	this->canvas = new Canvas(xC,yC,wC,hC,imagenFondo);
	this->viewCanvas= new ViewConBorde(canvas);
	this->viewCanvas->setAjustarTamanio(false);
}

Canvas* ZonaTablero::getCanvas(){
	return this->canvas;
}

bool ZonaTablero::agregarTemplate(FiguraView* view) {
	Logger log;
	log.info("Recibe figura el tablero");
	if(view->getModelo() == NULL){
		return false;
	}
	view->getModelo()->addObserver(this);
	this->canvas->agregar(view);
	return true;
}

FiguraView * ZonaTablero::getFiguraTemplate(float x, float y) {
	std::list<Dibujable*>::reverse_iterator it;
	FiguraView* result = NULL;
	list<Dibujable*> figuras = canvas->getDibujables();
	FiguraView* actual;
	//TODO ACA SI ANDA MAL HABRÍA QUE HACER UNA DIVISION DE ARBOL PARA IR UBICANDO BINARIO.
	for (it = figuras.rbegin(); it != figuras.rend(); ++it) {
	    actual = (FiguraView*)(*it);
		Figura * c =actual->getModelo();
	    if(c->contacto(x,y)){
	    	result = actual;
	    	break;
	    }
	}
	return result;
}

ZonaTablero::~ZonaTablero() {
	std::list<FiguraView*>::const_iterator iterator;
	delete this->viewCanvas;
}

void ZonaTablero::dibujarse(SDL_Renderer* renderer) {
//	this->canvas->dibujar(renderer);()
	this->viewCanvas->dibujarse(renderer);
}

bool ZonaTablero::removerFigura(FiguraView* figura) {
	int unsigned cantInicial = this->canvas->getDibujables().size();
	if(figura->getModelo() != NULL){
		figura->getModelo()->removeObserver(this);
	}
	this->canvas->remover(figura);
	return cantInicial != this->canvas->getDibujables().size();
}

bool ZonaTablero::click(float x, float y) {
return false;
}

bool ZonaTablero::mouseScroll(float x, float y, int amountScrolled){
	return false;
}

void ZonaTablero::dibujarse(SDL_Renderer* renderer, SDL_Rect&) {
	this->dibujarse(renderer);
}

void ZonaTablero::notifyEvent(ObservableModelo* o, Evento_type t) {
	if(t == DESTRUCCION_FORZADA){
		Figura * fig = (Figura*) o;
		FiguraView * view = (FiguraView *)fig->getVista();
		this->canvas->remover(view);
		delete view;
	}
}

