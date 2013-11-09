/*
 * ViewSogaDinamicaFactory.h
 *
 *  Created on: 18/10/2013
 *      Author: jonathan
 */

#ifndef VIEWSOGADINAMICAFACTORY_H_
#define VIEWSOGADINAMICAFACTORY_H_

#include "ViewFiguraFactory.h"
#include "../editor/EditorUnion.h"
class ViewSogaDinamicaFactory: public ViewFiguraFactory {
public:
	ViewSogaDinamicaFactory(EditorUnion *, int cantidad);
	virtual ~ViewSogaDinamicaFactory();
	FiguraView * crear(float,float);
	View * crearVistaPropia();
	string getTagRemoto();
	ViewFiguraFactory* clone(int);
	View * crearVistaPropia(float,float,float,float);
};

#endif /* VIEWSOGADINAMICAFACTORY_H_ */
