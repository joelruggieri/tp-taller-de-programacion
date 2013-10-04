/*
 * PelotaView.h
 *
 *  Created on: 20/09/2013
 *      Author: joel
 */

#ifndef PELOTAVIEW_H_
#define PELOTAVIEW_H_
#include "FiguraView.h"
#include "SDL2/SDL.h"

class PelotaView: public FiguraView{
private:
	void dropTemplate();
public:
	PelotaView(int x, int y, int w, int h, SDL_Texture * textura,DropController * controller);
	virtual ~PelotaView();
	EditorNivel* getEditor();
};


#endif /* PELOTAVIEW_H_ */
