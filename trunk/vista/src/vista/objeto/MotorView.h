/*
 * MotorView.h
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#ifndef MOTORVIEW_H_
#define MOTORVIEW_H_

#include "ObjetoView.h"
#include "SDL2/SDL.h"
namespace CLIENTE {

class MotorView: public ObjetoView {
public:
//	MotorView(int x, int y, int w, int h, SDL_Texture * textura, SimpleEditorAnguloFijo * editor);
	MotorView(int x, int y, int w, int h, SDL_Texture * textura);
	void update(ViewMsj *);
	virtual ~MotorView();
	int getLayer();
};
}

#endif /* MOTORVIEW_H_ */
