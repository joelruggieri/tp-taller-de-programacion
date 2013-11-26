/*
 * CarritoView.h
 *
 *  Created on: 14/11/2013
 *      Author: joel
 */

#ifndef CARRITOVIEW_H_
#define CARRITOVIEW_H_
class SimpleEditorNivel;
class SimpleEditorEstirar;
#include "ObjetoView.h"

class CarritoView: public ObjetoView {
public:
	CarritoView(float x, float y, SimpleEditorNivel* editor);
	virtual ~CarritoView();
	void dropTemplate();
	EditorNivel * getEditor();
	void dibujarse(list<ViewMsj*> & lista);
	//void seleccionarEventoSonido();
};

#endif /* CARRITOVIEW_H_ */
