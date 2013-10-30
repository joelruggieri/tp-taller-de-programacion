/*
 * SimpleEditorEstirar.cpp
 *
 *  Created on: 04/10/2013
 *      Author: joel
 */

#include "SimpleEditorEstirar.h"
#include "src/objeto/Estirable.h"
#include "../../vista/CargadorDeTextures.h"
#include "../../vista/ViewConIcono.h"
#include "../../ConstantesVista.h"
SimpleEditorEstirar::SimpleEditorEstirar(ModeloController * controller, ZonaTablero * zona, FiguraFactory* factory,
		int yMaxDrag) :
		SimpleEditorNivel(controller, zona, factory, yMaxDrag) {
	estirando = false;
}

SimpleEditorEstirar::~SimpleEditorEstirar() {
	// TODO Auto-generated destructor stub
}

void SimpleEditorEstirar::rightClickDown(int x, int y) {
	this->editado->getModelo()->makeBackUp();
	tablero->removerFigura(editado);
	this->modeloController->removerFigura(editado->getModelo());
	ultimoX = x;
	ultimoY = y;
	const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
	if (keyboardState[SDL_SCANCODE_LCTRL]) {
		estirando = true;
		CargadorDeTextures* l = CargadorDeTextures::Instance();
		this->visor = new ViewConIcono(editado, l->cargarTexture(PATH_AGRANDAR_IMG), 0);
	} else
		super::rightClickDown(x, y);
}

void SimpleEditorEstirar::actualizarAncho(int delta) {
	Estirable* figura = dynamic_cast<Estirable*>(this->editado->getModelo());
	Resizer* r = Resizer::Instance();
	float wNuevo = 0;
	float hNuevo = 0;
	int aux = 0;
	r->adaptarDimensionPixel(delta, aux, wNuevo, hNuevo);
	figura->estirar(wNuevo);
	this->editado->update();
}

void SimpleEditorEstirar::mouseMotion(int x, int y) {
//	int posFinalDerecha = this->editado->getXCentro() + (this->editado->getW() / 2);
//	int posFinalIzquierda = this->editado->getXCentro() - (this->editado->getW() / 2);
	int delta;
	if (estirando && !dragueando) {
//		this->actualizarAncho(x - ultimoX);

		if ((x > this->editado->getXCentro() + (this->editado->getW() / 2)) || (x > this->editado->getXCentro())) {
			delta = x - ultimoX;
			this->actualizarAncho(delta);
		} else if ((x < this->editado->getXCentro() - (this->editado->getW() / 2))
				|| (x < this->editado->getXCentro())) {
			delta = ultimoX - x;
			this->actualizarAncho(delta);
		}
		ultimoX = x;
	} else
		super::mouseMotion(x, y);
}

void SimpleEditorEstirar::rightClickUp(int int1, int int2) {
	if (estirando) {
		//tablero->agregarFigura(this->editado);
		//this->modeloController->crearFigura(this->editado->getModelo());
		estirando = false;
		delete visor;
		visor = NULL;
		finalizado = true;
		this->actualizarEstadoDeLaFigura(int1, int2);
		this->editado->update();
	} else
		super::rightClickUp(int1, int2);
}

void SimpleEditorEstirar::dropNuevaFigura(CintaTransportadoraView* view) {
	Resizer* r = Resizer::Instance();
	float x;
	float y;
	r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
	dropear(view, this->figurasFactory->crearCintaTransportadora(x, 100 - y));

}

void SimpleEditorEstirar::dropNuevaFigura(PlataformaView* view) {
	Resizer* r = Resizer::Instance();
	float x;
	float y;
	r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
	dropear(view, this->figurasFactory->crearPlataforma(x, 100 - y));
}

void SimpleEditorEstirar::setFigura(FiguraView* f) {
	super::setFigura(f);
	estirando = false;
}