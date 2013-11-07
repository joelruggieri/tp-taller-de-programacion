/*
 * SimpleEditorEstirar.cpp
 *
 *  Created on: 04/10/2013
 *      Author: joel
 */

#include "SimpleEditorEstirar.h"
#include "src/objeto/Estirable.h"
//#include "../../vista/ViewConIcono.h"
#include "../../ConstantesVista.h"
SimpleEditorEstirar::SimpleEditorEstirar(ModeloController * controller, ZonaTablero * zona, FiguraFactory* factory,
		float yMaxDrag) :
		SimpleEditorNivel(controller, zona, factory, yMaxDrag) {
	estirando = false;
}

SimpleEditorEstirar::~SimpleEditorEstirar() {
	// TODO Auto-generated destructor stub
}

void SimpleEditorEstirar::rightClickDown(float x, float y) {
	this->editado->getModelo()->makeBackUp();
	tablero->removerFigura(editado);
	this->modeloController->removerFigura(editado->getModelo());
	ultimoX = x;
	ultimoY = y;
//	const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
	if (this->isCtrl()) {
		estirando = true;
	} else
		super::rightClickDown(x, y);
}

void SimpleEditorEstirar::actualizarAncho(float delta) {
	Estirable* figura = dynamic_cast<Estirable*>(this->editado->getModelo());
	figura->estirar(delta);
}

void SimpleEditorEstirar::mouseMotion(float x, float y) {
//	int posFinalDerecha = this->editado->getXCentro() + (this->editado->getW() / 2);
//	int posFinalIzquierda = this->editado->getXCentro() - (this->editado->getW() / 2);
	float delta;
	if (estirando && !dragueando) {
//		this->actualizarAncho(x - ultimoX);
		Estirable* estirable = dynamic_cast<Estirable*>(this->editado->getModelo());
		Figura* figura = dynamic_cast<Figura*>(this->editado->getModelo());
		if ((x > figura->getX() + (estirable->getAncho() / 2)) || (x > figura->getX())) {
			delta = x - ultimoX;
			this->actualizarAncho(delta);
		} else if ((x < figura->getX() - (estirable->getAncho() / 2))
				|| (x < figura->getX())) {
			delta = ultimoX - x;
			this->actualizarAncho(delta);
		}
		ultimoX = x;
	} else
		super::mouseMotion(x, y);
}

void SimpleEditorEstirar::rightClickUp(float int1, float int2) {
	if (estirando) {
		//tablero->agregarFigura(this->editado);
		//this->modeloController->crearFigura(this->editado->getModelo());
		estirando = false;
//		delete visor;
//		visor = NULL;
		finalizado = true;
		this->actualizarEstadoDeLaFigura(int1, int2);
//		this->editado->update();
	} else
		super::rightClickUp(int1, int2);
}

void SimpleEditorEstirar::dropNuevaFigura(CintaTransportadoraView* view) {
	dropear(view, this->figurasFactory->crearCintaTransportadora(view->getXCentro(), view->getYCentro()));

}

void SimpleEditorEstirar::dropNuevaFigura(PlataformaView* view) {
	dropear(view, this->figurasFactory->crearPlataforma(view->getXCentro(), view->getYCentro()));
}

void SimpleEditorEstirar::setFigura(FiguraView* f) {
	super::setFigura(f);
	estirando = false;
}
