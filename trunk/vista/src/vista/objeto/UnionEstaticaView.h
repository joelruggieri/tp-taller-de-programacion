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
class EditorUnion;
class UnionEstaticaView: public ObjetoView {
protected:
	void toDinamica(int r,int g, int b);
public:
	UnionEstaticaView(int x, int y, int w, int h, SDL_Texture * textura, EditorUnion * editor);
	virtual ~UnionEstaticaView();
	virtual UnionView * toDinamica() = 0;
};

#endif /* UNIONESTATICAVIEW_H_ */
