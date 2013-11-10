/*
 * CorreaView.h
 *
 *  Created on: 15/10/2013
 *      Author: joel
 */

#ifndef CORREAVIEW_H_
#define CORREAVIEW_H_

#include "UnionView.h"
#include "../../controller/Resizer.h"
namespace CLIENTE {

class CorreaView: public UnionView {
private:
	double v1iX,v1iY,v1fX,v1fY,v2iX,v2iY,v2fX,v2fY;
	bool estatica;
	float x, y, radio, angulo;
	typedef UnionView super;
	SDL_Color color;
	void dibujarseEstatica(SDL_Renderer* , bool estatica);
public:
	CorreaView(float x, float y, SDL_Texture * textura);
	virtual ~CorreaView();
	void dibujarse(SDL_Renderer*);
	void update();
	void update(ViewMsj *);
};
}
#endif /* CORREAVIEW_H_ */
