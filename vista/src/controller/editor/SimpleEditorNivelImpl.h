/*
 * SimpleEditorNivelImpl.h
 *
 *  Created on: 16/10/2013
 *      Author: jonathan
 */

#ifndef SIMPLEEDITORNIVELIMPL_H_
#define SIMPLEEDITORNIVELIMPL_H_

#include "SimpleEditorNivel.h"

class SimpleEditorNivelImpl: public SimpleEditorNivel {
public:
	SimpleEditorNivelImpl(ModeloController * , ZonaTablero *,FiguraFactory* factory, int yMaxDrag);
	virtual ~SimpleEditorNivelImpl();
};

#endif /* SIMPLEEDITORNIVELIMPL_H_ */
