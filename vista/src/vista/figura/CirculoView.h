/*
 * RomboView.h
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#ifndef CIRCULOVIEW_H_
#define CIRCULOVIEW_H_

#include "FiguraView.h"

class CirculoView: public FiguraView {
private:
	void dropTemplate(DropController*);
public:
	CirculoView();
	virtual ~CirculoView();
	void dibujarse(SDL_Renderer*);
};

#endif /* CIRCULOVIEW_H_ */
