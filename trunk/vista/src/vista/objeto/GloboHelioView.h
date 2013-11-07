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
	GloboHelioView(float x,float y, float w, float h, SDL_Texture * textura);
	virtual ~GloboHelioView();
	void dropTemplate();
	void update(ViewMsj *);
};
}
#endif /* GLOBOHELIOVIEW_H_ */
