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
	CintaTransportadoraView(float x, float y, float ancho, SimpleEditorEstirar* controller);
	virtual ~CintaTransportadoraView();
	void dropTemplate();
	EditorNivel * getEditor();
//	void update();
	void dibujarse(SDL_Renderer*);
private:
	float ancho;
	typedef ObjetoView super;
	int getLayer();
};

#endif /* VISTACINTATRANSPORTADORA_H_ */
