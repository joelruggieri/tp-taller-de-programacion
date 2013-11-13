/*
 * YunqueView.h
 *
 *  Created on: 13/11/2013
 *      Author: ezequiel
 */

#ifndef YUNQUEVIEW_H_
#define YUNQUEVIEW_H_
#include "ObjetoView.h"
#include "src/mensajes/viewMensaje/ViewObjetoUpdateMsj.h"
namespace CLIENTE {

class YunqueView : public ObjetoView {
public:
	YunqueView(float x, float y, float w, float h, SDL_Texture * textura);
	virtual ~YunqueView();
	void update(ViewMsj *);
};

} /* namespace CLIENTE */
#endif /* YUNQUEVIEW_H_ */
