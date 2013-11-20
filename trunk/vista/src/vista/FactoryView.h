/*
 * FactoryView.h
 *
 *  Created on: 21/09/2013
 *      Author: jonathan
 */

#ifndef FACTORYVIEW_H_
#define FACTORYVIEW_H_

#include "SDL2/SDL.h"
#include "View.h"
#include <string>
#include <iostream>
#include "SDL2/SDL_ttf.h"
#include "src/mensajes/viewMensaje/MensajeCantidadRestante.h"
namespace CLIENTE {
class FactoryView: public View {
private:
	bool debeActualizar;
	int cantAnterior, wpAnterior;
	SDL_Texture * textura;
	void dibujarFondo(SDL_Renderer *);
	void dibujarBorde(SDL_Renderer * renderer);
	void dibujarBordeIzquierdo(SDL_Renderer* renderer);
	void dibujarBordeDerecho(SDL_Renderer* renderer);
	void dibujarBordeSuperior(SDL_Renderer* renderer);
	void dibujarBordeInferior(SDL_Renderer* renderer);
	void generarConBorde(SDL_Rect & dest);
	void generarSinBorde(SDL_Rect & dest);
	void dibujarCantidad(SDL_Renderer* renderer);


	//texto
	float tamanoFuente;
	TTF_Font* fuente;
	string texto;
	SDL_Surface* surfaceTexto;
	SDL_Color color;
	SDL_Rect dest;
	SDL_Texture* textureTexto;
	typedef View super;
	int xpc, ypc;
public:
	FactoryView(float x, float y, float w, float h, SDL_Texture * textura);
	virtual ~FactoryView();
	void dibujarse(SDL_Renderer*);
	void dibujarse(SDL_Renderer*, SDL_Rect&);
	void update(ViewMsj *);
	void setYL(float yl);
	typedef struct RGBFactory {
		int r;
		int g;
		int b;
	} RGB;
	bool isUpdated();
	void resizear();
};

const struct FactoryView::RGBFactory CBORDE_EXTERNO = { 94, 139, 0 };
const struct FactoryView::RGBFactory CBORDE_INTERNO = { 22, 41, 28 };
}
#endif /* FACTORYVIEW_H_ */

