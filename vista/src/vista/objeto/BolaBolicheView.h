/*
 * BolaBolicheView.h
 *
 *  Created on: 06/10/2013
 *      Author: ezequiel
 */

#ifndef BOLABOLICHEVIEW_H_
#define BOLABOLICHEVIEW_H_
#include "ObjetoView.h"
#include "src/mensajes/viewMensaje/ViewObjetoUpdateMsj.h"
class SimpleEditorAnguloFijo;
namespace CLIENTE {
class BolaBolicheView : public ObjetoView {
public:
	BolaBolicheView(float x, float y, float w, float h, SDL_Texture * textura);
	virtual ~BolaBolicheView();
	void update(ViewMsj *);
};

}
#endif /* BOLABOLICHEVIEW_H_ */
