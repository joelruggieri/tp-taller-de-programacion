/*
 * ViewPelotaFactory.h
 *
 *  Created on: 20/09/2013
 *      Author: joel
 */

#ifndef VIEWPELOTAFACTORY_H_
#define VIEWPELOTAFACTORY_H_
#include "ViewFiguraFactory.h"

class ViewPelotaFactory: public ViewFiguraFactory {
public:
	ViewPelotaFactory(DropController* controller);
	virtual ~ViewPelotaFactory();
	FiguraView * crear(int,int,int,int);
	View * crearVistaPropia(int,int,int,int);

};

#endif /* VIEWPELOTAFACTORY_H_ */
