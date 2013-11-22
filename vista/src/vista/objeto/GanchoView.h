/*
 * GanchoView.h
 *
 *  Created on: 13/11/2013
 *      Author: joel
 */

#ifndef GANCHOVIEW_H_
#define GANCHOVIEW_H_
#include "ObjetoView.h"
#include "src/mensajes/viewMensaje/ViewObjetoUpdateMsj.h"
namespace CLIENTE {

class GanchoView: public ObjetoView {
public:
	GanchoView(float x, float y, float w, float h,int numeroEvent,SDL_Texture * textura);
	virtual ~GanchoView();
	void update(ViewMsj *);
};

} /* namespace CLIENTE */
#endif /* GANCHOVIEW_H_ */
