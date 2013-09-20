/*
 * RuedaView.h
 *
 *  Created on: 19/09/2013
 *      Author: joel
 */

#ifndef RUEDAVIEW_H_
#define RUEDAVIEW_H_

#include "FiguraView.h"
#include "SDL2/SDL.h"
namespace std {

class RuedaView: public FiguraView{
private:
	void dropTemplate();
public:
	RuedaView(int x, int y, int w, int h, SDL_Texture * textura,DropController * controller);
	virtual ~RuedaView();
};

} /* namespace std */
#endif /* RUEDAVIEW_H_ */
