/*
 * PlataformaView.h
 *
 *  Created on: 03/10/2013
 *      Author: joel
 */

#ifndef PLATAFORMAVIEW_H_
#define PLATAFORMAVIEW_H_
#include "ObjetoView.h"

class PlataformaView: public ObjetoView {
public:
	PlataformaView(int x, int y, int w, int h, SDL_Texture * textura,DropController * controller);
	virtual ~PlataformaView();
	void dropTemplate();
};

#endif /* PLATAFORMAVIEW_H_ */
