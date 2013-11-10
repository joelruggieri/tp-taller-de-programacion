/*
 * Sogaview.h
 *
 *  Created on: Oct 5, 2013
 *      Author: matias
 */

#ifndef SOGAVIEW_H_
#define SOGAVIEW_H_
#include "src/mensajes/viewMensaje/ViewObjetoUnionUpdateMsj.h"
#include "UnionView.h"
namespace CLIENTE {

class SogaView: public UnionView {
public:
	SogaView(float x, float y, SDL_Texture * textura);
	virtual ~SogaView();
	void dibujarse(SDL_Renderer * renderer);
	void dibujarse(SDL_Renderer * renderer, SDL_Rect & dest);
	void update(ViewMsj *);
	void resizear();
private:
	typedef UnionView super;
	float xDesdeP, xHastap, yDesdep, yHastaP;
};
}
#endif /* SOGAVIEW_H_ */
