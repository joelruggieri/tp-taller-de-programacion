/*
 * ViewMotorFactory.h
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#ifndef VIEWMOTORFACTORY_H_
#define VIEWMOTORFACTORY_H_
#include "ViewFiguraFactory.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
#include "../../controller/editor/SimpleEditorOrientacionCambiable.h"
class ViewMotorFactory: public ViewFiguraFactory {
public:
//	ViewMotorFactory(SimpleEditorAnguloFijo * editor);
	ViewMotorFactory(SimpleEditorOrientacionCambiable * editor, int cantidad);
	virtual ~ViewMotorFactory();
	FiguraView * crear(float,float);
	View * crearVistaPropia();
	string getTagRemoto();
};

#endif /* VIEWMOTORFACTORY_H_ */
