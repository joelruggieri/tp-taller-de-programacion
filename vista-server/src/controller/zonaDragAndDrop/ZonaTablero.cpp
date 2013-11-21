/*
 * ZonaTablero.cpp
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#include "ZonaTablero.h"
#include "src/Logger.h"
#include <src/figura/Figura.h>
//UN CUADRADO DE 100X100 CENTRADO EN X,Y
ZonaTablero::ZonaTablero(float x, float y):Zona(new Cuadrado(x,y,100,100)) {
	//TODO HARCODEADA LA ALTURA DE LA BARRA DE HERRAMIENTAS
}

FiguraView * ZonaTablero::getVista(float x, float y) {
	FiguraView * drop  = NULL;
	if (this->cuerpo->contacto(x, y)) {
		drop = this->getFiguraTemplate(x,y);
	}
	return drop;
}


FiguraView * ZonaTablero::getFiguraTemplate(float x, float y) {
	std::list<View*>::reverse_iterator it;
	FiguraView* result = NULL;
	FiguraView* actual;
	for (it = canvas.rbegin(); it != canvas.rend(); ++it) {
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
}

void ZonaTablero::dibujarse(list<ViewMsj*> & lista){
//	this->canvas->dibujar(renderer);()
	list<View*>::iterator it;
	for (it = this->canvas.begin(); it != this->canvas.end(); ++it) {
		(*it)->dibujarse(lista);
	}
}

bool ZonaTablero::removerFigura(FiguraView* figura) {
	int unsigned cantInicial = this->canvas.size();
	if(figura->getModelo() != NULL){
		figura->getModelo()->removeObserver(this);
	}
	this->canvas.remove(figura);
	return cantInicial != this->canvas.size();
}

bool ZonaTablero::click(float x, float y) {
return false;
}

bool ZonaTablero::mouseScroll(float x, float y, int amountScrolled){
	return false;
}


void ZonaTablero::notifyEvent(ObservableModelo* o, Evento_type t) {
	if(t == DESTRUCCION_FORZADA){
		Figura * fig = (Figura*) o;
		FiguraView * view = (FiguraView *)fig->getVista();
		if(this->remover(view)){
			delete view;
		}
	}
}
bool ZonaTablero::remover(View* vista) {
	int cant = this->canvas.size();
	this->canvas.remove(vista);
	int cantNueva= this->canvas.size();
	return cant > cantNueva;
}

bool ZonaTablero::agregarFigura(FiguraView* view) {
	if (this->cuerpo->contieneCentro(view->getModelo())) {
			Logger log;
			log.info("Recibe figura el tablero");
			if(view->getModelo() == NULL){
				return false;
			}
			view->getModelo()->addObserver(this);
			this->canvas.push_back(view);
			return true;
	}
	return false;
}
