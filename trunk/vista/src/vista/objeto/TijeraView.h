/*
 * TijeraView.h
 *
 *  Created on: 16/11/2013
 *      Author: joel
 */

#ifndef TIJERAVIEW_H_
#define TIJERAVIEW_H_
#include "ObjetoView.h"
#include "src/mensajes/viewMensaje/ViewObjetoUpdateMsj.h"

namespace CLIENTE {

class TijeraView: public ObjetoView {
private:
	typedef ObjetoView super;
public:
	TijeraView(float x, float y, float w, float h, SDL_Texture * textura);
	virtual ~TijeraView();
	void update(ViewMsj *);
	void dibujarse(SDL_Renderer *);
};

} /* namespace CLIENTE */
#endif /* TIJERAVIEW_H_ */
