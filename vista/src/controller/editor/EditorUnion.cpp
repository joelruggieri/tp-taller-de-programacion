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
EditorUnion::EditorUnion(ModeloController * m, ZonaTablero * t,
		FiguraFactory* factory, int yMaxDrag) :
		SimpleEditorNivel(m, t, factory, yMaxDrag) {
	primerClick = true;
}

EditorUnion::~EditorUnion() {
}

void EditorUnion::clickDown(int x, int y) {
	if (primerClick) {
		super::clickDown(x, y);
	} else {
		Union * un = (Union *) editado->getModelo();
		Figura* figFinal = modeloController->pickUp(un->getXFinal(),
				un->getYFinal());
		if (figFinal != NULL && un->isExtremoValido(figFinal)) {
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
				Resizer*r = Resizer::Instance();
				Transformacion trans;
				trans.traslacion(0, 100);
				trans.escalar(r->getRelacionX(), r->getRelacionY());
				trans.invertir(false, true);
				 this->editado->update(trans);
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
	Figura* figInicial = modeloController->pickUp(un->getX(), un->getY());
	if (figInicial != NULL && un->isExtremoValido(figInicial)) {
		visor = vista;
		editado = vista;
		primerClick = false;
		Resizer*r = Resizer::Instance();
		Transformacion trans;
		trans.traslacion(0, 100);
		trans.escalar(r->getRelacionX(), r->getRelacionY());
		trans.invertir(false, true);
		un->setXInicial(figInicial->getX());
		un->setYInicial(figInicial->getY());
		un->setXFinal(figInicial->getX());
		un->setYFinal(figInicial->getY());

//		un->setFin(figInicial->getX(), figInicial->getY());
		vista->update(trans);
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
		this->elementoDrag->drop();
		delete this->elementoDrag;
		this->dragueando = false;
	}
}

void EditorUnion::mouseMotion(int x, int y) {
	if (primerClick) {
		super::mouseMotion(x, y);
	} else {
		Resizer*r = Resizer::Instance();
		Transformacion trans;
		trans.traslacion(0, 100);
		trans.escalar(r->getRelacionX(), r->getRelacionY());
		trans.invertir(false, true);
		float xf, yf;
		trans.setVector(x, y);
		trans.getResultado(xf, yf);
		Union * un =((Union *) this->editado->getModelo());
		un->setXFinal(xf);
		un->setYFinal(yf);
		this->editado->update(trans);
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
