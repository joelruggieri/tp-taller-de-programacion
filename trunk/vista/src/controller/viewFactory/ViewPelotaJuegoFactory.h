/*
 * ViewPelotaJuegoFactory.h
 *
 *  Created on: 06/10/2013
 *      Author: ezequiel
 */

#ifndef VIEWPELOTAJUEGOFACTORY_H_
#define VIEWPELOTAJUEGOFACTORY_H_
#include "ViewFiguraFactory.h"
class ViewPelotaJuegoFactory : public ViewFiguraFactory{
public:
	ViewPelotaJuegoFactory();
	virtual ~ViewPelotaJuegoFactory();
	FiguraView * crear(int,int);
};

#endif /* VIEWPELOTAJUEGOFACTORY_H_ */
