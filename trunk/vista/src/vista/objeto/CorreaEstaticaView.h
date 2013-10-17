/*
 * CorreaEstaticaView.h
 *
 *  Created on: 16/10/2013
 *      Author: jonathan
 */

#ifndef CORREAESTATICAVIEW_H_
#define CORREAESTATICAVIEW_H_

#include "UnionEstaticaView.h"

class CorreaEstaticaView: public UnionEstaticaView {
public:
	CorreaEstaticaView(int x, int y, int w, int h, SDL_Texture * textura,EditorUnion * editor);
	virtual ~CorreaEstaticaView();
	void dropTemplate();
	EditorNivel * getEditor();
	UnionView * toDinamica();

};

#endif /* CORREAESTATICAVIEW_H_ */
