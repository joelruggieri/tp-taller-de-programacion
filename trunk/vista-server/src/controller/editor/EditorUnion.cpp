/*
 * EditorUnion.cpp
 *
 *  Created on: 03/10/2013
 *      Author: jonathan
 */

#include "EditorUnion.h"
#include "src/Logger.h"
#include "../../ConstantesVista.h"
#include "../../vista/objeto/UnionEstaticaView.h"
#include "src/objeto/Union.h"
EditorUnion::EditorUnion(ModeloController * m, ZonaTablero * t, FiguraFactory* factory, int yMaxDrag) :
		SimpleEditorNivel(m, t, factory, yMaxDrag) {
	primerClick = true;
}

EditorUnion::~EditorUnion() {
}

void EditorUnion::clickDown(float x, float y) {
	if (primerClick && this->editado->getModelo() != NULL) {
		//si tiene body y es el primer click no hago nada.
		finalizado = true;
		return;
	}
	if (primerClick) {
		super::clickDown(x, y);
	} else {
		Union * un = (Union *) editado->getModelo();
		Figura* figFinal = modeloController->pickUp(un->getXFinal(), un->getYFinal(), un->getMascaraExtremos());
		if (figFinal != NULL && un->isFinValido(figFinal, x, y)) {
			un->extraerPosFinal(figFinal, x, y);
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
//				this->editado->update();
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
void EditorUnion::rightClickUp(float x, float y) {
}

void EditorUnion::rightClickDown(float x, float y) {
	if (!dragueando && !finalizado) {
		//TODO NO SE SI HAY Q CHEQUEAR ESTO.
		if (editado->getModelo() != NULL) {
			//la remuevo de todos lados.

//			const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
			if (this->isShift()) {
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
		editado = vista;
		primerClick = false;
		un->extraerPosInicial(figInicial, this->clickDownX, this->clickDownY);
		un->extraerPosFinal(figInicial, this->clickDownX, this->clickDownY);
//		vista->update();
	} else {
		Logger log;
		log.info("Punto inicial de union invalido");
		delete vista;
		delete figura;
		finalizado = true;
	}
}

void EditorUnion::clickUp(float x, float y) {
	if (dragueando) {
		this->clickDownX=x;
		this->clickDownY=y;
		this->elementoDrag->drop();
		delete this->elementoDrag;
		this->dragueando = false;
	}
}

void EditorUnion::mouseMotion(float x, float y) {
	if (primerClick) {
		super::mouseMotion(x, y);
	} else {
		Union * un = ((Union *) this->editado->getModelo());
		un->setXFinal(x);
		un->setYFinal(y);
		un->calcularCentroCuadrado();
//		this->editado->update();
	}
}

void EditorUnion::dropNuevaFigura(SogaEstaticaView* view) {
	dropear(view, this->figurasFactory->crearSoga(view->getXCentro(), view->getYCentro(),this->numeroJugadorDuenio));
}

void EditorUnion::dropNuevaFigura(CorreaEstaticaView* view) {
	dropear(view, this->figurasFactory->crearCorrea(view->getXCentro(), view->getYCentro(), this->numeroJugadorDuenio));
}
