/*
 * SimpleEditorSoga.h
 *
 *  Created on: Oct 5, 2013
 *      Author: matias
 */

#ifndef SIMPLEEDITORSOGA_H_
#define SIMPLEEDITORSOGA_H_

#include "EditorNivel.h"
#include "../../vista/figura/FiguraView.h"
#include "../../vista/objeto/PlataformaView.h"
#include "../../vista/objeto/GloboHelioView.h"
#include "../../vista/objeto/BalancinView.h"
#include "../../vista/objeto/VistaCintaTransportadora.h"
#include "../../vista/figura/FiguraView.h"
#include "../../vista/objeto/BolaBolicheView.h"
#include "../../vista/objeto/PelotaJuegoView.h"
#include "../../vista/objeto/VistaEngranaje.h"
#include "../DropController.h"
#include "../zonaDragAndDrop/ZonaTablero.h"
#include "src/ModeloController.h"
#include "../Drag.h"
#include "../../modelo/Rotacion.h"

class SimpleEditorSoga: public EditorNivel,public DropController {
private:
	FiguraFactory * figurasFactory;
	Drag * elementoDrag;
	Rotacion * rot;
	int posStartDragX;
	int posStartDragY;
	int yMaxDrag;
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
public:
	SimpleEditorSoga(ModeloController * , ZonaTablero *,FiguraFactory* factory, int yMaxDrag);
	void setFigura(FiguraView *);
	virtual ~SimpleEditorSoga();
	virtual void clickDown(int x, int y);
	virtual void clickUp(int x, int y);
	virtual void rightClickUp(int x, int y);
	virtual void rightClickDown(int x, int y);
	virtual bool isEnd();
	virtual void dibujarEdicion(SDL_Renderer *);
	virtual void mouseMotion(int x, int y);
	void dropNuevaFigura(MotorView*);
	void dropNuevaFigura(PlataformaView*);
	void dropNuevaFigura(GloboHelioView*);
	void dropNuevaFigura(BalancinView* view);
	void dropNuevaFigura(VistaCintaTransportadora*);
	void dropNuevaFigura(BolaBolicheView* view);
	void dropNuevaFigura(PelotaJuegoView* view);
	void dropNuevaFigura(VistaEngranaje* view);
	void dropFigura(FiguraView*);
	void drag(FiguraView*, float, float);
};

#endif /* SIMPLEEDITORSOGA_H_ */
