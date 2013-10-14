/*
 * EditorDeEstiramientoDeCinta.cpp
 *
 *  Created on: 12/10/2013
 *      Author: javier
 */

#include "EditorDeEstiramientoDeCinta.h"

#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_stdinc.h>
#include <src/figura/Figura.h>
#include <src/ModeloController.h>
#include <src/objeto/CintaTransportadora.h>

#include "../../ConstantesVista.h"
#include "../../vista/CargadorDeTextures.h"
#include "../../vista/Dibujable.h"
#include "../../vista/figura/FiguraView.h"
#include "../../vista/View.h"
#include "../../vista/ViewConIcono.h"
#include "../Resizer.h"
#include "../zonaDragAndDrop/ZonaDragAndDrop.h"
#include "../zonaDragAndDrop/ZonaTablero.h"
#include "SimpleEditorAnguloFijo.h"

class FiguraFactory;


EditorDeEstiramientoDeCinta::EditorDeEstiramientoDeCinta(ModeloController * controlador, ZonaTablero *tablero, FiguraFactory* factory, int yMaxDrag): SimpleEditorNivel(controlador,tablero,factory,yMaxDrag)  {
	editando = false;
}

EditorDeEstiramientoDeCinta::~EditorDeEstiramientoDeCinta() {
	// TODO Auto-generated destructor stub
}


void EditorDeEstiramientoDeCinta::rightClickDown(int x, int y){
		tablero->removerFigura(editado);
		this->modeloController->removerFigura(editado->getModelo());
		const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
		if (keyboardState[SDL_SCANCODE_LCTRL]) {
			editando = true;
			CargadorDeTextures* l = CargadorDeTextures::Instance();
			this->visor = new ViewConIcono(editado,
			l->cargarTexture(PATH_AGRANDAR_IMG),0);

		}else
			SimpleEditorNivel::rightClickDown(x,y);
}

void EditorDeEstiramientoDeCinta::actualizarAncho(int delta){
//

	CintaTransportadora* cinta = dynamic_cast<CintaTransportadora*>(this->editado->getModelo());
	Resizer* r = Resizer::Instance();
	float wNuevo = 0;
	float hNuevo = 0;
	int aux = 0;
	r->adaptarDimensionPixel(this->editado->getW() + delta,aux,wNuevo,hNuevo);
	cinta->setLongitud(wNuevo);

	this->editado->setW(r->resizearDistanciaLogicaX(cinta->getLongitud()+2*RADIO_EJE_CINTA_LOG));
}

void EditorDeEstiramientoDeCinta::mouseMotion(int x, int y) {
	int posFinalDerecha = this->editado->getXCentro() + (this->editado->getW()/2);
	int posFinalIzquierda = this->editado->getXCentro() - (this->editado->getW()/2);
	int delta;
	if (editando && !dragueando) {
		if((x > this->editado->getXCentro() + (this->editado->getW()/2)) || (x > this->editado->getXCentro())){
			delta = x - posFinalDerecha;
			this->actualizarAncho(delta);
		}
		else if((x < this->editado->getXCentro() - (this->editado->getW()/2)) || (x < this->editado->getXCentro())){
			delta = posFinalIzquierda - x;
			this->actualizarAncho(delta);
		}
	}else
		SimpleEditorNivel::mouseMotion(x,y);
}

void EditorDeEstiramientoDeCinta::rightClickUp(int int1, int int2) {
	if (editando) {
		tablero->agregarFigura(this->editado);
		this->modeloController->crearFigura(this->editado->getModelo());
		editando = false;
		delete visor;
		visor = NULL;
		finalizado = true;
	}else
		SimpleEditorNivel::rightClickUp(int1,int2);
}

