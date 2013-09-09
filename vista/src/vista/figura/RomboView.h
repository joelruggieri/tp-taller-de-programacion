/*
 * RomboView.h
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#ifndef ROMBOVIEW_H_
#define ROMBOVIEW_H_

#include "FiguraView.h"
#include "SDL2/SDL.h"

class RomboView: public FiguraView {
private:
	void dropTemplate();
public:
	RomboView(int x, int y, int w, int h, SDL_Texture * textura,DropController * controller);
	virtual ~RomboView();
};

#endif /* ROMBOVIEW_H_ */
