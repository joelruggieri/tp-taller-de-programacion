/*
 * ViewController.cpp
 *
 *  Created on: 04/11/2013
 *      Author: jonathan
 */

#include "ViewController.h"

#include "../vista/LayerDibujablesComparator.h"
#include "../ConstantesVista.h"
#include "../vista/CargadorDeTextures.h"
#include "../vista/Canvas.h"
#include "../vista/ViewConBorde.h"
#include "../vista/BotonSwitch.h"
#include "src/mensajes/viewMensaje/ViewObjetoConAnchoUpdateMsj.h"
#include "src/mensajes/viewMensaje/ViewObjetoUnionUpdateMsj.h"
#include "src/mensajes/viewMensaje/ViewObjetoUpdateMsj.h"
#include "viewFactory/ViewObjetoSimpleFactory.h"
#include "SDL2/SDL.h"
namespace CLIENTE {
bool comparar_layersViews(View * first, View * second) {
	return first->getLayer() < second->getLayer();
}

ViewController::ViewController(SDL_Renderer * r, Transformacion * tl) {
	this->renderer = r;
	this->tl = NULL;
	resize(tl);
	crearPantalla();
}


void ViewController::addView(int id, View* v) {
	lock();
	vistas.insert(pair<int, View *>(id, v));
	vistasList.push_back(v);
	v->setTl(tl);
	v->resizear();
	vistasList.sort(comparar_layersViews);
	unlock();
}

void ViewController::dibujar() {
	lock();
	list<View*>::iterator it;
	for (it = vistasList.begin(); it != vistasList.end(); ++it) {
		(*it)->dibujarse(renderer);
	}
	unlock();
	SDL_RenderPresent(renderer);
}

ViewController::~ViewController() {
	delete tl;
}

void ViewController::crearPantalla() {
	CargadorDeTextures::Instance(renderer);
	SDL_Texture * text= CargadorDeTextures::Instance()->cargarTexture(PATH_ZONA_CREACION);
	View * view = new Canvas(60, -10, 120, 20,1, text);
	addView(ID_CANVAS_RELLENO, view);
	view = new ViewConBorde(60, -10, 120, 20);
	addView(ID_BORDE_RELLENO, view);

}

void ViewController::addViewScrolleable(int id, View* v) {
	this->addView(id, v);
	this->vistasScrolleables.push_back(v);
}

void ViewController::scrollUnidadesLogicas(float unidadesLogicas) {
	lock();
	list<View*>::iterator it;
	View* vista;
	for (it = vistasScrolleables.begin(); it != vistasScrolleables.end(); ++it) {
		vista = *it;
		vista->setYL(vista->getYL() + unidadesLogicas);
	}
	unlock();
}

void ViewController::resize(Transformacion * tl) {
	lock();
	if (this->tl != NULL) {
		delete this->tl;
	}
	this->tl = tl;
	list<View*>::iterator it;
	for (it = vistasList.begin(); it != vistasList.end(); ++it) {
		(*it)->setTl(tl);
		(*it)->resizear();
	}
	unlock();
}



void ViewController::visit(ViewObjetoConAnchoUpdateMsj*) {
	lock();
	//ENTREGA3 TIENE QUE RECIBIR EL MENSAJE, TOMAR EL ID OBTENER LA VIEW Y DARLE UPDATE
	//SI NO EXISTE LA VISTA TIENE QUE CREARLA EN LA POSICION QUE DIGA EL MENSAJE.
	unlock();
}

void ViewController::visit(ViewObjetoUpdateMsj* mje) {
	lock();
	if(!update(mje)){
		ViewObjetoSimpleFactory fac;
		View* view = fac.crear(mje);
		addView(mje->getId(), view);
	}
	unlock();
}

bool ViewController::update(ViewMsj*) {
	//ENTREGA3 TIENE QUE RECIBIR EL MENSAJE, TOMAR EL ID OBTENER LA VIEW Y DARLE UPDATE
	//retornar false si no encontró la vista y por eso no pudo actualizarlo, de lo contrario retornar true.
	return false;
}

void ViewController::visit(ViewObjetoUnionUpdateMsj*) {
	lock();
	//ENTREGA3 TIENE QUE RECIBIR EL MENSAJE, TOMAR EL ID OBTENER LA VIEW Y DARLE UPDATE
	//SI NO EXISTE LA VISTA TIENE QUE CREARLA EN LA POSICION QUE DIGA EL MENSAJE.
	unlock();
}

View* ViewController::getForUpdate(int id) {
	lock();
	map<int, View*>::iterator it = vistas.find(id);
	if(it == vistas.end()){
		return NULL;
	}
	return it->second;
}

void ViewController::endUpdate() {
	unlock();
}

}
