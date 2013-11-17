/*
 * TijeraView.h
 *
 *  Created on: 17/11/2013
 *      Author: joel
 */

#ifndef TIJERAVIEW_H_
#define TIJERAVIEW_H_
class SimpleEditorAnguloFijo;
#include "ObjetoView.h"
class TijeraView: public ObjetoView  {
public:
	TijeraView(float x, float y, SimpleEditorAnguloFijo* editor);
	virtual ~TijeraView();
	void dropTemplate();
	EditorNivel * getEditor();
};

#endif /* TIJERAVIEW_H_ */
