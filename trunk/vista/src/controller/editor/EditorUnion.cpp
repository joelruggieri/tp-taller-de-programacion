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
EditorUnion::EditorUnion(ModeloController * m, ZonaTablero * t,
		FiguraFactory* factory, int yMaxDrag):SimpleEditorNivel(m,t,factory,yMaxDrag) {
	primerClick = true;
}

EditorUnion::~EditorUnion() {
}

void EditorUnion::clickDown(int x, int y) {
	if(primerClick) {
		super::clickDown(x,y);
	} else {
		cout<< "voy por el segundo" << endl;
	}
}


void EditorUnion::rightClickUp(int x, int y) {
}

void EditorUnion::rightClickDown(int x, int y) {
}

void EditorUnion::dibujarEdicion(SDL_Renderer*r) {
	if(primerClick) {
		super::dibujarEdicion(r);
	}
}

void EditorUnion::setFigura(FiguraView* f) {
	super::setFigura(f);
	primerClick = true;
}

void EditorUnion::dropear(FiguraView* view, Figura* figura) {
	Logger log;
//	view->setModelo(figura);
	UnionView * vista = ((UnionEstaticaView *) view)->toDinamica();
	figura->setVista(vista);
	vista->setModelo(figura);
//	Union * un =(Union *) figura;

}
