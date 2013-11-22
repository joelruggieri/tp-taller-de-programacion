/*
 * GloboHelioView.h
 *
 *  Created on: 05/10/2013
 *      Author: ezequiel
 */

#ifndef GLOBOHELIOVIEW_H_
#define GLOBOHELIOVIEW_H_
#include "ObjetoView.h"
#include "src/mensajes/viewMensaje/ViewObjetoUpdateMsj.h"
namespace CLIENTE {
class GloboHelioView : public ObjetoView {
public:
	GloboHelioView(float x,float y, float w, float h,int numeroEvent, SDL_Texture * textura);
	virtual ~GloboHelioView();
	void dropTemplate();
	void update(ViewMsj *);
};
}
#endif /* GLOBOHELIOVIEW_H_ */
