/*
 * ViewPlataformaFactory.h
 *
 *  Created on: 03/10/2013
 *      Author: joel
 */

#ifndef VIEWPLATAFORMAFACTORY_H_
#define VIEWPLATAFORMAFACTORY_H_
#include "ViewFiguraFactory.h"

class SimpleEditorEstirar;
class ViewPlataformaFactory: public ViewFiguraFactory{

public:
	ViewPlataformaFactory(SimpleEditorEstirar * editor, int cantidad);
	virtual ~ViewPlataformaFactory();
	FiguraView * crear(float,float);
	View * crearVistaPropia();
	string getTagRemoto();
};

#endif /* VIEWPLATAFORMAFACTORY_H_ */
