/*
 * CanvasController.cpp
 *
 *  Created on: Sep 18, 2013
 *      Author: matias
 */

#include "CanvasController.h"
#include "../vista/CargadorDeTextures.h"

using namespace std;

CanvasController::CanvasController(Canvas* canvas) {
	this->canvas = canvas;
}

CanvasController::~CanvasController() {
	// No se borra el canvas asociado.
}

void CanvasController::atenderEvento(SDL_Event &evento){
	CargadorDeTextures* texturas = CargadorDeTextures::Instance();
	string* ruta = static_cast<string*>(evento.user.data1);
	SDL_Texture* nuevaTextura = texturas->cargarTexture(*ruta);
	if (nuevaTextura == NULL) cout<<"Ruta invalida." <<endl;
	else this->canvas->ModificarFondo(nuevaTextura);
	this->ultimaRuta = *ruta;
	delete ruta;
}

void CanvasController::cambiarFondo(string ruta) {
	CargadorDeTextures* texturas = CargadorDeTextures::Instance();
	SDL_Texture* nuevaTextura = texturas->cargarTexture(ruta);
	this->ultimaRuta = ruta;
	this->canvas->ModificarFondo(nuevaTextura);
}

string CanvasController::getRutaFondo() {
	return this->ultimaRuta;
}
