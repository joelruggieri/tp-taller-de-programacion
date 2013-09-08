/*
 * ViewFiguraFactory.h
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#ifndef VIEWFIGURAFACTORY_H_
#define VIEWFIGURAFACTORY_H_
#include "../../vista/figura/FiguraView.h"

class ViewFiguraFactory {
private:
public:
	ViewFiguraFactory();
	virtual ~ViewFiguraFactory();
	virtual FiguraView * crear(int,int,int,int)=0;
	virtual FiguraView * crearVistaPropia(int,int,int,int) = 0;
	float getAlto() const;
	void setAlto(float alto);
	float getAncho() const;
	void setAncho(float ancho);
};

#endif /* VIEWFIGURAFACTORY_H_ */
