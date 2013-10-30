/*
 * ViewSogaFactory.h
 *
 *  Created on: Oct 5, 2013
 *      Author: matias
 */

#ifndef VIEWSOGAFACTORY_H_
#define VIEWSOGAFACTORY_H_
#include "ViewFiguraFactory.h"
#include "../editor/EditorUnion.h"

namespace std {

class ViewSogaFactory: public ViewFiguraFactory {

public:
	ViewSogaFactory(EditorUnion* editor);
	virtual ~ViewSogaFactory();
	FiguraView * crear(float,float,float,float);
	View * crearVistaPropia(float,float,float,float);
};

} /* namespace std */
#endif /* VIEWSOGAFACTORY_H_ */
