/*
 * EditorUnion.cpp
 *
 *  Created on: 03/10/2013
 *      Author: jonathan
 */

#include "EditorUnion.h"
#include "src/Logger.h"
#include "../../vista/CargadorDeTextures.h"
#include "../../vista/ViewConIcono.h"
#include "../../ConstantesVista.h"
#include "../../vista/objeto/UnionEstaticaView.h"
#include "src/objeto/Union.h"
EditorUnion::EditorUnion(ModeloController * m, ZonaTablero * t, FiguraFactory* factory, int yMaxDrag) :
		SimpleEditorNivel(m, t, factory, yMaxDrag) {
	primerClick = true;
}

EditorUnion::~EditorUnion() {
}

void EditorUnion::clickDown(int x, int y) {
	Transformacion & trans = Resizer::Instance()->getTransformacionToModelo();
	if (primerClick && this->editado->getModelo() != NULL) {
		//si tiene body y es el primer click no hago nada.
		finalizado = true;
		return;
	}
	if (primerClick) {
		trans.setVector(x, y);
		super::clickDown(x, y);
	} else {
		Union * un = (Union *) editado->getModelo();
		Figura* figFinal = modeloController->pickUp(un->getXFinal(), un->getYFinal(), un->getMascaraExtremos());
		trans.setVector(x, y);
		float xf, yf;
		trans.getResultado(xf, yf);
		if (figFinal != NULL && un->isFinValido(figFinal, xf, yf)) {
			un->extraerPosFinal(figFinal, xf, yf);
			bool exitoVista = tablero->agregarFigura(this->editado);
			bool exitoModelo = this->modeloController->crearUnion(un);
			if (!exitoVista || !exitoModelo) {
				//si uno de los dos no tuvo exito nos vamos
				if (exitoVista) {
					tablero->removerFigura(editado);
				}
				if (exitoModelo) {
					modeloController->removerFigura(un);
				}
				Logger log;
				log.info("Punto final de union invalido");
				delete this->editado;
				this->editado = NULL;
				delete un;
			} else {
				this->editado->update();
				this->visor = NULL;
				this->editado = NULL;
			}
		} else {
			Logger log;
			log.info("Punto final de union invalido");
			delete this->editado;
			this->editado = NULL;
			delete un;
		}
		finalizado = true;
	}
}
void EditorUnion::rightClickUp(int x, int y) {
}

void EditorUnion::rightClickDown(int x, int y) {
	if (!dragueando && !finalizado) {
		//TODO NO SE SI HAY Q CHEQUEAR ESTO.
		if (editado->getModelo() != NULL) {
			//la remuevo de todos lados.

			const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
			if (keyboardState[SDL_SCANCODE_LSHIFT]) {
				editado->getModelo()->makeBackUp();
				tablero->removerFigura(editado);
				this->modeloController->removerFigura(editado->getModelo());
				cleanAndDelete();
				return;
			}
		}

	}
}

void EditorUnion::setFigura(FiguraView* f) {
	super::setFigura(f);
	primerClick = true;
}

void EditorUnion::dropear(FiguraView* view, Figura* figura) {
	Logger log;
	// agarro una vista que se banque la edicion de la soga.
	UnionView * vista = ((UnionEstaticaView *) view)->toDinamica();
	delete view;
	figura->setVista(vista);
	vista->setModelo(figura);
	Union * un = (Union *) figura;
	Figura* figInicial = modeloController->pickUp(un->getX(), un->getY(), un->getMascaraExtremos());
	if (figInicial != NULL && un->isInicioValido(figInicial, this->clickDownX, this->clickDownY)) {
		visor = vista;
		editado = vista;
		primerClick = false;
		un->extraerPosInicial(figInicial, this->clickDownX, this->clickDownY);
		un->extraerPosFinal(figInicial, this->clickDownX, this->clickDownY);
		vista->update();
	} else {
		Logger log;
		log.info("Punto inicial de union invalido");
		delete vista;
		delete figura;
		finalizado = true;
	}
}

void EditorUnion::clickUp(int x, int y) {
	if (dragueando) {
		Transformacion & trans = Resizer::Instance()->getTransformacionToModelo();
		trans.setVector(x, y);
		trans.getResultado(this->clickDownX, this->clickDownY);
		this->elementoDrag->drop();
		delete this->elementoDrag;
		this->dragueando = false;
	}
}

void EditorUnion::mouseMotion(int x, int y) {
	if (primerClick) {
		super::mouseMotion(x, y);
	} else {
		Transformacion trans = Resizer::Instance()->getTransformacionToModelo();
		float xf, yf;
		trans.setVector(x, y);
		trans.getResultado(xf, yf);
		Union * un = ((Union *) this->editado->getModelo());
		un->setXFinal(xf);
		un->setYFinal(yf);
		this->editado->update();
	}
}

void EditorUnion::dropNuevaFigura(SogaEstaticaView* view) {
	Resizer* r = Resizer::Instance();
	float x;
	float y;
	r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
	dropear(view, this->figurasFactory->crearSoga(x, 100 - y));
}

void EditorUnion::dropNuevaFigura(CorreaEstaticaView* view) {
	Resizer* r = Resizer::Instance();
	float x;
	float y;
	r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
	dropear(view, this->figurasFactory->crearCorrea(x, 100 - y));
}
