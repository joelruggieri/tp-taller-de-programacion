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
	ViewMotorFactory(SimpleEditorOrientacionCambiable * editor);
	virtual ~ViewMotorFactory();
	FiguraView * crear(float,float,float,float);
	View * crearVistaPropia(float,float,float,float);
};

#endif /* VIEWMOTORFACTORY_H_ */
