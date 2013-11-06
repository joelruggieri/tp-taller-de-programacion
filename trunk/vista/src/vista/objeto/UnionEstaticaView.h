/*
 * UnionEstaticaView.h
 *
 *  Created on: 16/10/2013
 *      Author: jonathan
 */

#ifndef UNIONESTATICAVIEW_H_
#define UNIONESTATICAVIEW_H_

#include "ObjetoView.h"
#include "UnionView.h"

namespace CLIENTE {

class UnionEstaticaView: public ObjetoView {
public:
	UnionEstaticaView(int x, int y, int w, int h, SDL_Texture * textura);
	virtual ~UnionEstaticaView();
};


}
#endif /* UNIONESTATICAVIEW_H_ */
