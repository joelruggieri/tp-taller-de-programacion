/*
 * ViewCorreaDinamicaFactory.h
 *
 *  Created on: 16/10/2013
 *      Author: jonathan
 */

#ifndef VIEWCORREADINAMICAFACTORY_H_
#define VIEWCORREADINAMICAFACTORY_H_

#include "ViewFiguraFactory.h"
#include "../editor/EditorUnion.h"
class ViewCorreaDinamicaFactory: public ViewFiguraFactory {
public:
	ViewCorreaDinamicaFactory(EditorUnion *);
	virtual ~ViewCorreaDinamicaFactory();
	FiguraView * crear(float,float,float,float);
	View * crearVistaPropia(float,float,float,float);
};

#endif /* VIEWCORREADINAMICAFACTORY_H_ */
