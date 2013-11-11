/*
 * AreaView.h
 *
 *  Created on: 11/11/2013
 *      Author: ezequiel
 */

#ifndef AREAVIEW_H_
#define AREAVIEW_H_
#include "View.h"
namespace CLIENTE {

class AreaView : public View {
private:
	SDL_Texture* textura;
public:
	AreaView(float x, float y, float w, float h, SDL_Texture* );
	virtual ~AreaView();
	 void dibujarse(SDL_Renderer*);
	 void dibujarse(SDL_Renderer*, SDL_Rect&);
	 void update(ViewMsj *);
	 void resize();
	 int getLayer();
	 bool isUpdated();

};

} /* namespace CLIENTE */
#endif /* AREAVIEW_H_ */
