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
	double v1oX;
	double v1oY;
	double v2oX;
	double v2oY;
	typedef UnionView super;
	SDL_Color color;
public:
	CorreaView(int x, int y, SDL_Texture * textura,EditorUnion * editor);
	virtual ~CorreaView();
	EditorNivel* getEditor();
	void dropTemplate();
	void dibujarse(SDL_Renderer*);
	void update();
};

#endif /* CORREAVIEW_H_ */
