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
#include <SDL2/SDL_mixer.h>
#include "src/mensajes/viewMensaje/ViewObjetoUpdateMsj.h"
namespace CLIENTE {

class MotorView: public ObjetoView {
private:
	Mix_Chunk* sonido;
	typedef FiguraView super;
public:
//	MotorView(int x, int y, int w, int h, SDL_Texture * textura, SimpleEditorAnguloFijo * editor);
	MotorView(float x, float y,float w,float h,int numeroEvent,SDL_Texture * textura);
	void update(ViewMsj *);
	virtual ~MotorView();
	void dibujarse(SDL_Renderer*);
};
}

#endif /* MOTORVIEW_H_ */
