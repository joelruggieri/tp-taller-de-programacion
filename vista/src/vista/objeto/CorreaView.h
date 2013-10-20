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

	typedef UnionView super;
	SDL_Color color;
public:
	CorreaView(int x, int y, SDL_Texture * textura,EditorUnion * editor);
	virtual ~CorreaView();
	EditorNivel* getEditor();
	void dropTemplate();
	void dibujarse(SDL_Renderer*);
	double obtenerAnguloEnRadianes();
	void proyeccion1(SDL_Renderer* renderer, double angulo);
	void proyeccion2(SDL_Renderer* renderer, double angulo);
};

#endif /* CORREAVIEW_H_ */
