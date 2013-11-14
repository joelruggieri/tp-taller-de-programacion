/*
 * SimpleEditorAnguloFijo.h
 *
 *  Created on: 03/10/2013
 *      Author: jonathan
 */

#ifndef SIMPLEEDITORANGULOFIJO_H_
#define SIMPLEEDITORANGULOFIJO_H_

#include "SimpleEditorNivel.h"
class BalancinView;
class SimpleEditorAnguloFijo: public SimpleEditorNivel {
private:
   typedef SimpleEditorNivel super;
   list<float> angulosPermitidos;
   float anguloPermitidoMasCercano(float angulo);
   double start;
   unsigned int indice;
public:
	SimpleEditorAnguloFijo(ModeloController * , ZonaTablero *,FiguraFactory* factory, float yMaxDrag, list<float>);
	virtual ~SimpleEditorAnguloFijo();
	void mouseMotion(float x, float y);
	void setFigura(FiguraView *);
	void dropNuevaFigura(BalancinView*);
	void dropNuevaFigura(BolaBolicheView*);
	void dropNuevaFigura(GloboHelioView*);
	void dropNuevaFigura(GanchoView*);
	void dropNuevaFigura(PelotaJuegoView*);
	void dropNuevaFigura(VistaEngranaje*);
	void dropNuevaFigura(YunqueView*);
	void dropNuevaFigura(ClavoView*);
	EditorNivel * clone();
};

#endif /* SIMPLEEDITORANGULOFIJO_H_ */

