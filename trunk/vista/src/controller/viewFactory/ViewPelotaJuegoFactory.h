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
	ViewPelotaJuegoFactory(SimpleEditorAnguloFijo * editor);
	virtual ~ViewPelotaJuegoFactory();
	FiguraView * crear(int,int,int,int);
	View * crearVistaPropia(int,int,int,int);
};

#endif /* VIEWPELOTAJUEGOFACTORY_H_ */
