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
//	double v1iX,v1iY,v1fX,v1fY,v2iX,v2iY,v2fX,v2fY;
	float v1xl, v1yl,v2xl,v2yl, radioil,radiofl, v1oX, v1oY;
	float v1xp, v1yp,v2xp,v2yp, radioip,radiofp, v1oXp, v1oYp;
	typedef UnionView super;
	SDL_Color color;
	void calcularVectoresLogicos();
public:
	CorreaView(float xDesde, float yDesde,float xHasta, float yHasta, SDL_Texture * textura);
	virtual ~CorreaView();
	void dibujarse(SDL_Renderer*);
	void update();
	void update(ViewMsj *);
	void resizear();
};
}
#endif /* CORREAVIEW_H_ */
