/*
 * SogaEstaticaView.h
 *
 *  Created on: 15/10/2013
 *      Author: jonathan
 */

#ifndef SOGAESTATICAVIEW_H_
#define SOGAESTATICAVIEW_H_

#include "UnionEstaticaView.h"
#include "UnionView.h"
#include "src/mensajes/viewMensaje/ViewObjetoUnionUpdateMsj.h"
#include "src/mensajes/viewMensaje/ViewObjetoUpdateMsj.h"
namespace CLIENTE {

class SogaEstaticaView: public UnionEstaticaView {
public:
	SogaEstaticaView(float x, float y, float w, float h,int numeroEvent, SDL_Texture * textura);
	virtual ~SogaEstaticaView();
	void update(ViewMsj *);
private:
	SDL_Texture * texturaTramo;
};

}
#endif /* SOGAESTATICAVIEW_H_ */
