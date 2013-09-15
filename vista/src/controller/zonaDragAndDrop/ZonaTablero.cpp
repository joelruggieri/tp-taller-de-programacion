/*
 * ZonaTablero.cpp
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#include "ZonaTablero.h"
#include "../Resizer.h"
#include "src/AdministradorDeLoggers.h"

//TODO UN CUADRADO DE 100X100 CENTRADO EN X,Y
ZonaTablero::ZonaTablero(Mapa * mapa, float x, float y , SDL_Texture * imagenFondo):Zona(new Cuadrado(x,y,100,100)) {
	this->mapa = mapa;
	Resizer * instance = Resizer::Instance();
	//TODO HARCODEADA LA ALTURA DE LA BARRA DE HERRAMIENTAS
	int xC = instance->resizearDistanciaLogicaX(x);
	int yC =instance->resizearDistanciaLogicaY(y);
	int wC = instance->resizearDistanciaLogicaX(100);
	int hC =instance->resizearDistanciaLogicaY(100);
	this->canvas = new Canvas(xC,yC,wC,hC,imagenFondo);
	this->canvas->setBorder(true);
}

bool ZonaTablero::agregarTemplate(FiguraView* view) {
	Logger &log = AdministradorDeLoggers::getLogger(INFO);
	std::string mensaje_info = "recibe figura tablero";
	log.info(mensaje_info);
	//cout<<"recibe figura tablero"<<endl;
	if(view->getModelo() == NULL){
		return false;
	}
	this->canvas->agregar(view);
//	this->mapa->addFigura(view->getModelo());
	return true;
}

FiguraView * ZonaTablero::getFiguraTemplate(float x, float y) {
	std::list<Dibujable*>::reverse_iterator it;
	FiguraView* result = NULL;
	list<Dibujable*> figuras = canvas->getDibujables();
	FiguraView* actual;
	//TODO ACA SI ANDA MAL HABRÍA QUE HACER UNA DIVISION DE ARBOL PARA IR UBICANDO BINARIO.
	for (it = figuras.rbegin(); it != figuras.rend(); ++it) {
	    actual = (FiguraView*)(*it);
		Figura * c =actual->getModelo();
	    if(c->contacto(x,y)){
	    	result = actual;
	    	break;
	    }
	}
	return result;
}

ZonaTablero::~ZonaTablero() {
	std::list<FiguraView*>::const_iterator iterator;
	delete this->canvas;

	delete this->mapa;
}

void ZonaTablero::dibujarse(SDL_Renderer* renderer) {
	this->canvas->dibujarse(renderer);
}

bool ZonaTablero::removerFigura(FiguraView* figura) {
	int unsigned cantInicial = this->canvas->getDibujables().size();
	this->canvas->remover(figura);
	return cantInicial != this->canvas->getDibujables().size();
}

bool ZonaTablero::click(float x, float y) {
return false;
}
