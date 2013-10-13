/*
 * SimpleEditorEstirar.cpp
 *
 *  Created on: 04/10/2013
 *      Author: joel
 */

#include "SimpleEditorEstirar.h"
#include "src/objeto/Plataforma.h"
#include "../../vista/CargadorDeTextures.h"
#include "../../vista/ViewConIcono.h"
#include "../../ConstantesVista.h"
SimpleEditorEstirar::SimpleEditorEstirar(ModeloController * controller , ZonaTablero * zona,FiguraFactory* factory, int yMaxDrag) : SimpleEditorNivel(controller,zona,factory,yMaxDrag) {
	estirando = false;
}

SimpleEditorEstirar::~SimpleEditorEstirar() {
	// TODO Auto-generated destructor stub
}

void SimpleEditorEstirar::rightClickDown(int x, int y){
	this->editado->getModelo()->makeBackUp();
	tablero->removerFigura(editado);
	this->modeloController->removerFigura(editado->getModelo());
	const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
	if (keyboardState[SDL_SCANCODE_LCTRL]) {
		estirando = true;
		CargadorDeTextures* l = CargadorDeTextures::Instance();
		this->visor = new ViewConIcono(editado,
		l->cargarTexture(PATH_AGRANDAR_IMG),0);
	}else
		super::rightClickDown(x,y);
}

void SimpleEditorEstirar::actualizarAncho(int delta){
//

	Figura* figura = (this->editado->getModelo());
	Resizer* r = Resizer::Instance();
	float wNuevo = 0;
	float hNuevo = 0;
	int aux = 0;
	r->adaptarDimensionPixel(delta,aux,wNuevo,hNuevo);
	/*Resizer* r = Resizer::Instance();
	Transformacion trans;
	trans.traslacion(0, 100);
	trans.escalar(r->getRelacionX(), r->getRelacionY());
	trans.invertir(false, true);
	trans.setVector(x, y);
	float lX2, lY2;
	trans.getResultado(lX2, lY2);*/
	figura->agrandar(wNuevo);
	this->editado->setW(r->resizearDistanciaLogicaX(figura->getAncho())); //TODO EN vez de esto hay que usar update de la vista con una transformacion para sacar el metodo getAncho de Figura

}

void SimpleEditorEstirar::mouseMotion(int x, int y) {
	int posFinalDerecha = this->editado->getXCentro() + (this->editado->getW()/2);
	int posFinalIzquierda = this->editado->getXCentro() - (this->editado->getW()/2);
	int delta;

	if (estirando && !dragueando) {
		if((x > this->editado->getXCentro() + (this->editado->getW()/2)) || (x > this->editado->getXCentro())){
			delta = x - posFinalDerecha;
			this->actualizarAncho(delta);
		}
		else if((x < this->editado->getXCentro() - (this->editado->getW()/2)) || (x < this->editado->getXCentro())){
			delta = posFinalIzquierda - x;
			this->actualizarAncho(delta);
		}
	}else
		super::mouseMotion(x,y);
}

void SimpleEditorEstirar::rightClickUp(int int1, int int2) {
	if (estirando) {
		//tablero->agregarFigura(this->editado);
		//this->modeloController->crearFigura(this->editado->getModelo());
		estirando = false;
		delete visor;
		visor = NULL;
		finalizado = true;
		this->actualizarEstadoDeLaFigura(int1,int2);
	}else
		super::rightClickUp(int1,int2);
}

