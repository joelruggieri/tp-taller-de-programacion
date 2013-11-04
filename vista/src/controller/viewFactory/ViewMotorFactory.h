/*
 * ViewMotorFactory.h
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#ifndef VIEWMOTORFACTORY_H_
#define VIEWMOTORFACTORY_H_
#include "ViewFiguraFactory.h"
class ViewMotorFactory: public ViewFiguraFactory {
public:
//	ViewMotorFactory(SimpleEditorAnguloFijo * editor);
	ViewMotorFactory();
	virtual ~ViewMotorFactory();
	FiguraView * crear(int, int, int, int);
};

#endif /* VIEWMOTORFACTORY_H_ */
