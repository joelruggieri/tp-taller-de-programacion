/*
 * RomboView.h
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#ifndef TRIANGULOVIEW_H_
#define TRIANGULOVIEW_H_

#include "FiguraView.h"
#include "SDL2/SDL.h"
class TrianguloView: public FiguraView {
private:
	void dropTemplate(DropController*);
public:
	TrianguloView(int x, int y, int w, int h, SDL_Texture * textura);
	virtual ~TrianguloView();
};

#endif /* CUADRADOVIEW_H_ */
