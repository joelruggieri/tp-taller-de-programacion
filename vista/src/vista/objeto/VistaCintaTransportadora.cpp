/*
 * VistaCintaTransportadora.cpp
 *
 *  Created on: 05/10/2013
 *      Author: javier
 */

#include "VistaCintaTransportadora.h"

#include "../../controller/DropController.h"
#include "../../controller/editor/SimpleEditorEstirar.h"
#include "../figura/FiguraView.h"
#include "ObjetoView.h"
#include "../CargadorDeTextures.h"
#include <src/objeto/CintaTransportadora.h>

#define RADTODEG 57.295779513082320876f

VistaCintaTransportadora::VistaCintaTransportadora(int x, int y, int w, int h,
		SDL_Texture* textura, SimpleEditorEstirar* editor) : ObjetoView(x,y,w,h,textura, editor){
//	pieza = CargadorDeTextures::Instance()->cargarTexture("resource/eslabon_cinta.png");
//	rueda = CargadorDeTextures::Instance()->cargarTexture("resource/eje_cinta.png");
}

VistaCintaTransportadora::~VistaCintaTransportadora() {
	// TODO Auto-generated destructor stub
}

void VistaCintaTransportadora::dropTemplate() {
	((SimpleEditorEstirar * )this->controller)->dropNuevaFigura(this);
}


EditorNivel* VistaCintaTransportadora::getEditor() {
	SimpleEditorEstirar * editor = (SimpleEditorEstirar *)controller;
	editor->setFigura(this);
	return editor;
}


//	FiguraView::dibujarse(renderer, dest);
//
//	CintaTransportadora *cinta = (CintaTransportadora*) getModelo();
//	if (!getModelo()) {
//		SDL_RenderCopy(renderer,getTexture(),NULL,&dest);
//	} else {
////		std::vector<SDL_Rect> &marcosPiezas = cinta->getMarcosPiezas();
////		std::vector<float> &angulosPiezas = cinta->getAngulosPiezas();
//
////		SDL_Rect* marcosRuedas = cinta->getMarcosRuedas();
//		float* angulosRuedas = cinta->getAngulosRuedas();
//
////		Resizer * r = Resizer::Instance();
////		r->adaptarDimensionLogica(marcosRuedas[0].x, marcosRuedas[0].y, marcosRuedas[0].x, marcosRuedas[0].y);
////		r->adaptarDimensionLogica(marcosRuedas[0].w, marcosRuedas[0].h, marcosRuedas[0].w, marcosRuedas[0].h);
////		r->adaptarDimensionLogica(marcosRuedas[1].x, marcosRuedas[1].y, marcosRuedas[1].x, marcosRuedas[1].y);
////		r->adaptarDimensionLogica(marcosRuedas[1].w, marcosRuedas[1].h, marcosRuedas[1].w, marcosRuedas[1].h);
//
//		// Ruedas
//		SDL_Rect aux1, aux2, auxRueda1, auxRueda2;
//		aux1 = aux2 = dest;
//		aux1.w = aux2.w = aux1.h = aux2.h = dest.h * 0.20;
//		aux2.x = dest.x + dest.w * 0.75;
//		aux1.y = aux2.y = dest.y + dest.h *0.38;
//		auxRueda1 = aux1;
//		auxRueda2 = aux2;
//		SDL_Rect aux3 = aux1;
//		aux3.x += aux1.w/2;
//		aux3.y += 3;
//		aux3.w = 10;
//		aux3.h = 3;
//		for (; aux3.x < (aux2.x+aux2.w/3); aux3.x += 13){
//			SDL_RenderCopy(renderer,pieza,NULL,&aux3);
//		}
//		aux3.x = aux1.x;
//		aux3.x += aux1.w/2;
//		aux3.y += (aux1.h - aux1.h*0.18);
//		for (; aux3.x < (aux2.x+aux2.w/3); aux3.x += 13){
//			SDL_RenderCopy(renderer,pieza,NULL,&aux3);
//		}
//		dibujarParte(renderer, auxRueda1, -angulosRuedas[0] * RADTODEG, rueda);
//		dibujarParte(renderer, auxRueda2, -angulosRuedas[1] * RADTODEG, rueda);
////		dibujarParte(renderer, marcosRuedas[0], angulosRuedas[0], rueda);
////		dibujarParte(renderer, marcosRuedas[1], angulosRuedas[1], rueda);
//	}


void VistaCintaTransportadora::dibujarParte(SDL_Renderer * renderer, SDL_Rect & dest, float angulo, SDL_Texture* text) {
	SDL_RenderCopyEx(renderer,text, NULL, &dest,angulo,NULL,SDL_FLIP_NONE);
}


void VistaCintaTransportadora::update(){
	super::update();
	float y = 0;
	CintaTransportadora * p = (CintaTransportadora *)this->getModelo();
	tl.setVector(p->getAncho(),y);
	float nuevoAncho;
	tl.getResultadoInverso(nuevoAncho,y);
	this->setW(nuevoAncho);
}
