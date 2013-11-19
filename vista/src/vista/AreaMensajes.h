/*
 * AreaMensajes.h
 *
 *  Created on: 19/11/2013
 *      Author: ezequiel
 */

#ifndef AREAMENSAJES_H_
#define AREAMENSAJES_H_
#include "View.h"
#include "SDL2/SDL_ttf.h"
#define TAM_FUENTE 25
namespace CLIENTE {

class AreaMensajes : public View {
public:
	AreaMensajes(float x, float y, float w, float h, SDL_Texture*, string mensaje);
	virtual ~AreaMensajes();
	void dibujarse(SDL_Renderer*);
   void dibujarse(SDL_Renderer*, SDL_Rect&);
	void update(ViewMsj *);
//		 void resize();
		 bool isUpdated();
	void setMensaje(string mensaje);
	void resizear();


private:
	float tamanoFuente;
	SDL_Texture* textura ;
	TTF_Font* fuente ;
	 string texto ;
	 SDL_Surface* surfaceTexto;
	 SDL_Color color;
	 typedef View super;
};

} /* namespace CLIENTE */
#endif /* AREAMENSAJES_H_ */
