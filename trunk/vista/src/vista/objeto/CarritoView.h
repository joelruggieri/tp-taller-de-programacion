/*
 * CarritoView.h
 *
 *  Created on: 14/11/2013
 *      Author: joel
 */

#ifndef CARRITOVIEW_H_
#define CARRITOVIEW_H_
#include "ObjetoView.h"
#include "src/mensajes/viewMensaje/ViewObjetoUpdateMsj.h"

namespace CLIENTE {

class CarritoView: public ObjetoView {
//private:
	//typedef ObjetoView super;
public:
	CarritoView(float x, float y, float w, float h, SDL_Texture * textura);
	virtual ~CarritoView();
	void update(ViewMsj *);
	//void dibujarse(SDL_Renderer *);
};
}
#endif /* CARRITOVIEW_H_ */
