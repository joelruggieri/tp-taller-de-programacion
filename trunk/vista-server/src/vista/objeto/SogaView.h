/*
 * Sogaview.h
 *
 *  Created on: Oct 5, 2013
 *      Author: matias
 */

#ifndef SOGAVIEW_H_
#define SOGAVIEW_H_

#include "UnionView.h"

class EditorUnion;

class SogaView: public UnionView {
public:
	SogaView(float x, float y,EditorUnion * editor);
	virtual ~SogaView();
	EditorNivel* getEditor();
	void dropTemplate();
	void dibujarse(SDL_Renderer * renderer, SDL_Rect & dest);
private:
	typedef UnionView super;
};

#endif /* SOGAVIEW_H_ */
