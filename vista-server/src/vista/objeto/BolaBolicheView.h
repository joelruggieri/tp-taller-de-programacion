/*
 * BolaBolicheView.h
 *
 *  Created on: 06/10/2013
 *      Author: ezequiel
 */

#ifndef BOLABOLICHEVIEW_H_
#define BOLABOLICHEVIEW_H_
#include "ObjetoView.h"
class SimpleEditorAnguloFijo;

class BolaBolicheView : public ObjetoView {
private:
	typedef ObjetoView super;
public:
	BolaBolicheView(float x, float y, SimpleEditorAnguloFijo * editor);
	virtual ~BolaBolicheView();
	void dropTemplate();
	EditorNivel * getEditor();
	void seleccionarEventoSonido();
	void dibujarse(list<ViewMsj*> & lista);
};

#endif /* BOLABOLICHEVIEW_H_ */
