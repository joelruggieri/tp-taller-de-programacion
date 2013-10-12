/*
 * EditorDeEstiramientoDeCinta.h
 *
 *  Created on: 12/10/2013
 *      Author: javier
 */

#ifndef EDITORDEESTIRAMIENTODECINTA_H_
#define EDITORDEESTIRAMIENTODECINTA_H_

#include "SimpleEditorNivel.h"
class ModeloController;
class ZonaTablero;
class FiguraFactory;

class EditorDeEstiramientoDeCinta: public SimpleEditorNivel {
public:
	EditorDeEstiramientoDeCinta(ModeloController * , ZonaTablero *,FiguraFactory* factory, int yMaxDrag);
	virtual ~EditorDeEstiramientoDeCinta();
	void rightClickDown(int x, int y);
	void mouseMotion(int x, int y);
	void rightClickUp(int int1, int int2);
private:
	void actualizarAncho(int delta);
	bool editando;
};

#endif /* EDITORDEESTIRAMIENTODECINTA_H_ */
