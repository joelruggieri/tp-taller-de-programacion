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
	CorreaView(float x, float y,EditorUnion * editor);
	virtual ~CorreaView();
	EditorNivel* getEditor();
	void dropTemplate();
	void dibujarse(list<ViewMsj*> & lista);
//	void update();
};

#endif /* CORREAVIEW_H_ */
