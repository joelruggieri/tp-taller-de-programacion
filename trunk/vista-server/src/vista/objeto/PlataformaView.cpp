/*
 * PlataformaView.cpp
 *
 *  Created on: 03/10/2013
 *      Author: joel
 */

#include "PlataformaView.h"
#include "../../controller/editor/SimpleEditorEstirar.h"
#include "src/objeto/Plataforma.h"
PlataformaView::PlataformaView(float x, float y, float ancho, SimpleEditorEstirar* editor) :
		ObjetoView(x, y, editor) {
	this->ancho = ancho;
}

PlataformaView::~PlataformaView() {
	// TODO Auto-generated destructor stub
}

void PlataformaView::dropTemplate() {
	((SimpleEditorEstirar *) this->controller)->dropNuevaFigura(this);
}

EditorNivel* PlataformaView::getEditor() {
	SimpleEditorEstirar * editor = (SimpleEditorEstirar *) controller;
	editor->setFigura(this);
	return editor;
}

//void PlataformaView::update(){
//	super::update();
//	float y = 0;
//	Plataforma * p = (Plataforma *)this->getModelo();
//	tl.setVector(p->getAncho(),y);
//	float nuevoAncho;
//	tl.getResultadoInverso(nuevoAncho,y);
//	this->setW(nuevoAncho);
//}

void PlataformaView::dibujarse(list<ViewMsj*> & lista){
	cout << "PLATAFORMA: ";
	if (getModelo() == NULL) {
		cout << getXCentro() << " ";
		cout << getYCentro() << " ";
		cout << this->ancho << endl;
	} else {
		cout << getModelo()->getX() << " ";
		cout << getModelo()->getY() << " ";
		Plataforma * p = (Plataforma *) this->getModelo();
		cout << p->getAncho() << endl;
	}
}
