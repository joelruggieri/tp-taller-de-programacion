/*
 * BombaView.h
 *
 *  Created on: 17/11/2013
 *      Author: ezequiel
 */

#ifndef BOMBAVIEW_H_
#define BOMBAVIEW_H_
#include "ObjetoView.h"
#include "src/mensajes/viewMensaje/ViewObjetoUpdateMsj.h"
namespace CLIENTE {

class BombaView : public ObjetoView {
public:
	BombaView(float x, float y, float w, float h, SDL_Texture * textura);
	virtual ~BombaView();
	void update(ViewMsj *);
};

} /* namespace CLIENTE */
#endif /* BOMBAVIEW_H_ */
