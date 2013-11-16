/*
 * PoleaView.h
 *
 *  Created on: 13/11/2013
 *      Author: joel
 */

#ifndef POLEAVIEW_H_
#define POLEAVIEW_H_
#include "ObjetoView.h"
class SimpleEditorAnguloFijo;

class PoleaView: public ObjetoView {
public:
	PoleaView(float x, float y, SimpleEditorAnguloFijo * editor);
	virtual ~PoleaView();
	void dropTemplate();
	EditorNivel * getEditor();
};

#endif /* POLEAVIEW_H_ */
