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
   void actualizarAncho(int delta);
public:
	SimpleEditorEstirar(ModeloController * , ZonaTablero *,FiguraFactory* factory, int yMaxDrag);
	virtual ~SimpleEditorEstirar();
	void rightClickDown(int x, int y);
	void mouseMotion(int x, int y);
	void rightClickUp(int int1, int int2);
	void setFigura(FiguraView *);
	void dropNuevaFigura(VistaCintaTransportadora * v);
	void dropNuevaFigura(PlataformaView * v);
};

#endif /* SIMPLEEDITORESTIRAR_H_ */
