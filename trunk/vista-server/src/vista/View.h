/*
 * View.h
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#ifndef VIEW_H_
#define VIEW_H_
#include "Dibujable.h"

class View : public Dibujable{
private:
	float xc,yc;
public:
	View(float x, float y);
	virtual ~View();
	virtual void dibujarse(list<ViewMsj*> & lista)=0;
	virtual float getXCentro();
	virtual float getYCentro();
	//desplaza la vista en x y en y;
	virtual void desplazarCentroA(float x, float y);

	virtual void setXc(float xc) {
		this->xc = xc;
	}

	virtual void setYc(float yc) {
		this->yc = yc;
	}
};

#endif /* VIEW_H_ */
