/*
 * EditorUnion.h
 *
 *  Created on: 15/10/2013
 *      Author: jonathan
 */

#ifndef EDITORUNION_H_
#define EDITORUNION_H_

#include "SimpleEditorNivel.h"

class EditorUnion: public SimpleEditorNivel{
private:
	bool primerClick;
	typedef SimpleEditorNivel super;
public:


	EditorUnion(ModeloController * , ZonaTablero *,FiguraFactory* factory, int yMaxDrag);
	void setFigura(FiguraView *);
	virtual ~EditorUnion();
	void clickDown(int x, int y);
	void rightClickUp(int x, int y);
	void rightClickDown(int x, int y);
	void dibujarEdicion(SDL_Renderer *);
	void dropear(FiguraView* view, Figura* figura);

};

#endif /* EDITORUNION_H_ */
