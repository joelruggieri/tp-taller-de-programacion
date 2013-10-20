/*
 * CorreaView.cpp
 *
 *  Created on: 15/10/2013
 *      Author: joel
 */

#include "CorreaView.h"
#include "../../controller/editor/EditorUnion.h"
#include "src/objeto/Correa.h"
#include <cmath>
#define PI 3.14159265

CorreaView::CorreaView(int x, int y, SDL_Texture * textura,EditorUnion* editor): UnionView(x, y,textura, editor) {

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

double CorreaView::obtenerAnguloEnRadianes(){
	//TODO CORROBORAR QUE NO ESTEN EN EL MISMO x porque tendriamos una division por cero.
	int xHastaRespectoXDesde = this->xHasta - this->xDesde;
	int yHastaRespectoYDesde = this->yHasta - this->xDesde;
	double anguloFinal;
	if(xHastaRespectoXDesde == 0){
		if(yHastaRespectoYDesde > 0)
			anguloFinal = PI/2;
		else
			anguloFinal = -PI/2;
	}else{
		double anguloAuxiliar = atan(yHastaRespectoYDesde/xHastaRespectoXDesde);
		if((anguloAuxiliar < 0) && (yHastaRespectoYDesde < 0)) //cuarto cuadrante
			anguloFinal = (2*PI) - anguloAuxiliar;
		if((anguloAuxiliar < 0) && (yHastaRespectoYDesde > 0)) // segundo cuadrante
			anguloFinal = PI + anguloAuxiliar;
		if((anguloAuxiliar > 0) && (yHastaRespectoYDesde > 0)) //primer cuadrante
			anguloFinal = anguloAuxiliar;
		if((anguloAuxiliar < 0) && (yHastaRespectoYDesde < 0)) //tercer cuadrante
			anguloFinal = PI + anguloAuxiliar;
	}

	return anguloFinal;
}

void CorreaView::proyeccion1(SDL_Renderer* renderer, double angulo){
	double xProyeccionDesde = 0;
	double yProyeccionDesde = 0;
	double yProyeccionHasta = 0;
	double xProyeccionHasta = 0;
	while(sqrt((yProyeccionDesde*yProyeccionDesde) + (xProyeccionDesde*xProyeccionDesde)) < this->getH()){

		xProyeccionHasta ++;
		xProyeccionDesde ++;
		yProyeccionHasta = (tan(angulo)) * xProyeccionHasta;
		yProyeccionDesde = (tan(angulo)) * xProyeccionDesde;
	}
	SDL_RenderDrawLine(renderer,this->xDesde + xProyeccionDesde,this->yDesde + yProyeccionDesde,this->xHasta + xProyeccionHasta,this->yHasta + yProyeccionHasta);

}

void CorreaView::proyeccion2(SDL_Renderer* renderer, double angulo){
	double xProyeccionDesde = 0;
	double yProyeccionDesde = 0;
	double yProyeccionHasta = 0;
	double xProyeccionHasta = 0;
	while(sqrt((yProyeccionDesde*yProyeccionDesde) + (xProyeccionDesde*xProyeccionDesde)) < this->getH()){

		xProyeccionHasta --;
		xProyeccionDesde --;
		yProyeccionHasta = (tan(angulo)) * xProyeccionHasta;
		yProyeccionDesde = (tan(angulo)) * xProyeccionDesde;
	}
	SDL_RenderDrawLine(renderer,this->xDesde + xProyeccionDesde,this->yDesde + yProyeccionDesde,this->xHasta + xProyeccionHasta,this->yHasta + yProyeccionHasta);
	/*if(this->yDesde == this->yHasta){
			SDL_RenderDrawLine(renderer,this->xDesde,this->yDesde + this->getH(),this->xHasta,this->yHasta + this->getH());
			SDL_RenderDrawLine(renderer,this->xDesde,this->yDesde - this->getH(),this->xHasta,this->yHasta - this->getH());
		}else{
			double angulo = this->obtenerAnguloEnRadianes();
			double anguloInvertido = (-1) * angulo;
			this->proyeccion1(renderer,anguloInvertido);
			this->proyeccion2(renderer,anguloInvertido);

		}*/
}

void CorreaView::dibujarse(SDL_Renderer* renderer){
	//super::dibujarse(renderer,10,10,10);
	SDL_SetRenderDrawColor(renderer,10,10,10,0);
	double xHastaRespectoXDesde = (float)this->xHasta - (float)this->xDesde;
	double yHastaRespectoYDesde = (float)this->yHasta - (float)this->yDesde;
	double norma = sqrt((xHastaRespectoXDesde*xHastaRespectoXDesde) + (yHastaRespectoYDesde*yHastaRespectoYDesde));
	xHastaRespectoXDesde = xHastaRespectoXDesde / norma;
	yHastaRespectoYDesde = yHastaRespectoYDesde / norma;
	//V1o
	double v1oX = (-yHastaRespectoYDesde) * ((float)this->getW()/2);
	double v1oY = xHastaRespectoXDesde * ((float)this->getW()/2);
	//V2o
	double v2oX = -v1oX;
	double v2oY = -v1oY;

	SDL_RenderDrawLine(renderer,this->xDesde + v1oX,this->yDesde + v1oY,this->xHasta + v1oX,this->yHasta + v1oY);
	SDL_RenderDrawLine(renderer,this->xDesde + v2oX,this->yDesde + v2oY,this->xHasta + v2oX,this->yHasta + v2oY);

	Union* u = (Union *)this->getModelo();


	if(u->estaEstatica()){
		SDL_Rect dest;
		int wi,hi;
		float xi,yi;
		Resizer::Instance()->adaptarDimensionLogica(u->getRadio()*2,u->getRadio()*2,wi,hi);
		tl.setVector(u->getX(),u->getY());
		tl.getResultadoInverso(xi,yi);
		dest.h = hi;
		dest.w = wi;
		dest.x = xi - wi/2;
		dest.y = yi - hi/2;
		SDL_RenderCopyEx(renderer,this->getTexture(), NULL, &dest,this->getModelo()->getRotacion(),NULL,SDL_FLIP_NONE);
		SDL_RenderCopy(renderer,this->getTexture(),NULL,&dest);
	}
}

