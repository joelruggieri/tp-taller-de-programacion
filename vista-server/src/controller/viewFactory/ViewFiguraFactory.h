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

class ViewFiguraFactory: public Observer {
protected:
	DropController * controller;
	int cantidadDisponible;
	int id;
public:
	ViewFiguraFactory(DropController * controller, int cant, int id);
	virtual ~ViewFiguraFactory();
	virtual FiguraView * crear(float,float)=0;
	virtual string getTagRemoto() = 0;
	FiguraView * crearTemplate(float,float);
	virtual ViewFiguraFactory* clone(int) = 0;
	void notify(Observable*, event_type);
	virtual ViewMsj *  dibujarse(int destinatario);

};

#endif /* VIEWFIGURAFACTORY_H_ */
