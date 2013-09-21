/*
 * MartilloView.h
 *
 *  Created on: 20/09/2013
 *      Author: joel
 */

#ifndef MARTILLOVIEW_H_
#define MARTILLOVIEW_H_
#include "FiguraView.h"
#include "SDL2/SDL.h"

class MartilloView: public FiguraView {
private:
	void dropTemplate();
public:
	MartilloView(int x, int y, int w, int h, SDL_Texture * textura,DropController * controller);
	virtual ~MartilloView();
};

#endif /* MARTILLOVIEW_H_ */
