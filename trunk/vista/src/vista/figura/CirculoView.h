/*
 * RomboView.h
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#ifndef CIRCULOVIEW_H_
#define CIRCULOVIEW_H_

#include "FiguraView.h"
#include "SDL2/SDL.h"

class CirculoView: public FiguraView {
private:
	void dropTemplate();
public:
	CirculoView(int x, int y, int w, int h, SDL_Texture * textura,DropController * controller);
	virtual ~CirculoView();
};

#endif /* CIRCULOVIEW_H_ */
