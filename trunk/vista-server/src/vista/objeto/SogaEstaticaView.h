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
class EditorUnion;
class SogaEstaticaView: public UnionEstaticaView {
public:
	SogaEstaticaView(float x, float y,EditorUnion * editor);
	virtual ~SogaEstaticaView();
	EditorNivel* getEditor();
	void dropTemplate();
	UnionView * toDinamica();
	void dibujarse(SDL_Renderer *);
private:
};

#endif /* SOGAESTATICAVIEW_H_ */
