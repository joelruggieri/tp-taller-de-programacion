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
	float ancho, alto;
public:
	ViewFiguraFactory(float ancho, float alto);
	virtual ~ViewFiguraFactory();
	virtual FiguraView * crear(float, float)=0;
	float getAlto() const;
	void setAlto(float alto);
	float getAncho() const;
	void setAncho(float ancho);
};

#endif /* VIEWFIGURAFACTORY_H_ */
