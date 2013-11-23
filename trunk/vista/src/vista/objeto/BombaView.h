/*
 * BombaView.h
 *
 *  Created on: 17/11/2013
 *      Author: ezequiel
 */

#ifndef BOMBAVIEW_H_
#define BOMBAVIEW_H_
#include "ObjetoView.h"
#include <SDL2/SDL_mixer.h>
#include "src/mensajes/viewMensaje/ViewObjetoUpdateMsj.h"
namespace CLIENTE {

class BombaView : public ObjetoView {
private:
	Mix_Chunk* sonidoContacto;
	Mix_Chunk* sonidoExplosion;
	typedef FiguraView super;
public:
	BombaView(float x, float y, float w, float h,int numeroEvent,SDL_Texture * textura);
	virtual ~BombaView();
	void update(ViewMsj *);
	void dibujarse(SDL_Renderer* renderer);
};

} /* namespace CLIENTE */
#endif /* BOMBAVIEW_H_ */
