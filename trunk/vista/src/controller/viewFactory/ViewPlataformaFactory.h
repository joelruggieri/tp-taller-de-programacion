/*
 * ViewPlataformaFactory.h
 *
 *  Created on: 03/10/2013
 *      Author: joel
 */

#ifndef VIEWPLATAFORMAFACTORY_H_
#define VIEWPLATAFORMAFACTORY_H_
#include "ViewFiguraFactory.h"
#include "../editor/SimpleEditorNivel.h"

class ViewPlataformaFactory: public ViewFiguraFactory{
private:
	SimpleEditorNivel * editor;
public:
	ViewPlataformaFactory(SimpleEditorNivel * editor);
	virtual ~ViewPlataformaFactory();
	FiguraView * crear(int, int, int, int);
	View * crearVistaPropia(int,int,int,int);
};

#endif /* VIEWPLATAFORMAFACTORY_H_ */
