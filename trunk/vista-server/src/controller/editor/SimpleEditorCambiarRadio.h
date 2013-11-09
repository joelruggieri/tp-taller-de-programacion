/*
 * SimpleEditorCambiarRadio.h
 *
 *  Created on: 16/10/2013
 *      Author: ezequiel
 */
#include "SimpleEditorEstirar.h"
#ifndef SIMPLEEDITORCAMBIARRADIO_H_
#define SIMPLEEDITORCAMBIARRADIO_H_
class SimpleEditorCambiarRadio  : public SimpleEditorEstirar {
	typedef SimpleEditorEstirar super;
public:
	SimpleEditorCambiarRadio(ModeloController * controller , ZonaTablero * zona,FiguraFactory* factory, float yMaxDrag);
	virtual ~SimpleEditorCambiarRadio();
	void mouseMotion(float x, float y);
	EditorNivel * clone();

//	void rightClickDown(int x, int y);
};

#endif /* SIMPLEEDITORCAMBIARRADIO_H_ */
