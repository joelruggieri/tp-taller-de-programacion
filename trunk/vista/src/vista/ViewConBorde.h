/*
 * ViewConBorde.h
 *
 *  Created on: 22/09/2013
 *      Author: jonathan
 */

#ifndef VIEWCONBORDE_H_
#define VIEWCONBORDE_H_
#include "View.h"
#include "SDL2/SDL.h"

class ViewConBorde: public View {
private:
	View * decorable;
	void dibujarBorde(SDL_Renderer * renderer);
	void dibujarBordeIzquierdo(SDL_Renderer* renderer);
	void dibujarBordeDerecho(SDL_Renderer* renderer);
	void dibujarBordeSuperior(SDL_Renderer* renderer);
	void dibujarBordeInferior(SDL_Renderer* renderer);
	void generarConBorde(SDL_Rect & dest);
	void generarSinBorde(SDL_Rect & dest);
	bool mantenerTamanio;
public:
	ViewConBorde(View* view);
	virtual ~ViewConBorde();
	virtual void dibujarse(SDL_Renderer*);
	virtual void dibujarse(SDL_Renderer*, SDL_Rect&);
	typedef struct RGB{
	    int r;
	    int g;
	    int b;
	} RGB;
	void resizear();
	int getH() const;
	int getW() const;
	int getX() const;
	int getY() const;
	int getXCentro() const;
	int getYCentro() const;
	//desplaza la vista en x y en y;
	void desplazarCentroA(int x, int y);
	void setH(int h);
	void setW(int w);
	void setXc(int xc);
	void setYc(int yc);
	void setTamanioOriginal(bool);
};
const struct ViewConBorde::RGB COLOR_BORDE_EXTERNO = {94,139,0};
const struct ViewConBorde::RGB COLOR_BORDE_INTERNO = {22, 41, 28};
#endif /* VIEWCONBORDE_H_ */
