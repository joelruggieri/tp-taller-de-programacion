/*
 * SimpleEditorSoga.cpp
 *
 *  Created on: Oct 5, 2013
 *      Author: matias
 */

#include "SimpleEditorSoga.h"
#include "src/Logger.h"
#include "../../vista/objeto/MotorView.h"
#include "../../vista/CargadorDeTextures.h"
#include "../../vista/ViewConIcono.h"
#include "src/figura/Enganche.h"

SimpleEditorSoga::SimpleEditorSoga(ModeloController * m, ZonaTablero * t,
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

SimpleEditorSoga::~SimpleEditorSoga() {
	if (this->editado != NULL) {
		delete editado;
	}
}

void SimpleEditorSoga::dropear(FiguraView* view, Figura* figura) {
	Logger log;
	view->setModelo(figura);
	figura->setVista(view);
	log.info("Finaliza Drag");
	//Figura* figuraA = this->modeloController->pickUp()
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

void SimpleEditorSoga::dropNuevaFigura(CirculoView* view) {
	Resizer* r = Resizer::Instance();
	float x;
	float y;
	r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
	dropear(view, this->figurasFactory->crearCirculo(x, y));
}


void SimpleEditorSoga::setFigura(FiguraView* f) {
	this->editado = f;
	this->finalizado = false;
}

void SimpleEditorSoga::dropFigura(FiguraView* view) {
	Figura* modelo = view->getModelo();
	Resizer * r = Resizer::Instance();
	float x;
	float y;
	r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
	modelo->setX(x);
	modelo->setY(100 - y);
	this->dropear(view, modelo);
}

void SimpleEditorSoga::dropNuevaFigura(RuedaView* view) {
	Resizer* r = Resizer::Instance();
	float x;
	float y;
	r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
	dropear(view, this->figurasFactory->crearRueda(x, y));
}


void SimpleEditorSoga::dropNuevaFigura(PelotaView* view) {
	Resizer* r = Resizer::Instance();
	float x;
	float y;
	r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
	dropear(view, this->figurasFactory->crearPelota(x, y));
}

void SimpleEditorSoga::dropNuevaFigura(MotorView* view) {

	Resizer* r = Resizer::Instance();
	float x;
	float y;
	r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
	dropear(view, this->figurasFactory->crearMotor(x, 100 - y));
}

void SimpleEditorSoga::dropNuevaFigura(GloboHelioView* view) {
	Resizer* r = Resizer::Instance();
	float x;
	float y;
	r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
	dropear(view, this->figurasFactory->crearGloboHelio(x,100-y));
//	dropear(view, this->figurasFactory->crearGloboHelio(x, 100 - y));
}

void SimpleEditorSoga::dropNuevaFigura(PlataformaView* view) {

	Resizer* r = Resizer::Instance();
	float x;
	float y;
	r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
	dropear(view, this->figurasFactory->crearPlataforma(x, 100 - y));
}

void SimpleEditorSoga::clickDown(int x, int y) {
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
		log.warning("El editor se encuentra finalizado, puede que no se haya seteado el elemento a editar");
	}
}

void SimpleEditorSoga::clickUp(int x, int y) {
	Logger log;
	if (dragueando) {
		Figura* objetoA = this->modeloController->pickUp(x, y);//Aca que coordenadas van?
		if(objetoA != NULL){
			Lista_Enganches listaA = objetoA->getEnganches();
			if(listaA.size() != 0){
				//Poner aca la creacion del nodo de la soga.
				log.info("El elemento sobre el que se tiro la soga tiene enganches.");
			}
			else{
				//El elemento no se puede enganchar.
				log.info("El elemento sobre el que se tiro la soga no tiene enganches.");
			}
		}
		else{
			//No se tiro sobre un elemento
			log.info("No se tiro la soga sobre un elemento.");
			delete this->elementoDrag;
			this->dragueando = false;
			visor = NULL;
			this->finalizado = true;
		}
	}
}

void SimpleEditorSoga::mouseMotion(int corrimientoX, int corrimientoY) {
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

void SimpleEditorSoga::rightClickDown(int x, int y) {
	if (!rotando && !finalizado && !dragueando) {
		Resizer* r = Resizer::Instance();
		//TODO NO SE SI HAY Q CHEQUEAR ESTO.
		if (editado->getModelo() != NULL) {
			//la remuevo de todos lados.
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
						l->cargarTexture("resource/rotacion.png"), 2);
			}

		} else {
			delete editado;
			editado = NULL;
		}

	}
}

void SimpleEditorSoga::rightClickUp(int int1, int int2) {
	if (rotando) {
		tablero->agregarFigura(this->editado);
		this->modeloController->crearFigura(this->editado->getModelo());
		rotando = false;
		delete visor;
		delete this->rot;
		finalizado = true;
	}
}

bool SimpleEditorSoga::isEnd() {
	return finalizado;
}

void SimpleEditorSoga::dibujarEdicion(SDL_Renderer*r) {
	if (visor != NULL )	visor->dibujarse(r) ;
}

void SimpleEditorSoga::cleanAndDelete() {
	delete editado->getModelo();
	delete editado;
	editado = NULL;
	finalizado = true;
	dragueando = false;
	rotando = false;
}

void SimpleEditorSoga::dropNuevaFigura(BalancinView* view) {
	Resizer* r = Resizer::Instance();
	float x;
	float y;
	r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
	dropear(view, this->figurasFactory->crearMotor(x, 100 - y));
}

void SimpleEditorSoga::dropNuevaFigura(BolaBolicheView* view) {
//	Resizer* r = Resizer::Instance();
//	float x;
//	float y;
//	r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
//	dropear(view, this->figurasFactory->crearBolaBoliche(x, 100 - y));
}

void SimpleEditorSoga::dropNuevaFigura(PelotaJuegoView* view) {
//	Resizer* r = Resizer::Instance();
//	float x;
//	float y;
//	r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
//	dropear(view, this->figurasFactory->crearPelotaJuego(x, 100 - y));
}

void SimpleEditorSoga::dropNuevaFigura(VistaCintaTransportadora* vista) {
	Resizer* r = Resizer::Instance();
	float x;
	float y;
	r->adaptarPosicionPixel(vista->getXCentro(), vista->getYCentro(), x, y);
	dropear(vista, this->figurasFactory->crearCintaTransportadora(x, 100 - y));
}

void SimpleEditorSoga::drag(FiguraView* figuras, float x, float y) {
	//TENGO QUE AVISAR AL JUEGO QUE SUSPENDA VISTA.
	Logger log;
	Resizer * r = Resizer::Instance();
	if (!dragueando) {
		r->adaptarPosicionLogica(x, y, this->posStartDragX,
				this->posStartDragY);
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

