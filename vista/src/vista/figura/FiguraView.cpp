#include "FiguraView.h"

#include <iostream>
#include "../../controller/DropController.h"
#include "src/Logger.h"
using namespace std;

/********************************************************
 * FIGURAVIEW

 ********************************************************/
Figura* FiguraView::getModelo() {
	return this->modelo;
}

void FiguraView::setModelo(Figura* modelo) {
	this->modelo = modelo;
}

void FiguraView::drop() {
	Logger log;
	std::string mensaje_info;
	if (this->getModelo() != NULL) {
		log.debug("Drop generico de FiguraView");
		//cout<<"llamando al drop generico de figura"<<endl;
		controller->dropFigura(this);
	} else {
		log.debug("Drop especifico de FiguraView");
		//cout<<"llamando al drop especifico de figura"<<endl;
		this->dropTemplate();
	}
}
FiguraView::FiguraView(int x, int y, int w, int h,SDL_Texture* textura,DropController * controller ): View(x,y,w,h) {
	this->modelo = NULL;
	this->textura = textura;
	this->controller = controller;
}

FiguraView::~FiguraView(){

}


void FiguraView::dibujarse(SDL_Renderer * renderer){
	SDL_Rect dest;
	dest.h = this->getH();
	dest.w = this->getW();
	dest.x = this->getX();
	dest.y = this->getY();
	if(this->getModelo() != NULL && this->getModelo()->getRotacion() != 0){
		SDL_RenderCopyEx(renderer,this->textura, NULL, &dest,this->getModelo()->getRotacion(),NULL,SDL_FLIP_NONE);
	} else {
		SDL_RenderCopy(renderer,this->textura,NULL,&dest);

	}
}

void FiguraView::click(float x, float y) {
	this->controller->drag(this,x,y);
}

void FiguraView::resizear() {
	cout << "Se ha hecho resize en un figuraView" << endl ;
}
