/*
 * BloqueView.h
 *
 *  Created on: 21/09/2013
 *      Author: joel
 */

#ifndef BLOQUEVIEW_H_
#define BLOQUEVIEW_H_
#include "FiguraView.h"
#include "SDL2/SDL.h"

class BloqueView: public FiguraView {
private:
	void dropTemplate();

public:
	BloqueView(int x, int y, int w, int h, SDL_Texture * textura,DropController * controller);
	virtual ~BloqueView();
};

#endif /* BLOQUEVIEW_H_ */
