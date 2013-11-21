/*
 * PelotaJuegoView.h
 *
 *  Created on: 06/10/2013
 *      Author: ezequiel
 */

#ifndef PELOTAJUEGOVIEW_H_
#define PELOTAJUEGOVIEW_H_
#include "ObjetoView.h"
class SimpleEditorAnguloFijo;

class PelotaJuegoView : public ObjetoView {
private:
	typedef ObjetoView super;
public:
	PelotaJuegoView(float x, float y,SimpleEditorAnguloFijo * editor);
	virtual ~PelotaJuegoView();
	void dropTemplate();
	EditorNivel * getEditor();
	void seleccionarEventoSonido();
	void dibujarse(list<ViewMsj*> & lista);
};

#endif /* PELOTAJUEGOVIEW_H_ */
