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

void ViewController::receiveEvent(ViewMsj*) {
	lock();
	//ENTREGA3 TIENE QUE RECIBIR EL MENSAJE, TOMAR EL ID OBTENER LA VIEW Y DARLE UPDATE
	//SI NO EXISTE LA VISTA TIENE QUE CREARLA EN LA POSICION QUE DIGA EL MENSAJE.
	unlock();
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
	CargadorDeTextures * texturas = CargadorDeTextures::Instance();
	SDL_Texture* canvasTexture = texturas->cargarTexture(PATH_FONDO);
	View * view = new Canvas(50, 50, 100, 100, canvasTexture);
	addView(ID_CANVAS, view);
	view = new ViewConBorde(50, 50, 100, 100);
	addView(ID_BORDE_CANVAS, view);
	canvasTexture = texturas->cargarTexture(PATH_ZONA_CREACION);
	view = new Canvas(110, 40, 20, 80, canvasTexture);
	addView(ID_CANVAS, view);
	view = new ViewConBorde(110, 40, 20, 80);
	addView(ID_BORDE_CANVAS_CREAC, view);
	SDL_Texture* text1 = texturas->cargarTexture(PATH_BOTON_PLAY);
	SDL_Texture* text2 = texturas->cargarTexture(PATH_BOTON_STOP);
	view = new BotonSwitch(110, 90, 20, 20, text1, text2);
	addView(ID_BOTON_PLAY, view);
	view = new ViewConBorde(110, 90, 20, 20);
	addView(ID_BOTON_PLAY_BORDE, view);
	view = new Canvas(110, 90, 20, 20, canvasTexture);
	addView(ID_BOTON_PLAY_FONDO, view);
	view = new Canvas(60, -10, 120, 20, canvasTexture);
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

}
