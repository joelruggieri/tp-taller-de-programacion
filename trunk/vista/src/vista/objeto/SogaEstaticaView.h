/*
 * SogaEstaticaView.h
 *
 *  Created on: 15/10/2013
 *      Author: jonathan
 */

#ifndef SOGAESTATICAVIEW_H_
#define SOGAESTATICAVIEW_H_

#include "UnionEstaticaView.h"
#include "UnionView.h"

namespace CLIENTE {

class SogaEstaticaView: public UnionEstaticaView {
public:
	SogaEstaticaView(float x, float y, float w, float h, SDL_Texture * textura);
	virtual ~SogaEstaticaView();
	void update(ViewMsj *);
private:
	SDL_Texture * texturaTramo;
};

}
#endif /* SOGAESTATICAVIEW_H_ */
