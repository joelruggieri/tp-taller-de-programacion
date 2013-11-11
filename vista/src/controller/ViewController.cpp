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
#include "viewFactory/ViewObjetoAnchoUpdateFactory.h"
#include "viewFactory/ViewObjetoUnionFactory.h"
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
	addViewPrivado(id, v);
	unlock();
}

void ViewController::dibujar() {
	lock();
	list<View*>::iterator it;
	for (it = vistasList.begin(); it != vistasList.end(); ++it) {
		(*it)->dibujarse(renderer);
	}
	SDL_RenderPresent(renderer);
	unlock();
}

ViewController::~ViewController() {
	delete tl;
}

void ViewController::crearPantalla() {
	CargadorDeTextures * cargador = CargadorDeTextures::Instance(renderer);
	cargador->cargarTexture(PATH_VISTA_BALANCIN);
	cargador->cargarTexture(PATH_VISTA_CORREA);
	cargador->cargarTexture(PATH_VISTA_PLATAFORMA);
	cargador->cargarTexture(PATH_VISTA_GLOBO);
	cargador->cargarTexture(PATH_VISTA_PELOTA);
	cargador->cargarTexture(PATH_VISTA_BOLA);
	cargador->cargarTexture(PATH_VISTA_CINTA);
	cargador->cargarTexture(PATH_VISTA_CINTA_PLATAF);
	cargador->cargarTexture(PATH_VISTA_CUERDA);
	cargador->cargarTexture(PATH_VISTA_ENGRANAJE);
	cargador->cargarTexture(PATH_VISTA_MOTOR);
	cargador->cargarTexture(PATH_EDICION_UNION);
	cargador->cargarTexture(PATH_ERROR_IMG);


	SDL_Texture * text = CargadorDeTextures::Instance()->cargarTexture(
	PATH_ZONA_CREACION);
	View * view = new Canvas(60, -10, 120, 20, 0, text);
	addViewPrivado(ID_CANVAS_RELLENO, view);
	view = new ViewConBorde(60, -10, 120, 20);
	addViewPrivado(ID_BORDE_RELLENO, view);

}

void ViewController::addViewScrolleable(int id, View* v) {
	lock();
	this->addViewPrivado(id,v);
	this->vistasScrolleables.push_back(v);
	unlock();
}

void ViewController::scrollUnidadesLogicas(float unidadesLogicas) {
	lock();
	list<View*>::iterator it;
	View* vista;
	for (it = vistasScrolleables.begin(); it != vistasScrolleables.end();
			++it) {
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

void ViewController::visit(ViewObjetoConAnchoUpdateMsj* mje) {
	lock();
	if (!update(mje)) {
		ViewObjetoAnchoUpdateFactory fac;
		View* view = fac.crear(mje);
		addViewPrivado(mje->getId(), view);
	}
	unlock();
}

void ViewController::visit(ViewObjetoUpdateMsj* mje) {
	lock();
	if (!update(mje)) {
		ViewObjetoSimpleFactory fac;
		View* view = fac.crear(mje);
		addViewPrivado(mje->getId(), view);
	}
	unlock();
}

bool ViewController::update(ViewMsj* mje) {

	bool result = false;
	map<int, View*>::iterator it = vistas.find(mje->getId());
	if (it != vistas.end()) {
		(*it).second->update(mje);
		(*it).second->resizear();
		result = true;
	}
	return result;

}

void ViewController::visit(ViewObjetoUnionUpdateMsj* mje) {
	lock();
	if (!update(mje)) {
		ViewObjetoUnionFactory fac;
		View* view = fac.crear(mje);
		addViewPrivado(mje->getId(), view);
	}
	unlock();
}

View* ViewController::getForUpdate(int id) {
	lock();
	map<int, View*>::iterator it = vistas.find(id);
	if (it == vistas.end()) {
		return NULL;
	}

	return it->second;
}

void ViewController::endUpdate() {
	unlock();
}


void ViewController::addViewPrivado(int id, View*v) {
	cout << "Agregado "<< id << endl;
	vistas.insert(pair<int, View *>(id, v));
	vistasList.push_back(v);
	v->setTl(tl);
	v->resizear();
	vistasList.sort(comparar_layersViews);
}

void ViewController::lock() {
	super::lock();
}

void ViewController::unlock() {
	super::unlock();
}

}
