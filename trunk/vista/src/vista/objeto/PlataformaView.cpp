/*
 * PlataformaView.cpp
 *
 *  Created on: 03/10/2013
 *      Author: joel
 */

#include "PlataformaView.h"
PlataformaView::PlataformaView(int x, int y, int w, int h, SDL_Texture * textura) : ObjetoView(x,y,w,h,textura) {

}

PlataformaView::~PlataformaView() {
	// TODO Auto-generated destructor stub
}

void PlataformaView::update(ViewMsj* m){
	super::update(m);
//	float y = 0;
//	Plataforma * p = (Plataforma *)this->getModelo();
//	tl.setVector(p->getAncho(),y);
//	float nuevoAncho;
//	tl.getResultadoInverso(nuevoAncho,y);
//	this->setW(nuevoAncho);
}
