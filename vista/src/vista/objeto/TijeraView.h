/*
 * TijeraView.h
 *
 *  Created on: 16/11/2013
 *      Author: joel
 */

#ifndef TIJERAVIEW_H_
#define TIJERAVIEW_H_
#include "ObjetoView.h"
#include "src/mensajes/viewMensaje/ViewTijeraMsj.h"
#include <SDL2/SDL_mixer.h>

namespace CLIENTE {

class TijeraView: public ObjetoView {
private:
	typedef ObjetoView super;
	SDL_Texture * t2;
	float angulo1,angulo2;
	Mix_Chunk* sonido;
public:
	TijeraView(float x, float y, float w, float h,int numeroEvent, SDL_Texture* textura1, SDL_Texture* textura2);
	virtual ~TijeraView();
	void update(ViewMsj *);
	void dibujarse(SDL_Renderer *);
};

} /* namespace CLIENTE */
#endif /* TIJERAVIEW_H_ */
