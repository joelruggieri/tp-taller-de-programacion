/*
 * FlechaScrollView.h
 *
 *  Created on: 14/09/2013
 *      Author: jonathan
 */

#ifndef FLECHASCROLLVIEW_H_
#define FLECHASCROLLVIEW_H_
#include "SDL2/SDL.h"
#include "View.h"

namespace CLIENTE {
class FlechaScrollView: public View {
private:
	bool abajo;
	SDL_Texture * textura;
	void inicializar(SDL_Texture * flecha, bool,int sleep);
	bool presionado;
	int sleep, contAbajo;

public:
	FlechaScrollView(float x, float y, float w, float h,SDL_Texture * flecha,int sleep);
	FlechaScrollView(float x, float y, float w, float h,SDL_Texture * flecha,int sleep, bool);
	virtual ~FlechaScrollView();
	void dibujarse(SDL_Renderer*);
	void dibujarse(SDL_Renderer*, SDL_Rect & dest);
	void accionar();
	void update(ViewMsj*);
	bool isUpdated();
};
}
#endif /* FLECHASCROLLVIEW_H_ */
