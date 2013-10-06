/*
 * PelotaJuegoView.h
 *
 *  Created on: 06/10/2013
 *      Author: ezequiel
 */

#ifndef PELOTAJUEGOVIEW_H_
#define PELOTAJUEGOVIEW_H_
#include "ObjetoView.h"
class SimpleEditorAnguloFijo;
struct SDL_Texture;

class PelotaJuegoView : public ObjetoView {
public:
	PelotaJuegoView(int x, int y, int w, int h, SDL_Texture * textura, SimpleEditorAnguloFijo * editor);
	virtual ~PelotaJuegoView();
	void dropTemplate();
	EditorNivel * getEditor();
};

#endif /* PELOTAJUEGOVIEW_H_ */
