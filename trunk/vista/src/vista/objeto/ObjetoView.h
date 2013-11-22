/*
 * ObjetoView.h
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#ifndef OBJETOVIEW_H_
#define OBJETOVIEW_H_

#include "../figura/FiguraView.h"
namespace CLIENTE {
class ObjetoView: public FiguraView {
public:
	ObjetoView(float x, float y, float w, float h,int numeroEvent, SDL_Texture * textura);
	ObjetoView(float x, float y, float w, float h, int layer,int numeroEvent, SDL_Texture * textura);
	virtual ~ObjetoView();
};

}
#endif /* OBJETOVIEW_H_ */
