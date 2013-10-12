/*
 * SimpleEditorNivel.cpp
 *
 *  Created on: 03/10/2013
 *      Author: jonathan
 */

#include "SimpleEditorNivel.h"
#include "src/Logger.h"
#include "../../vista/objeto/MotorView.h"
#include "../../vista/CargadorDeTextures.h"
#include "../../vista/ViewConIcono.h"
#include "../../ConstantesVista.h"
SimpleEditorNivel::SimpleEditorNivel(ModeloController * m, ZonaTablero * t,
		FiguraFactory* factory, int yMaxDrag) {
	this->modeloController = m;
	this->tablero = t;
	this->figurasFactory = factory;
	this->elementoDrag = NULL;
	this->rot = NULL;
	this->posStartDragX = 0;
	this->posStartDragY = 0;
	this->modeloController = modeloController;
	this->yMaxDrag = yMaxDrag;
	this->finalizado = true;
	dragueando = false;
	editado = NULL;
	rotando = false;
	visor = NULL;
}

SimpleEditorNivel::~SimpleEditorNivel() {
	if (this->editado != NULL) {
		delete editado;
	}
}

void SimpleEditorNivel::dropear(FiguraView* view, Figura* figura) {
	Logger log;
	view->setModelo(figura);
	figura->setVista(view);
	log.info("Finaliza Drag");
//	if (this->tablero != NULL && this->creacion != NULL) {
	bool exitoVista = tablero->agregarFigura(view);
	bool exitoModelo = this->modeloController->crearFigura(figura);
	if (!exitoVista || !exitoModelo) {
//si uno de los dos no tuvo exito probamos rollbackeando.
		if (exitoVista) {
			tablero->removerFigura(view);
		}
		if (exitoModelo) {
			modeloController->removerFigura(figura);
		}
		if (!this->elementoDrag->isRolledBack()) {
			log.info(
					"El Drag no pudo completarse, se retorna a la posicion anterior");
			this->elementoDrag->rollBack();
			this->elementoDrag->drop();
		} else {
			delete figura;
			delete view;
			delete elementoDrag;
			elementoDrag = NULL;
			dragueando = false;
			editado = NULL;

		}
		//TODO VER QUE PASA CON LA MEMORIA ACA.
	} else {
		delete elementoDrag;
		elementoDrag = NULL;
	}
//	}
}

void SimpleEditorNivel::setFigura(FiguraView* f) {
	this->editado = f;
	this->finalizado = false;
}

void SimpleEditorNivel::dropFigura(FiguraView* view) {
	Figura* modelo = view->getModelo();
	Resizer * r = Resizer::Instance();
	float x;
	float y;
	r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
	modelo->setX(x);
	modelo->setY(100 - y);
	this->dropear(view, modelo);
}

void SimpleEditorNivel::dropNuevaFigura(MotorView* view) {

	Resizer* r = Resizer::Instance();
	float x;
	float y;
	r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
	dropear(view, this->figurasFactory->crearMotor(x, 100 - y));
}

void SimpleEditorNivel::dropNuevaFigura(PlataformaView* view) {

	Resizer* r = Resizer::Instance();
	float x;
	float y;
	r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
	dropear(view, this->figurasFactory->crearPlataforma(x, 100 - y));
}

void SimpleEditorNivel::dropNuevaFigura(BalancinView* view) {

	Resizer* r = Resizer::Instance();
	float x;
	float y;
	r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
	dropear(view, this->figurasFactory->crearBalancin(x, 100 - y));
}

void SimpleEditorNivel::clickDown(int x, int y) {
	//si no esta haciendo nada
	if (!rotando && !finalizado && !dragueando) {
		Resizer* r = Resizer::Instance();
		float lX = r->resizearDistanciaPixelX(x);
		float lY = r->resizearPosicionPixelY(y);
		this->editado->click(lX, lY);
		this->visor = editado;
		dragueando = true;

	} else {
		Logger log;
		log.warning(
				"El editor se encuentra finalizado, puede que no se haya seteado el elemento a editar");
	}
}

void SimpleEditorNivel::clickUp(int x, int y) {
	if (dragueando) {
		this->elementoDrag->drop();
		delete this->elementoDrag;
		this->dragueando = false;
		visor = NULL;
		this->finalizado = true;
	}
}

void SimpleEditorNivel::mouseMotion(int corrimientoX, int corrimientoY) {
	if (dragueando) {
		int yBack = this->elementoDrag->getYCentro();
		int xBack = this->elementoDrag->getXCentro();
		int deltaX = this->elementoDrag->getXCentro() + corrimientoX
				- this->posStartDragX;
		int deltaY = this->elementoDrag->getYCentro() + corrimientoY
				- this->posStartDragY;
		this->elementoDrag->desplazarCentroA(deltaX, deltaY);
		//si no se pudo hacer el desplazamiento no hago el corrimiento;
		this->posStartDragX = deltaX - xBack + this->posStartDragX;
		this->posStartDragY = deltaY - yBack + this->posStartDragY;
	}
	if (rotando) {
		Resizer* r = Resizer::Instance();
		this->rot->rotar(corrimientoX, r->getAltoPantalla() - corrimientoY);
		this->editado->getModelo()->setRotacion(
				this->editado->getModelo()->getRotacion()
						+ this->rot->getAngulo());
		Logger log;
		std::string mensaje_info = "Rotacion total ";
		log.concatenar(mensaje_info, this->editado->getModelo()->getRotacion());
		log.debug(mensaje_info);
	}
}

