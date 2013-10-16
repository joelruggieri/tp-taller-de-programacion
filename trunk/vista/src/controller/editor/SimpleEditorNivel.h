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
	Dibujable * visor;
	ZonaTablero * tablero;
	void cleanAndDelete();

	FiguraFactory * figurasFactory;
	Drag * elementoDrag;
	Rotacion * rot;
	int posStartDragX;
	int posStartDragY;
	int yMaxDrag;
	void actualizarEstadoDeLaFigura(int int1, int int2);
public:
	SimpleEditorNivel(ModeloController * , ZonaTablero *,FiguraFactory* factory, int yMaxDrag);
	virtual void setFigura(FiguraView *);
	virtual ~SimpleEditorNivel();
	virtual void clickDown(int x, int y);
	virtual void clickUp(int x, int y);
	virtual void rightClickUp(int x, int y);
	virtual void rightClickDown(int x, int y);
	virtual bool isEnd();
	virtual void dibujarEdicion(SDL_Renderer *);
	virtual void mouseMotion(int x, int y);
	void dropNuevaFigura(MotorView*);
	void dropNuevaFigura(PlataformaView*);
	void dropNuevaFigura(BalancinView*);
	void dropNuevaFigura(GloboHelioView* view);
	void dropNuevaFigura(VistaCintaTransportadora* view);
	void dropNuevaFigura(BolaBolicheView* view);
	void dropNuevaFigura(PelotaJuegoView* view);
	void dropNuevaFigura(VistaEngranaje* view);
	void dropNuevaFigura(SogaView* view);
	void dropNuevaFigura(CorreaView* view);
	void dropNuevaFigura(SogaEstaticaView* view);
	void dropFigura(FiguraView*);
	void drag(FiguraView*, float, float);
};

#endif /* SIMPLEEDITORNIVEL_H_ */
