/*
 * ClavoView.h
 *
 *  Created on: 14/11/2013
 *      Author: ezequiel
 */

#ifndef CLAVOVIEW_H_
#define CLAVOVIEW_H_
class SimpleEditorAnguloFijo;
#include "ObjetoView.h"
class ClavoView: public ObjetoView {
public:
	ClavoView(float x, float y,SimpleEditorAnguloFijo * editor);
	virtual ~ClavoView();
	void dropTemplate();
	EditorNivel * getEditor();
};

#endif /* CLAVOVIEW_H_ */
