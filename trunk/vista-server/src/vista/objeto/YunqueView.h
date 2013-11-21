/*
 * YunqueView.h
 *
 *  Created on: 13/11/2013
 *      Author: ezequiel
 */

#ifndef YUNQUEVIEW_H_
#define YUNQUEVIEW_H_
#include "ObjetoView.h"
class SimpleEditorAnguloFijo;
class YunqueView : public ObjetoView {
private:
	typedef ObjetoView super;
public:
	YunqueView(float x, float y,SimpleEditorAnguloFijo * editor);
	virtual ~YunqueView();
	void dropTemplate();
	EditorNivel * getEditor();
	void seleccionarEventoSonido();
	void dibujarse(list<ViewMsj*> & lista);
};

#endif /* YUNQUEVIEW_H_ */
