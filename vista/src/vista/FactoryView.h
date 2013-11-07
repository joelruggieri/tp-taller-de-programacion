/*
 * FactoryView.h
 *
 *  Created on: 21/09/2013
 *      Author: jonathan
 */

#ifndef FACTORYVIEW_H_
#define FACTORYVIEW_H_

#include "SDL2/SDL.h"
#include "View.h"

namespace CLIENTE {
class FactoryView: public View {
private:
	SDL_Texture * textura;
public:
	FactoryView(float x, float y, float w, float h, SDL_Texture * textura);
	virtual ~FactoryView();
	void dibujarse(SDL_Renderer*);
	void dibujarse(SDL_Renderer*, SDL_Rect&);
	void update(ViewMsj *);
	int getLayer();
};
}
#endif /* FACTORYVIEW_H_ */
