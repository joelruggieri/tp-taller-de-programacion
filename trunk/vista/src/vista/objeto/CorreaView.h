/*
 * CorreaView.h
 *
 *  Created on: 15/10/2013
 *      Author: joel
 */

#ifndef CORREAVIEW_H_
#define CORREAVIEW_H_

#include "UnionView.h"
namespace CLIENTE {

class CorreaView: public UnionView {
private:
	double v1iX,v1iY,v1fX,v1fY,v2iX,v2iY,v2fX,v2fY;
	typedef UnionView super;
	SDL_Color color;
public:
	CorreaView(float x, float y, SDL_Texture * textura);
	virtual ~CorreaView();
	void dibujarse(SDL_Renderer*);
	void update();
	void update(ViewMsj *);
};
}
#endif /* CORREAVIEW_H_ */
