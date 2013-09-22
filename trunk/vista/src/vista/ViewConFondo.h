/*
 * ViewConFondo.h
 *
 *  Created on: 22/09/2013
 *      Author: jonathan
 */

#ifndef VIEWCONFONDO_H_
#define VIEWCONFONDO_H_
#include "View.h"

class ViewConFondo: public View {
private:
	View *decorable;
public:
	ViewConFondo(View *);
	virtual ~ViewConFondo();
	virtual void dibujarse(SDL_Renderer*);
	virtual void dibujarse(SDL_Renderer*, SDL_Rect&);
	void resizear();
	int getH() const;
	int getW() const;
	int getX() const;
	int getY() const;
	int getXCentro() const;
	int getYCentro() const;
	//desplaza la vista en x y en y;
	void desplazarCentroA(int x, int y);
	void setH(int h);
	void setW(int w);
	void setXc(int xc);
	void setYc(int yc);
};

#endif /* VIEWCONFONDO_H_ */
