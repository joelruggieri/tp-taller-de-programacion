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
public:
	SimpleEditorAnguloFijo(ModeloController * , ZonaTablero *,FiguraFactory* factory, int yMaxDrag, list<float>&);
	virtual ~SimpleEditorAnguloFijo();
	void mouseMotion(int x, int y);

};

#endif /* SIMPLEEDITORANGULOFIJO_H_ */
