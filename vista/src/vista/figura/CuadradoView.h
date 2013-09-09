/*
 * RomboView.h
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#ifndef CUADRADOVIEW_H_
#define CUADRADOVIEW_H_

#include "FiguraView.h"
#include "SDL2/SDL.h"

class CuadradoView: public FiguraView {
private:
	void dropTemplate(DropController*);
public:
	CuadradoView(int x, int y, int w, int h, SDL_Texture * textura);
	virtual ~CuadradoView();
};

#endif /* CUADRADOVIEW_H_ */
