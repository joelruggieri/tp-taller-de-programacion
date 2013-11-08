/*
 * CorreaEstaticaView.h
 *
 *  Created on: 16/10/2013
 *      Author: jonathan
 */

#ifndef CORREAESTATICAVIEW_H_
#define CORREAESTATICAVIEW_H_
#include "src/mensajes/viewMensaje/ViewObjetoUnionUpdateMsj.h"
#include "UnionEstaticaView.h"
namespace CLIENTE {
class CorreaEstaticaView: public UnionEstaticaView {
public:
	CorreaEstaticaView(float x, float y, float w, float h, SDL_Texture * textura);
	virtual ~CorreaEstaticaView();
	void update(ViewMsj *);
};
}
#endif /* CORREAESTATICAVIEW_H_ */
