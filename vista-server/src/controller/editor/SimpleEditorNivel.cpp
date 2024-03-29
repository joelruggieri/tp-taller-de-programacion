/*
 * SimpleEditorNivel.cpp
 *
 *  Created on: 03/10/2013
 *      Author: jonathan
 */

#include "SimpleEditorNivel.h"
#include "src/Logger.h"
#include "../../ConstantesVista.h"
SimpleEditorNivel::SimpleEditorNivel(ModeloController * m, ZonaTablero * t, FiguraFactory* factory, float yMaxDrag) {
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
//	cout << "x: " << figura->getX() << " y: " << figura->getY() << endl;
	if (!exitoVista || !exitoModelo) {
//si uno de los dos no tuvo exito probamos rollbackeando.
		if (exitoVista) {
			tablero->removerFigura(view);
		}
		if (exitoModelo) {
			modeloController->removerFigura(figura);
		}
		if (!this->elementoDrag->isRolledBack()) {
			log.info("El Drag no pudo completarse, se retorna a la posicion anterior");
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
//	} else {
//		Resizer * r= Resizer::Instance();
//		Transformacion trans;
//		trans.traslacion(0, 100);
//		trans.escalar(r->getRelacionX(), r->getRelacionY());
//		trans.invertir(false, true);
//		trans.setVector(figura->getX(), figura->getY());
//		view->update(trans);
//		delete elementoDrag;
//		elementoDrag = NULL;
	}
//	}
}

void SimpleEditorNivel::setFigura(FiguraView* f) {
	this->editado = f;
	this->finalizado = false;
}

void SimpleEditorNivel::dropFigura(FiguraView* view) {
	Figura* modelo = view->getModelo();
	modelo->setPosicion(view->getXCentro(), view->getYCentro());
	this->dropear(view, modelo);
}

void SimpleEditorNivel::dropNuevaFigura(PlataformaView* view) {

	dropear(view, this->figurasFactory->crearPlataforma(view->getXCentro(), view->getYCentro(),this->numeroJugadorDuenio));
}

void SimpleEditorNivel::dropNuevaFigura(CarritoView* view) {

	dropear(view, this->figurasFactory->crearCarrito(view->getXCentro(), view->getYCentro(),this->numeroJugadorDuenio));
}

/*void SimpleEditorNivel::dropNuevaFigura(TijeraView* view) {

	dropear(view, this->figurasFactory->crearTijera(view->getXCentro(), view->getYCentro(),this->numeroJugadorDuenio));
}*/

void SimpleEditorNivel::clickDown(float x, float y) {
	//si no esta haciendo nada
	if (!rotando && !finalizado && !dragueando) {
		//TODO ESTE PASAJE DE COORDENADAS QUEDÓ VIEJO, USAR LA TL.
		this->editado->click(x, y);
		dragueando = true;

	} else {
		Logger log;
		log.warning("El editor se encuentra finalizado, puede que no se haya seteado el elemento a editar");
	}
}

void SimpleEditorNivel::clickUp(float x, float y) {
	if (dragueando) {
		this->elementoDrag->drop();
		delete this->elementoDrag;
		this->dragueando = false;
		this->finalizado = true;
	}
}

void SimpleEditorNivel::mouseMotion(float corrimientoX, float corrimientoY) {
	if (dragueando) {
		float yBack = this->elementoDrag->getYCentro();
		float xBack = this->elementoDrag->getXCentro();
		float deltaX = this->elementoDrag->getXCentro() + corrimientoX - this->posStartDragX;
		float deltaY = this->elementoDrag->getYCentro() + corrimientoY - this->posStartDragY;
		this->elementoDrag->desplazarCentroA(deltaX, deltaY);
		//si no se pudo hacer el desplazamiento no hago el corrimiento;
		this->posStartDragX = deltaX - xBack + this->posStartDragX;
		this->posStartDragY = deltaY - yBack + this->posStartDragY;
	}
	if (rotando) {
		this->rot->rotar(corrimientoX, corrimientoY);
		this->editado->getModelo()->setRotacion(this->editado->getModelo()->getRotacion() + this->rot->getAngulo());
		Logger log;
		std::string mensaje_info = "Rotacion total ";
		log.concatenar(mensaje_info, this->editado->getModelo()->getRotacion());
		log.debug(mensaje_info);
	}
}

void SimpleEditorNivel::rightClickDown(float x, float y) {
	if (!rotando && !finalizado && !dragueando) {
		//TODO NO SE SI HAY Q CHEQUEAR ESTO.
		if (editado->getModelo() != NULL) {
			//la remuevo de todos lados.
			editado->getModelo()->makeBackUp();
			tablero->removerFigura(editado);
			this->modeloController->removerFigura(editado->getModelo());
			//Verifico si se apreto el shift tambien.
//			const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
			if (this->isShift()) {
				cleanAndDelete();
				modeloController->cleanDeletes();
				return;
			} else {
				this->rot = new Rotacion(this->editado->getXCentro(), this->editado->getYCentro(), x, y, 0);
				rotando = true;
			}

		} else {
			delete editado;
			editado = NULL;
		}

	}
}

void SimpleEditorNivel::actualizarEstadoDeLaFigura(float int1, float int2) {
	bool exitoVista = tablero->agregarFigura(this->editado);
	bool exitoModelo = this->modeloController->crearFigura(this->editado->getModelo());
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
//		std::cout << " " << editado->getModelo()->getAncho() << std::endl;
		exitoVista = tablero->agregarFigura(this->editado);
		exitoModelo = this->modeloController->crearFigura(this->editado->getModelo());
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
}

void SimpleEditorNivel::rightClickUp(float int1, float int2) {
	if (rotando) {
		rotando = false;
		delete this->rot;
		finalizado = true;
		this->actualizarEstadoDeLaFigura(int1, int2);
		/*bool exitoVista = tablero->agregarFigura(this->editado);
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

		 }*/
		//TODO VER QUE PASA CON LA MEMORIA ACA.
	}
}

bool SimpleEditorNivel::isEnd() {
	return finalizado;
}

void SimpleEditorNivel::dibujarEdicion(list<ViewMsj *> & lista) {
	if (editado != NULL)
		editado->dibujarse(lista);
}

void SimpleEditorNivel::cleanAndDelete() {
	delete editado->getModelo();
	delete editado;
	editado = NULL;
	finalizado = true;
	dragueando = false;
	rotando = false;
}

void SimpleEditorNivel::drag(FiguraView* figuras, float x, float y) {
//TENGO QUE AVISAR AL JUEGO QUE SUSPENDA VISTA.
	Logger log;
	if (!dragueando) {
		this->posStartDragX = x;
		this->posStartDragY = y;
		this->elementoDrag = new Drag(editado, yMaxDrag);
		log.info("Comienza Drag");
	}
	tablero->removerFigura(editado);
	if (editado->getModelo() != NULL) {
		this->modeloController->removerFigura(editado->getModelo());
	}
	mouseMotion(posStartDragX, posStartDragY);
}

EditorNivel* SimpleEditorNivel::clone() {
	return new SimpleEditorNivel(modeloController, tablero, figurasFactory, yMaxDrag);
}

void SimpleEditorNivel::dropNuevaFigura(MonitorView*) {
	//no va a pasar nunca.
}
