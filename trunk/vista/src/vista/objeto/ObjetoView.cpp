/*
 * ObjetoView.cpp
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#include "ObjetoView.h"
namespace CLIENTE {
ObjetoView::ObjetoView(float x, float y, float w, float h, SDL_Texture * textura): FiguraView(x, y, w, h,LAYER_DEFAULT,textura) {
	// TODO Auto-generated constructor stub

}

ObjetoView::~ObjetoView() {
	// TODO Auto-generated destructor stub
}


CLIENTE::ObjetoView::ObjetoView(float x, float y, float w, float h, int layer,
		SDL_Texture* textura): FiguraView(x, y, w, h,layer,textura) {
}

}
