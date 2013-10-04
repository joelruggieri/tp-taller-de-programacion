/*
 * ViewPelotaFactory.h
 *
 *  Created on: 20/09/2013
 *      Author: joel
 */

#ifndef VIEWPELOTAFACTORY_H_
#define VIEWPELOTAFACTORY_H_
#include "ViewFiguraFactory.h"
#include "../editor/SimpleEditorNivel.h"
class ViewPelotaFactory: public ViewFiguraFactory {
private:
	SimpleEditorNivel * editor;
public:
	ViewPelotaFactory(DropController* controller, SimpleEditorNivel * editor);
	virtual ~ViewPelotaFactory();
	FiguraView * crear(int,int,int,int);
	View * crearVistaPropia(int,int,int,int);

};

#endif /* VIEWPELOTAFACTORY_H_ */
