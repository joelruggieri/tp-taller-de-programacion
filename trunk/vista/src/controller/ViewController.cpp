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
#include "SDL2/SDL.h"
namespace CLIENTE {
bool comparar_layersViews(View * first,	View * second) {
	return first->getLayer() < second->getLayer();
}

ViewController::ViewController(SDL_Renderer * r,int ancho, int alto) {
	this->renderer = r;
	resize(ancho, alto);
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
	vistas.insert(pair<int,View *> (id,v));
	vistasList.push_back(v);
	vistasList.sort(comparar_layersViews);
	unlock();
}

void ViewController::dibujar() {
	Logger log;
	log.debug("Dibujado");
	lock();
	list<View*>::iterator it;
	for(it=vistasList.begin(); it != vistasList.end(); ++it){
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
//	View * viewprueba = new PlataformaView(100,100,100,100,canvasTexture);
	Canvas * canvas = new Canvas(50,50,50,50,canvasTexture);
	addView(ID_CANVAS, canvas);
}

void ViewController::resize(int ancho, int alto) {
	if(tl != NULL){
		delete tl;
	}
	tl= Resizer::crearTransformacionALogica(ancho, alto);
	list<View*>::iterator it;
	lock();
	for(it=vistasList.begin(); it!= vistasList.end(); ++it){
		(*it)->setTl(tl);
		(*it)->resizear();
	}
	unlock();
}

}
