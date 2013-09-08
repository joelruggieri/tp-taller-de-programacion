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
public:
	View();
	virtual ~View();
	virtual void dibujarse(SDL_Renderer*)=0;
};

#endif /* VIEW_H_ */
