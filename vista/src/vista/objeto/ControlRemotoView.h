/*
 * ControlRemotoView.h
 *
 *  Created on: 17/11/2013
 *      Author: ezequiel
 */

#ifndef CONTROLREMOTOVIEW_H_
#define CONTROLREMOTOVIEW_H_
#include "ObjetoView.h"
#include "src/mensajes/viewMensaje/ViewObjetoUpdateMsj.h"
class SimpleEditorAnguloFijo;
namespace CLIENTE {

class ControlRemotoView : public ObjetoView {
public:
	ControlRemotoView(float x, float y, float w, float h, SDL_Texture* textura);
	virtual ~ControlRemotoView();
	void update(ViewMsj *);
};

} /* namespace CLIENTE */
#endif /* CONTROLREMOTOVIEW_H_ */
