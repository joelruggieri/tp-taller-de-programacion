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
private:
	typedef ObjetoView super;
public:
	BombaView(float x, float y , SimpleEditorAnguloFijo* editor);
	virtual ~BombaView();
	void dropTemplate();
	EditorNivel * getEditor();
	void seleccionarEventoSonido();
	void dibujarse(list<ViewMsj*> & lista);
};

#endif /* BOMBAVIEW_H_ */
