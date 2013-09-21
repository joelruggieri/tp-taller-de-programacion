/*
 * CoheteView.h
 *
 *  Created on: 21/09/2013
 *      Author: joel
 */

#ifndef COHETEVIEW_H_
#define COHETEVIEW_H_
#include "FiguraView.h"
#include "SDL2/SDL.h"

class CoheteView: public FiguraView {
private:
	void dropTemplate();

public:
	CoheteView(int x, int y, int w, int h, SDL_Texture * textura,DropController * controller);
	virtual ~CoheteView();
};

#endif /* COHETEVIEW_H_ */
