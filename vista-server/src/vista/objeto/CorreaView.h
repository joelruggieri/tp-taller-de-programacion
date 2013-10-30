/*
 * CorreaView.h
 *
 *  Created on: 15/10/2013
 *      Author: joel
 */

#ifndef CORREAVIEW_H_
#define CORREAVIEW_H_

#include "UnionView.h"

class EditorUnion;

class CorreaView: public UnionView {
private:
	double v1iX,v1iY,v1fX,v1fY,v2iX,v2iY,v2fX,v2fY;
	typedef UnionView super;
	SDL_Color color;
public:
	CorreaView(float x, float y,EditorUnion * editor);
	virtual ~CorreaView();
	EditorNivel* getEditor();
	void dropTemplate();
	void dibujarse(SDL_Renderer*);
//	void update();
};

#endif /* CORREAVIEW_H_ */
