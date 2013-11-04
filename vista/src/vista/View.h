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
#include "src/mensajes/viewMensaje/ViewMsj.h"
class View : public Dibujable, public Resizeable{
private:
	int w,h;
	int xc, yc;
public:
	View(int x, int y, int w, int h);
	virtual ~View();
	virtual void dibujarse(SDL_Renderer*)=0;
	virtual void dibujarse(SDL_Renderer*, SDL_Rect&)=0;
	virtual int getH() const;
	virtual int getW() const;
	virtual int getX() const;
	virtual int getY() const;
	virtual int getXCentro() const;
	virtual int getYCentro() const;
	virtual void resizear();
	//desplaza la vista en x y en y;
	virtual void desplazarCentroA(int x, int y);

	virtual void setH(int h) {
		this->h = h;
	}

	virtual void setW(int w) {
		this->w = w;
	}

	virtual void setXc(int xc) {
		this->xc = xc;
	}

	virtual void setYc(int yc) {
		this->yc = yc;
	}
	virtual void update(ViewMsj *) = 0;


};

#endif /* VIEW_H_ */