void SimpleEditorNivel::rightClickDown(int x, int y) {
	if (!rotando && !finalizado && !dragueando) {
		Resizer* r = Resizer::Instance();
		//TODO NO SE SI HAY Q CHEQUEAR ESTO.
		if (editado->getModelo() != NULL) {
			//la remuevo de todos lados.
			editado->getModelo()->makeBackUp();
			tablero->removerFigura(editado);
			this->modeloController->removerFigura(editado->getModelo());
			//Verifico si se apreto el shift tambien.
			const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
			if (keyboardState[SDL_SCANCODE_LSHIFT]) {
				cleanAndDelete();
				return;
			} else {
				this->rot = new Rotacion(this->editado->getXCentro(),
						r->getAltoPantalla() - this->editado->getYCentro(), x,
						r->getAltoPantalla() - y, 0);
				rotando = true;
				CargadorDeTextures* l = CargadorDeTextures::Instance();
				this->visor = new ViewConIcono(editado,
						l->cargarTexture(PATH_ROTACION_IMG), 2);
			}

		} else {
			delete editado;
			editado = NULL;
		}

	}
}

void SimpleEditorNivel::rightClickUp(int int1, int int2) {
	if (rotando) {
		rotando = false;
		delete visor;
		delete this->rot;
		finalizado = true;
		bool exitoVista = tablero->agregarFigura(this->editado);
		bool exitoModelo = this->modeloController->crearFigura(
				this->editado->getModelo());
		if (!exitoVista || !exitoModelo) {
			//si uno de los dos no tuvo exito probamos rollbackeando.
			if (exitoVista) {
				tablero->removerFigura(editado);
			}
			if (exitoModelo) {
				modeloController->removerFigura(editado->getModelo());
			}
			Logger log;
			editado->getModelo()->restoreBackUp();

			exitoVista = tablero->agregarFigura(this->editado);
			exitoModelo = this->modeloController->crearFigura(
					this->editado->getModelo());
			if (!exitoVista || !exitoModelo) {
				if (exitoVista) {
					tablero->removerFigura(editado);
				}
				if (exitoModelo) {
					modeloController->removerFigura(editado->getModelo());
				}
				delete this->editado->getModelo();
				delete editado;
				delete elementoDrag;
				elementoDrag = NULL;
				dragueando = false;
				editado = NULL;
			}

//			if (!this->elementoDrag->isRolledBack()) {
//				log.info(
//						"La rotacion no pudo completarse, se retorna a la posicion anterior");
//				this->editado->getModelo()->restoreBackUp();
//			} else {
//				delete this->editado->getModelo();
//				delete editado;
//				delete elementoDrag;
//				elementoDrag = NULL;
//				dragueando = false;
//				editado = NULL;

		}
		//TODO VER QUE PASA CON LA MEMORIA ACA.
	}
}

bool SimpleEditorNivel::isEnd() {
return finalizado;
}

void SimpleEditorNivel::dibujarEdicion(SDL_Renderer*r) {
if (visor != NULL)
	visor->dibujarse(r);
}

void SimpleEditorNivel::cleanAndDelete() {
delete editado->getModelo();
delete editado;
editado = NULL;
finalizado = true;
dragueando = false;
rotando = false;
}

void SimpleEditorNivel::dropNuevaFigura(BolaBolicheView* view) {
Resizer* r = Resizer::Instance();
float x;
float y;
r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
dropear(view, this->figurasFactory->crearBolaBoliche(x, 100 - y));
}

void SimpleEditorNivel::drag(FiguraView* figuras, float x, float y) {
//TENGO QUE AVISAR AL JUEGO QUE SUSPENDA VISTA.
Logger log;
Resizer * r = Resizer::Instance();
if (!dragueando) {
	r->adaptarPosicionLogica(x, y, this->posStartDragX, this->posStartDragY);
	this->elementoDrag = new Drag(editado,
			Resizer::Instance()->resizearPosicionLogicaY(yMaxDrag));
	log.info("Comienza Drag");
}
tablero->removerFigura(editado);
if (editado->getModelo() != NULL) {
	this->modeloController->removerFigura(editado->getModelo());
}
mouseMotion(posStartDragX, posStartDragY);
}

void SimpleEditorNivel::dropNuevaFigura(GloboHelioView* view) {
Resizer* r = Resizer::Instance();
float x;
float y;
r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
dropear(view, this->figurasFactory->crearGloboHelio(x, 100 - y));
//	dropear(view, this->figurasFactory->crearGloboHelio(x, 100 - y));
}

void SimpleEditorNivel::dropNuevaFigura(VistaCintaTransportadora* view) {
Resizer* r = Resizer::Instance();
float x;
float y;
r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
dropear(view, this->figurasFactory->crearCintaTransportadora(x, 100 - y));
}

void SimpleEditorNivel::dropNuevaFigura(PelotaJuegoView* view) {
Resizer* r = Resizer::Instance();
float x;
float y;
r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
dropear(view, this->figurasFactory->crearPelotaJuego(x, 100 - y));
}
