/*
 * YunqueView.h
 *
 *  Created on: 13/11/2013
 *      Author: ezequiel
 */

#ifndef YUNQUEVIEW_H_
#define YUNQUEVIEW_H_
#include "ObjetoView.h"
#include <SDL2/SDL_mixer.h>
#include "src/mensajes/viewMensaje/ViewObjetoUpdateMsj.h"
namespace CLIENTE {

class YunqueView : public ObjetoView {
private:
	Mix_Chunk* sonido;
	typedef FiguraView super;
public:
	YunqueView(float x, float y, float w, float h,int numeroEvent,SDL_Texture * textura);
	virtual ~YunqueView();
	void update(ViewMsj *);
	void dibujarse(SDL_Renderer* r);
};

} /* namespace CLIENTE */
#endif /* YUNQUEVIEW_H_ */
