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
public:
	SimpleEditorAnguloFijo(ModeloController * , ZonaTablero *,FiguraFactory* factory, int yMaxDrag);
	virtual ~SimpleEditorAnguloFijo();
	virtual void rightClickUp(int x, int y);
	virtual void rightClickDown(int x, int y);
	virtual void mouseMotion(int x, int y);

};

#endif /* SIMPLEEDITORANGULOFIJO_H_ */
