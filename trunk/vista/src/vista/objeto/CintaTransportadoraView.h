/*
 * CintaTransportadoraView.h
 *
 *  Created on: 05/10/2013
 *      Author: javier
 */

#ifndef VISTACINTATRANSPORTADORA_H_
#define VISTACINTATRANSPORTADORA_H_

#include "ObjetoView.h"
class SimpleEditorEstirar;

class CintaTransportadoraView: public ObjetoView {
public:
	CintaTransportadoraView(int x, int y, int w, int h,int altoModelo,int altoPlataforma, SDL_Texture * textura,SimpleEditorEstirar* controller);
	virtual ~CintaTransportadoraView();
	void dropTemplate();
	EditorNivel * getEditor();
	void update();
	void dibujarse(SDL_Renderer*);
private:
	int xEngrIzq, xEngrDer, alto, yEngranajes,altoPlataforma;
	SDL_Texture * rueda;
	typedef ObjetoView super;
	void recalcular();
	void resizear();
	void dibujarParte(SDL_Renderer * renderer, SDL_Rect & dest, float angulo, SDL_Texture* text);
};

#endif /* VISTACINTATRANSPORTADORA_H_ */
