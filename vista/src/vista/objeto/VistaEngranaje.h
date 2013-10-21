/*
 * VistaEngranaje.h
 *
 *  Created on: 12/10/2013
 *      Author: javier
 */

#ifndef VISTAENGRANAJE_H_
#define VISTAENGRANAJE_H_
	#include "ObjetoView.h"
class SimpleEditorAnguloFijo;
class SDL_Texture;

class VistaEngranaje: public ObjetoView {
	typedef FiguraView super;
public:
	VistaEngranaje(int x, int y, int w, int h, SDL_Texture * textura, SimpleEditorAnguloFijo * editor);
	virtual ~VistaEngranaje();
	void dropTemplate();
	EditorNivel * getEditor();
	void  update();
};

#endif /* VISTAENGRANAJE_H_ */
