/*
 * CorreaView.cpp
 *
 *  Created on: 15/10/2013
 *      Author: joel
 */

#include "CorreaView.h"
#include "../../controller/editor/EditorUnion.h"
#include "src/objeto/Correa.h"
#include "src/mensajes/viewMensaje/ViewObjetoUnionUpdateMsj.h"
#include "src/ConstantesComunicacion.h"
#include <cmath>
#define PI 3.14159265

CorreaView::CorreaView(float x, float y,EditorUnion* editor): UnionView(x, y,editor, OBJ_UNION_S_CORREA) {

}

CorreaView::~CorreaView() {
	// TODO Auto-generated destructor stub
}

EditorNivel* CorreaView::getEditor(){
	EditorUnion * editor = (EditorUnion *)controller;
	editor->setFigura(this);
	return editor;
}

void CorreaView::dropTemplate(){

}


void CorreaView::dibujarse(list<ViewMsj*> & lista){
	Correa* figura = (Correa*) this->getModelo();
	ViewObjetoUnionUpdateMsj* viewMensaje;
	if(figura != NULL)
		viewMensaje = new ViewObjetoUnionUpdateMsj(figura->getXInicial(),figura->getYFinal(),figura->getXFinal(),figura->getYFinal(),this->getId(), this->selector);
	else
		viewMensaje = new ViewObjetoUnionUpdateMsj(this->xDesde,this->yDesde,this->xHasta,this->yHasta,this->getId(), this->selector);
	lista.push_back(viewMensaje);
}


//	SDL_SetRenderDrawColor(renderer,10,10,10,0);
//	SDL_RenderDrawLine(renderer,this->xDesde + v1iX,this->yDesde + v1iY,this->xHasta + v1fX,this->yHasta + v1fY);
//	SDL_RenderDrawLine(renderer,this->xDesde + v2iX,this->yDesde + v2iY,this->xHasta + v2fX,this->yHasta + v2fY);
//	float longitud = 0.9;
//	for (int i = 0; i < 9; ++i) {
//		longitud += 0.01;
//		SDL_RenderDrawLine(renderer,this->xDesde + v1iX *longitud,this->yDesde + v1iY*longitud,this->xHasta + v1fX*longitud,this->yHasta + v1fY*longitud);
//		SDL_RenderDrawLine(renderer,this->xDesde + v2iX*longitud,this->yDesde + v2iY*longitud,this->xHasta + v2fX*longitud,this->yHasta + v2fY*longitud);
//
//	}
//
//	this->dibujarseEstatica(renderer);

//void CorreaView::update(){
//	super::update();
//	double xHastaRespectoXDesde = (float)this->xHasta - (float)this->xDesde;
//	double yHastaRespectoYDesde = (float)this->yHasta - (float)this->yDesde;
//	double norma = sqrt((xHastaRespectoXDesde*xHastaRespectoXDesde) + (yHastaRespectoYDesde*yHastaRespectoYDesde));
//	xHastaRespectoXDesde = xHastaRespectoXDesde / norma;
//	yHastaRespectoYDesde = yHastaRespectoYDesde / norma;
//	//V1o
//	float v1oX = (-yHastaRespectoYDesde);
//	float v1oY = xHastaRespectoXDesde;
//
//	if(this->getModelo() == NULL){
//		 v1iX = v1oX *((float)this->getW()/2);
//		 v1iY = v1oY * ((float)this->getW()/2);
//		 v1fX = v1oX * ((float)this->getW()/2);
//		 v1fY = v1oY * ((float)this->getW()/2);
//	} else {
//		Correa* c = (Correa*)this->getModelo();
//		float radio,foo;
//		tl.setVector(c->getRadioInicial() * 0.8,0.0f);
//		tl.getResultadoInverso(radio,foo);
//		v1iX = v1oX * radio;
//		v1iY = v1oY * radio;
//		tl.setVector(c->getRadioFinal() * 0.8,0.0f);
//		tl.getResultadoInverso(radio,foo);
//		v1fX = v1oX * radio;
//		v1fY = v1oY * radio;
//	}
//	//V2o
//	v2iX = -v1iX;
//	v2iY = -v1iY;
//	v2fX = -v1fX;
//	v2fY = -v1fY;
//
//}
