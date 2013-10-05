/*
 * SimpleEditorEstirar.h
 *
 *  Created on: 04/10/2013
 *      Author: joel
 */

#ifndef SIMPLEEDITORESTIRAR_H_
#define SIMPLEEDITORESTIRAR_H_
#include "SimpleEditorNivel.h"

class SimpleEditorEstirar: public SimpleEditorNivel{
private:
   typedef SimpleEditorNivel super;
   bool estirando;
public:
	SimpleEditorEstirar(ModeloController * , ZonaTablero *,FiguraFactory* factory, int yMaxDrag);
	virtual ~SimpleEditorEstirar();
	void rightClickDown(int x, int y);
	void mouseMotion(int x, int y);
	void rightClickUp(int int1, int int2);
};

#endif /* SIMPLEEDITORESTIRAR_H_ */
