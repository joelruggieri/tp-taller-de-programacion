/*
 * CanvasController.cpp
 *
 *  Created on: Sep 18, 2013
 *      Author: matias
 */

#include "CanvasController.h"

using namespace std;

CanvasController::CanvasController(Canvas* canvas) {
	this->canvas = canvas;
}

CanvasController::~CanvasController() {
	// No se borra el canvas asociado.
}

void CanvasController::atenderEvento(SDL_Event evento){
	cout << "Cambiar aca el fondo del canvas" << endl;
}

