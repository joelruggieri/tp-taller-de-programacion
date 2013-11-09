/*
 * ViewFiguraFactory.h
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#ifndef VIEWFIGURAFACTORY_H_
#define VIEWFIGURAFACTORY_H_
#include "../../vista/figura/FiguraView.h"
#include "../../vista/FactoryView.h"
#include "../DropController.h"
#include <string>
#include "SDL2/SDL.h"
#include "src/ConstantesComunicacion.h"
using namespace std;

class ViewFiguraFactory {
protected:
	DropController * controller;
	int cantidadDisponible;
public:
	ViewFiguraFactory(DropController * controller, int);
	virtual ~ViewFiguraFactory();
	virtual FiguraView * crear(float,float)=0;
	//TODO ENTREGA3 FALTA IMPLEMENTAR ESTO EN LOS HIJOS, YO LES HICE UN RETURN NULL SOLO PARA QUE BUILDEE
	virtual View * crearVistaPropia(float,float,float,float) = 0;
	float getAlto() const;
	void setAlto(float alto);
	float getAncho() const;
	void setAncho(float ancho);
	virtual string getTagRemoto() = 0;
	FiguraView * crearTemplate(float,float);
	virtual ViewFiguraFactory* clone(int) = 0;

};

#endif /* VIEWFIGURAFACTORY_H_ */
