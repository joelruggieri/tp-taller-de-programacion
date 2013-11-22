/*
 * PelotaJuegoView.h
 *
 *  Created on: 06/10/2013
 *      Author: ezequiel
 */

#ifndef PELOTAJUEGOVIEW_H_
#define PELOTAJUEGOVIEW_H_
#include "ObjetoView.h"
#include "src/mensajes/viewMensaje/ViewObjetoUpdateMsj.h"
namespace CLIENTE {

class PelotaJuegoView : public ObjetoView {
private:
	typedef FiguraView super;
public:
	PelotaJuegoView(float x, float y, float w, float h,int numeroEvent,SDL_Texture * textura);
	virtual ~PelotaJuegoView();
	void update(ViewMsj *);
	void dibujarse(SDL_Renderer*);
};
}
#endif /* PELOTAJUEGOVIEW_H_ */
