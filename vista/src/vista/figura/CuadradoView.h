/*
 * RomboView.h
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#ifndef CUADRADOVIEW_H_
#define CUADRADOVIEW_H_

#include "FiguraView.h"

class CuadradoView: public FiguraView {
private:
	void dropTemplate(DropController*);
public:
	CuadradoView();
	virtual ~CuadradoView();
	void dibujarse(SDL_Renderer*);
};

#endif /* CUADRADOVIEW_H_ */
