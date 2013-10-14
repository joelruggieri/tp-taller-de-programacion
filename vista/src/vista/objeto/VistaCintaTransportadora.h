/*
 * VistaCintaTransportadora.h
 *
 *  Created on: 05/10/2013
 *      Author: javier
 */

#ifndef VISTACINTATRANSPORTADORA_H_
#define VISTACINTATRANSPORTADORA_H_

#include "ObjetoView.h"
class EditorDeEstiramientoDeCinta;

class VistaCintaTransportadora: public ObjetoView {
public:
	VistaCintaTransportadora(int x, int y, int w, int h, SDL_Texture * textura,EditorDeEstiramientoDeCinta* controller);
	virtual ~VistaCintaTransportadora();
	void dropTemplate();
	EditorNivel * getEditor();
	void dibujarse(SDL_Renderer * renderer, SDL_Rect & dest);
private:
	void dibujarParte(SDL_Renderer * renderer, SDL_Rect & dest, float angulo, SDL_Texture* text);
	SDL_Texture *pieza, *rueda;
};

#endif /* VISTACINTATRANSPORTADORA_H_ */
