/*
 * Canvas.h
 *
 *  Created on: 31/08/2013
 *      Author: ezequiel
 */

#ifndef CANVAS_H_
#define CANVAS_H_
#include "SDL2/SDL_image.h"
#include "SDL2/SDL.h"
#include <iostream>
#include "View.h"
#include "Resizeable.h"
#include <list>
using namespace std;





class Canvas: public View {
private:
	SDL_Texture* imagenCanvas;
	list<Dibujable*> vistas;
	bool border;
	void generarConBorde(SDL_Rect & dest);
	void generarSinBorde(SDL_Rect & dest);
	void dibujarBorde(SDL_Renderer * renderer);
	void dibujarBordeIzquierdo(SDL_Renderer* renderer);
	void dibujarBordeDerecho(SDL_Renderer* renderer);
	void dibujarBordeSuperior(SDL_Renderer* renderer);
	void dibujarBordeInferior(SDL_Renderer* renderer);

public:
	Canvas(int x, int y, int h, int w, SDL_Texture* textura);
	void dibujarse(SDL_Renderer *);
	virtual ~Canvas();
	int ModificarFondo(char* rutaNueva);
	void agregar(Dibujable *);
	void remover(Dibujable *);
	//void Resizear(int x, int y);
	const list<Dibujable*>& getDibujables() const;
	bool isBorder() const;
	void setBorder(bool border);
	const list<Dibujable*>& getVistas();
	typedef struct RGB{
	    int r;
	    int g;
	    int b;
	} RGB;
//	static const RGB COLOR_BORDE_EXTERNO;
};

const struct Canvas::RGB COLOR_BORDE_EXTERNO = {124,117,105};
const struct Canvas::RGB COLOR_BORDE_INTERNO = {107, 84, 43};
#endif /* CANVAS_H_ */

