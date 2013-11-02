/*
 * VistaEngranaje.h
 *
 *  Created on: 12/10/2013
 *      Author: javier
 */

#ifndef VISTAENGRANAJE_H_
#define VISTAENGRANAJE_H_
	#include "ObjetoView.h"
class SimpleEditorAnguloFijo;
class SimpleEditorCambiarRadio;

class VistaEngranaje: public ObjetoView {
	typedef FiguraView super;
private:
	float diametro;
public:
	VistaEngranaje(float x, float y, float diametro, SimpleEditorCambiarRadio * editor);
	virtual ~VistaEngranaje();
	void dropTemplate();
	EditorNivel * getEditor();
//	void  update();
	int getLayer();
	void dibujarse(list<ViewMsj*> & lista);
};

#endif /* VISTAENGRANAJE_H_ */
