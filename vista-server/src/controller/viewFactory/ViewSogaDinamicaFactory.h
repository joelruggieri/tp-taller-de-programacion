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
	ViewSogaDinamicaFactory(EditorUnion *);
	virtual ~ViewSogaDinamicaFactory();
	FiguraView * crear(float,float);
	View * crearVistaPropia();
	string getTagRemoto();
};

#endif /* VIEWSOGADINAMICAFACTORY_H_ */
