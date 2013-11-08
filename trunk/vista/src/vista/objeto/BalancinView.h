/*
 * BalancinView.h
 *
 *  Created on: 05/10/2013
 *      Author: joel
 */

#ifndef BALANCINVIEW_H_
#define BALANCINVIEW_H_


#include "ObjetoView.h"
#include "src/mensajes/viewMensaje/ViewObjetoUpdateMsj.h"
namespace CLIENTE {
class BalancinView: public ObjetoView {
public:
	BalancinView(float x, float y, float w, float h, SDL_Texture * textura);
	virtual ~BalancinView();
	void update(ViewMsj *);
};
}
#endif /* BALANCINVIEW_H_ */
