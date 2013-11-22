/*
 * ObjetoView.cpp
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#include "ObjetoView.h"
namespace CLIENTE {
ObjetoView::ObjetoView(float x, float y, float w, float h,int numeroEvent,SDL_Texture * textura): FiguraView(x, y, w, h,LAYER_DEFAULT,numeroEvent,textura) {
	// TODO Auto-generated constructor stub

}

ObjetoView::~ObjetoView() {
	// TODO Auto-generated destructor stub
}


CLIENTE::ObjetoView::ObjetoView(float x, float y, float w, float h, int layer,int numeroEvent,
		SDL_Texture* textura): FiguraView(x, y, w, h,layer,numeroEvent,textura) {
}

}
