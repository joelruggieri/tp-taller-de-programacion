/*
 * CorreaEstaticaView.h
 *
 *  Created on: 16/10/2013
 *      Author: jonathan
 */

#ifndef CORREAESTATICAVIEW_H_
#define CORREAESTATICAVIEW_H_

#include "UnionEstaticaView.h"
namespace CLIENTE {
class CorreaEstaticaView: public UnionEstaticaView {
public:
	CorreaEstaticaView(int x, int y, int w, int h, SDL_Texture * textura);
	virtual ~CorreaEstaticaView();
	void update(ViewMsj *);
};
}
#endif /* CORREAESTATICAVIEW_H_ */
