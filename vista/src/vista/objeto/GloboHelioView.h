/*
 * GloboHelioView.h
 *
 *  Created on: 05/10/2013
 *      Author: ezequiel
 */

#ifndef GLOBOHELIOVIEW_H_
#define GLOBOHELIOVIEW_H_
#include "ObjetoView.h"

namespace CLIENTE {
class GloboHelioView : public ObjetoView {
public:
	GloboHelioView(int x, int y, int w, int h, SDL_Texture * textura);
	virtual ~GloboHelioView();
	void dropTemplate();
};
}
#endif /* GLOBOHELIOVIEW_H_ */
