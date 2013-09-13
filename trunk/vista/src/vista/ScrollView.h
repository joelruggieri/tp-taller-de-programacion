/*
 * ScrollView.h
 *
 *  Created on: 13/09/2013
 *      Author: jonathan
 */

#ifndef SCROLLVIEW_H_
#define SCROLLVIEW_H_

#include "View.h"
#include "SDL2/SDL.h"
class ScrollView: public View {
private:
	bool abajo;
	SDL_Texture * textura;
	void inicializar(SDL_Texture * flecha, bool);
public:
	ScrollView(int x, int y, int w, int h,SDL_Texture * flecha);
	ScrollView(int x, int y, int w, int h,SDL_Texture * flecha, bool);
	virtual ~ScrollView();
	bool isAbajo() const;
	void setAbajo(bool abajo);
	void dibujarse(SDL_Renderer*);
};

#endif /* SCROLLVIEW_H_ */
