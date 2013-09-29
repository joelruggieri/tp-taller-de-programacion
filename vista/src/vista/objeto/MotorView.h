/*
 * MotorView.h
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#ifndef MOTORVIEW_H_
#define MOTORVIEW_H_
#include "ObjetoView.h"

class MotorView: public ObjetoView {
public:
	MotorView(int x, int y, int w, int h, SDL_Texture * textura,DropController * controller);
	virtual ~MotorView();
	void dropTemplate();

};

#endif /* MOTORVIEW_H_ */
