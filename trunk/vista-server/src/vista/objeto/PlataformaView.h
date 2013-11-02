/*
 * PlataformaView.h
 *
 *  Created on: 03/10/2013
 *      Author: joel
 */

#ifndef PLATAFORMAVIEW_H_
#define PLATAFORMAVIEW_H_
#include "ObjetoView.h"

class SimpleEditorEstirar;
class PlataformaView: public ObjetoView {
private:
	typedef FiguraView super;
	float ancho;
public:
	PlataformaView(float x, float y, float ancho,SimpleEditorEstirar* controller);
	virtual ~PlataformaView();
	void dropTemplate();
	EditorNivel * getEditor();
	void dibujarse(list<ViewMsj*> & lista);
//	void update();
};

#endif /* PLATAFORMAVIEW_H_ */
