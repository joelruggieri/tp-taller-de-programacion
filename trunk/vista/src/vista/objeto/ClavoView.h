/*
 * ClavoView.h
 *
 *  Created on: 14/11/2013
 *      Author: ezequiel
 */

#ifndef CLAVOVIEW_H_
#define CLAVOVIEW_H_
#include "ObjetoView.h"
#include "src/mensajes/viewMensaje/ViewObjetoUpdateMsj.h"
namespace CLIENTE {

class ClavoView : public ObjetoView {
private:
	typedef ObjetoView super;
public:
	ClavoView(float x, float y, float w, float h,int numeroEvent,SDL_Texture * textura);
	virtual ~ClavoView();
	void update(ViewMsj *);
	void dibujarse(SDL_Renderer *);
};

} /* namespace CLIENTE */
#endif /* CLAVOVIEW_H_ */
