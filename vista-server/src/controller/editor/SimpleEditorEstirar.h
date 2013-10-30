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
   void actualizarAncho(float delta);
protected:
   bool estirando;
   float ultimoX, ultimoY;
public:
	SimpleEditorEstirar(ModeloController * , ZonaTablero *,FiguraFactory* factory, float yMaxDrag);
	virtual ~SimpleEditorEstirar();
	void rightClickDown(float x, float y);
	void mouseMotion(float x, float y);
	void rightClickUp(float int1, float int2);
	void setFigura(FiguraView *);
	void dropNuevaFigura(CintaTransportadoraView * v);
	void dropNuevaFigura(PlataformaView * v);
};

#endif /* SIMPLEEDITORESTIRAR_H_ */
