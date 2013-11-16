/*
 * PoleaView.h
 *
 *  Created on: 13/11/2013
 *      Author: joel
 */

#ifndef POLEAVIEW_H_
#define POLEAVIEW_H_
#include "ObjetoView.h"
#include "src/mensajes/viewMensaje/ViewObjetoUpdateMsj.h"
namespace CLIENTE {

class PoleaView: public ObjetoView {
public:
	PoleaView(float x, float y, float w, float h, SDL_Texture * textura);
	virtual ~PoleaView();
	void update(ViewMsj *);
};

} /* namespace CLIENTE */
#endif /* POLEAVIEW_H_ */
