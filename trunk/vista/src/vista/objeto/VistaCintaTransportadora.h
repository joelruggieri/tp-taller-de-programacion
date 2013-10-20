/*
 * VistaCintaTransportadora.h
 *
 *  Created on: 05/10/2013
 *      Author: javier
 */

#ifndef VISTACINTATRANSPORTADORA_H_
#define VISTACINTATRANSPORTADORA_H_

#include "ObjetoView.h"
class SimpleEditorEstirar;

class VistaCintaTransportadora: public ObjetoView {
public:
	VistaCintaTransportadora(int x, int y, int w, int h, SDL_Texture * textura,SimpleEditorEstirar* controller);
	virtual ~VistaCintaTransportadora();
	void dropTemplate();
	EditorNivel * getEditor();
	void update();
private:
	typedef ObjetoView super;
	void dibujarParte(SDL_Renderer * renderer, SDL_Rect & dest, float angulo, SDL_Texture* text);
};

#endif /* VISTACINTATRANSPORTADORA_H_ */
