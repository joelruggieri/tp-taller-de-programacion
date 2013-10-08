/*
 * SimpleEditorAnguloFijo.h
 *
 *  Created on: 03/10/2013
 *      Author: jonathan
 */

#ifndef SIMPLEEDITORANGULOFIJO_H_
#define SIMPLEEDITORANGULOFIJO_H_

#include "SimpleEditorNivel.h"

class SimpleEditorAnguloFijo: public SimpleEditorNivel {
private:
   typedef SimpleEditorNivel super;
   list<float> angulosPermitidos;
   float anguloPermitidoMasCercano(float angulo);
   double start;
   unsigned int indice;
public:
	SimpleEditorAnguloFijo(ModeloController * , ZonaTablero *,FiguraFactory* factory, int yMaxDrag, list<float>&);
	virtual ~SimpleEditorAnguloFijo();
	void mouseMotion(int x, int y);
	void setFigura(FiguraView *);
};

#endif /* SIMPLEEDITORANGULOFIJO_H_ */
