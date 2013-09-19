/*
 * View.h
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#ifndef VIEW_H_
#define VIEW_H_
#include "Dibujable.h"
#include "Resizeable.h"
#include "../controller/Resizer.h"

class View : public Dibujable, public Resizeable{
private:
	int w,h;
	int xc, yc;
public:
	View(int x, int y, int w, int h);
	virtual ~View();
	virtual void dibujarse(SDL_Renderer*)=0;
	int getH() const;
	int getW() const;
	int getX() const;
	int getY() const;
	int getXCentro() const;
	int getYCentro() const;
	virtual void resizear() = 0;
	//desplaza la vista en x y en y;
	void desplazarCentroA(int x, int y);

	void setH(int h) {
		this->h = h;
	}

	void setW(int w) {
		this->w = w;
	}

	void setXc(int xc) {
		this->xc = xc;
	}

	void setYc(int yc) {
		this->yc = yc;
	}
};

#endif /* VIEW_H_ */