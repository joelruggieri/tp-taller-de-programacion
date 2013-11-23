/*
 * ViewPelotaJuegoFactory.h
 *
 *  Created on: 06/10/2013
 *      Author: ezequiel
 */

#ifndef VIEWMonitorFACTORY_H_
#define VIEWMonitorFACTORY_H_
#include "ViewFiguraFactory.h"
class SimpleEditorAnguloFijo;
class ViewMonitorFactory : public ViewFiguraFactory{
public:
	ViewMonitorFactory(SimpleEditorAnguloFijo * editor, int cantidad);
	virtual ~ViewMonitorFactory();
	FiguraView * crear(float,float);
	View * crearVistaPropia();
	string getTagRemoto();
	View * crearVistaPropia(float,float,float,float);
	ViewFiguraFactory* clone(int);
};

#endif /* VIEWMonitorFACTORY_H_ */
