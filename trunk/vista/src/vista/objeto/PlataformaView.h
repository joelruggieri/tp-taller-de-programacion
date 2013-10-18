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
public:
	PlataformaView(int x, int y, int w, int h, SDL_Texture * textura,SimpleEditorEstirar* controller);
	virtual ~PlataformaView();
	void dropTemplate();
	EditorNivel * getEditor();
	void update(Transformacion & tl);
};

#endif /* PLATAFORMAVIEW_H_ */
