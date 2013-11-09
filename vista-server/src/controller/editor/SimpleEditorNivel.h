/*
 * SimpleEditorNivel.h
 *
 *  Created on: 03/10/2013
 *      Author: jonathan
 */

#ifndef SIMPLEEDITORNIVEL_H_
#define SIMPLEEDITORNIVEL_H_

#include "EditorNivel.h"
#include "../../vista/figura/FiguraView.h"
#include "../DropController.h"
#include "../zonaDragAndDrop/ZonaTablero.h"
#include "src/ModeloController.h"
#include "../Drag.h"
#include "../../modelo/Rotacion.h"

class SimpleEditorNivel: public EditorNivel,public DropController {
protected:
	ModeloController * modeloController;
	virtual void dropear(FiguraView* view, Figura* figura);
	bool finalizado;
	FiguraView * editado;
	bool dragueando;
	bool rotando;
	ZonaTablero * tablero;
	void cleanAndDelete();

	FiguraFactory * figurasFactory;
	Drag * elementoDrag;
	Rotacion * rot;
	float posStartDragX,posStartDragY,yMaxDrag;
	void actualizarEstadoDeLaFigura(float int1, float int2);
public:
	SimpleEditorNivel(ModeloController * , ZonaTablero *,FiguraFactory* factory, float yMaxDrag);
	virtual void setFigura(FiguraView *);
	virtual ~SimpleEditorNivel();
	virtual void clickDown(float x, float y);
	virtual void clickUp(float x, float y);
	virtual void rightClickUp(float x, float y);
	virtual void rightClickDown(float x, float y);
	virtual bool isEnd();
	virtual void dibujarEdicion(list<ViewMsj* > &);
	virtual void mouseMotion(float x, float y);
	void dropNuevaFigura(PlataformaView*);
	EditorNivel * clone();
//
	void dropFigura(FiguraView*);
	void drag(FiguraView*, float, float);
};

#endif /* SIMPLEEDITORNIVEL_H_ */
