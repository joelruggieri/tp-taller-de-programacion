/*
 * MonitorView.h
 *
 *  Created on: 06/10/2013
 *      Author: ezequiel
 */

#ifndef MonitorVIEW_H_
#define MonitorVIEW_H_
#include "ObjetoView.h"
class SimpleEditorNivel;

class MonitorView : public ObjetoView {
private:
	typedef ObjetoView super;
public:
	MonitorView(float x, float y,SimpleEditorNivel * editor);
	virtual ~MonitorView();
	void dropTemplate();
	EditorNivel * getEditor();
	void seleccionarEventoSonido();
	void dibujarse(list<ViewMsj*> & lista);
};

#endif /* MonitorVIEW_H_ */
