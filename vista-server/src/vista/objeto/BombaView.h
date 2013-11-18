/*
 * BombaView.h
 *
 *  Created on: 17/11/2013
 *      Author: ezequiel
 */

#ifndef BOMBAVIEW_H_
#define BOMBAVIEW_H_
#include "ObjetoView.h"
class SimpleEditorAnguloFijo;
class BombaView : public ObjetoView {
public:
	BombaView(float x, float y , SimpleEditorAnguloFijo* editor);
	virtual ~BombaView();
	void dropTemplate();
	EditorNivel * getEditor();
};

#endif /* BOMBAVIEW_H_ */
