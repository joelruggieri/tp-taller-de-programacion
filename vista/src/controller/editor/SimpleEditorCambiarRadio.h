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
	typedef SimpleEditorNivel super;
public:
	SimpleEditorCambiarRadio(ModeloController * controller , ZonaTablero * zona,FiguraFactory* factory, int yMaxDrag);
	virtual ~SimpleEditorCambiarRadio();
	void mouseMotion(int x, int y);

	void rightClickDown(int x, int y);
	void actualizarRadio();
};

#endif /* SIMPLEEDITORCAMBIARRADIO_H_ */
