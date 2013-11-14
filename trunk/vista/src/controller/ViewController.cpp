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
#include "src/mensajes/viewMensaje/FinDibujado.h"
#include "viewFactory/ViewObjetoSimpleFactory.h"
#include "viewFactory/ViewObjetoAnchoUpdateFactory.h"
#include "viewFactory/ViewObjetoUnionFactory.h"
#include "SDL2/SDL.h"
#include <set>

static const int ID_NO_HIGHLIGHT = -20;

namespace CLIENTE {
bool comparar_layersViews(View * first, View * second) {
	return first->getLayer() < second->getLayer();
}

ViewController::ViewController(SDL_Renderer * r, Transformacion * tl,
		Cuadrado cuadradoArea) {
	this->renderer = r;
	this->tl = NULL;
	resize(tl);
	crearPantalla();
	addView(ID_AREA,
			new AreaView(cuadradoArea.getX(), cuadradoArea.getY(),
					cuadradoArea.getAncho(), cuadradoArea.getAlto(),
					CargadorDeTextures::Instance()->cargarTexture(
					PATH_VISTA_AREA)));
	highlightsActual = ID_NO_HIGHLIGHT;
	highlightsAnterior = ID_NO_HIGHLIGHT;
	ordenar = false;
	huboHighLighT = false;
}

void ViewController::addView(int id, View* v) {
	lock();
	addViewPrivado(id, v);
	unlock();
}

void ViewController::dibujar() {
	lock();
	if(ordenar){
		vistasList.sort(comparar_layersViews);
		ordenar = false;
	}
	list<View*>::iterator it;
	for (it = vistasList.begin(); it != vistasList.end(); ++it) {
		(*it)->dibujarse(renderer);
	}
//	this->areaVista->dibujarse(renderer);
	SDL_RenderPresent(renderer);
	unlock();
}

ViewController::~ViewController() {
	delete tl;
	//delete areaVista;
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
	cargador->cargarTexture(PATH_VISTA_YUNQUE);
	cargador->cargarTexture(PATH_VISTA_GANCHO);
	cargador->cargarTexture(PATH_EDICION_UNION);
	cargador->cargarTexture(PATH_ERROR_IMG);

	SDL_Texture * text = CargadorDeTextures::Instance()->cargarTexture(
	PATH_ZONA_CREACION);
	View * view = new Canvas(60, -10, 120, 20, LAYER_CANVAS_RELLENO, text);
	addViewPrivado(ID_CANVAS_RELLENO, view);
	view = new ViewConBorde(60, -10, 120, 20);
	addViewPrivado(ID_BORDE_RELLENO, view);

}

void ViewController::addViewScrolleable(int id, View* v) {
	lock();
	this->addViewPrivado(id, v);
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
//	this->areaVista->setTl(tl);
//	this->areaVista->resizear();
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
		(*it).second->markUpdated();
		result = true;
	}
//	this->areaVista->resizear();
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
	vistas.insert(pair<int, View *>(id, v));
	vistasList.push_back(v);
	v->setTl(tl);
	v->resizear();
	v->setId(id);
	ordenar = true;
}

void ViewController::lock() {
	super::lock();
}

void ViewController::unlock() {
	super::unlock();
}
void ViewController::generarVistaArea(float x, float y, float w, float h) {
	this->areaVista = new AreaView(x, y, w, h,
			CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_AREA));
}

void ViewController::visit(FinDibujado* m) {
	lock();
	View* elemento;
	map<int, View*>::iterator it;
	for (std::list<View*>::iterator i = vistasList.begin();
			i != vistasList.end();) {
		if (!(*i)->isUpdated()) {
			elemento = *i;
			vistasList.erase(i++);
			it = vistas.find(elemento->getId());
			vistas.erase(it); // advance before iterator become invalid
		} else {
			(*i)->invalidate();
			++i;
		}
	}

	if(huboHighLighT){
		if(highlightsActual != highlightsAnterior){
			it = vistas.find(highlightsAnterior);
			if(it != vistas.end()){
				(*it).second->higlight(false);
			}
			it = vistas.find(highlightsActual);
			if(it != vistas.end()){
				(*it).second->higlight(true);
			}
			highlightsAnterior = highlightsActual;
			ordenar= true;
		}
	} else {
		if(highlightsAnterior != ID_NO_HIGHLIGHT){
			it = vistas.find(highlightsAnterior);
			if(it != vistas.end()){
				(*it).second->higlight(false);
				ordenar = true;
			}
		}
		highlightsActual = ID_NO_HIGHLIGHT;
		highlightsAnterior = highlightsActual;
	}
	huboHighLighT = false;
	unlock();
}

void ViewController::visit(ViewBotonStartMsj* m) {
	lock();
	update(m);
	unlock();
}

void ViewController::visit(Highlight* h) {
	lock();
	highlightsActual = h->getId();
	huboHighLighT = true;
//	if(highlightsActual != highlightsAnterior){
//			std::map<int, View*>::iterator it = vistas.find(h->getId());
//			if (it != vistas.end()) {
//				it->second->higlight(true);
//			}
//	}
	unlock();
}

}
