/*
 * ViewPelotaJuegoFactory.h
 *
 *  Created on: 06/10/2013
 *      Author: ezequiel
 */

#ifndef VIEWPELOTAJUEGOFACTORY_H_
#define VIEWPELOTAJUEGOFACTORY_H_
#include "ViewFiguraFactory.h"
class SimpleEditorAnguloFijo;
class ViewPelotaJuegoFactory : public ViewFiguraFactory{
public:
	ViewPelotaJuegoFactory(SimpleEditorAnguloFijo * editor, int cantidad);
	virtual ~ViewPelotaJuegoFactory();
	FiguraView * crear(float,float);
	View * crearVistaPropia();
	string getTagRemoto();
};

#endif /* VIEWPELOTAJUEGOFACTORY_H_ */
