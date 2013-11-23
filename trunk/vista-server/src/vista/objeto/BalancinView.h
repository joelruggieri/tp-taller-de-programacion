/*
 * BalancinView.h
 *
 *  Created on: 05/10/2013
 *      Author: joel
 */

#ifndef BALANCINVIEW_H_
#define BALANCINVIEW_H_


class SimpleEditorAnguloFijo;
#include "ObjetoView.h"
class BalancinView: public ObjetoView {
private:
	typedef ObjetoView super;
public:
	BalancinView(float x, float y, SimpleEditorAnguloFijo * editor);
	virtual ~BalancinView();
	void dropTemplate();
	EditorNivel * getEditor();
};

#endif /* BALANCINVIEW_H_ */
