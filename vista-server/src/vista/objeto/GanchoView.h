/*
 * GanchoView.h
 *
 *  Created on: 13/11/2013
 *      Author: joel
 */

#ifndef GANCHOVIEW_H_
#define GANCHOVIEW_H_
#include "ObjetoView.h"
class SimpleEditorAnguloFijo;

class GanchoView: public ObjetoView {
public:
	GanchoView(float x, float y, SimpleEditorAnguloFijo * editor);
	virtual ~GanchoView();
	void dropTemplate();
	EditorNivel * getEditor();
};

#endif /* GANCHOVIEW_H_ */
