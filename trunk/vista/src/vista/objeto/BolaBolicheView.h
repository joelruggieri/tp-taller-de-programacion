/*
 * BolaBolicheView.h
 *
 *  Created on: 06/10/2013
 *      Author: ezequiel
 */

#ifndef BOLABOLICHEVIEW_H_
#define BOLABOLICHEVIEW_H_
#include "ObjetoView.h"
#include <SDL2/SDL_mixer.h>
#include "src/mensajes/viewMensaje/ViewObjetoUpdateMsj.h"
class SimpleEditorAnguloFijo;
namespace CLIENTE {
class BolaBolicheView : public ObjetoView {
private:
	Mix_Chunk* sonido;
	typedef FiguraView super;
public:
	BolaBolicheView(float x, float y, float w, float h,int numeroEvent,SDL_Texture * textura);
	virtual ~BolaBolicheView();
	void update(ViewMsj *);
	void dibujarse(SDL_Renderer* renderer);
};

}
#endif /* BOLABOLICHEVIEW_H_ */
