/*
 * VistaCintaTransportadora.h
 *
 *  Created on: 05/10/2013
 *      Author: javier
 */

#ifndef VISTACINTATRANSPORTADORA_H_
#define VISTACINTATRANSPORTADORA_H_

#include "ObjetoView.h"
class SimpleEditorAnguloFijo;

class VistaCintaTransportadora: public ObjetoView {
public:
	VistaCintaTransportadora(int x, int y, int w, int h, SDL_Texture * textura,SimpleEditorAnguloFijo* controller);
	virtual ~VistaCintaTransportadora();
	void dropTemplate();
	EditorNivel * getEditor();
};

#endif /* VISTACINTATRANSPORTADORA_H_ */
