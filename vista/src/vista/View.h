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
	int x, y, w,h;
public:
	View(int x, int y, int w, int h);
	virtual ~View();
	virtual void dibujarse(SDL_Renderer*)=0;
	int getH() const;
	int getW() const;
	int getX() const;
	int getY() const;
};

#endif /* VIEW_H_ */
