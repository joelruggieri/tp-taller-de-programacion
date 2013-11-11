/*
 * GeneralEventController.h
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#ifndef GENERALEVENTCONTROLLER_H_
#define GENERALEVENTCONTROLLER_H_


#include <list>
#include <SDL2/SDL.h>
#include "DrawController.h"
#include "src/mensajes/userEvents/UserEventVisitor.h"
#include "src/mensajes/userEvents/UserEventMsj.h"
#include "src/mensajes/internos/MensajeInternoVisitor.h"
#include "src/mensajes/internos/MensajeInterno.h"
#include "src/mensajes/internos/ConexionUsuario.h"
#include "src/mensajes/internos/StepModelo.h"
#include "src/mensajes/userEvents/CreacionMsj.h"
#include "JuegoEventsController.h"
#include "FlujoDeJuegoController.h"
#include "src/Logger.h"
#include "src/Jugador.h"
#include <map>
using namespace std;

class GeneralEventController: public UserEventVisitor, public MensajeInternoVisitor {
private:
	DrawController * drawController;
	FlujoDeJuegoController * flowController;
	map <int, JuegoEventsController * > controllers;
	Logger log;
public:
	GeneralEventController(DrawController * dController, FlujoDeJuegoController * fcontroller);
	virtual ~GeneralEventController();
	void procesarEventos(UserEventMsj *);
	void addJugador(JuegoEventsController *);
	void visit(MouseMotionMsj *);
	void visit(ClickMsj *);
	void visit(KeyMsj *);
	void visit(JugadorListo *);
	void visit(DrawEvent *);
	void visit(CreacionMsj*);
	void visit(ConexionUsuario*);
	void visit(StepModelo*);
	//ENTREGA3 AGREGAR AL VISITOR EL USEREVENT DE CREACION.
	//EN ESE METODO HAY QUE LLAMAR  AL CREARVISTA DEL JUEGOEVENTCONTROLLER.
};

#endif /* GENERALEVENTCONTROLLER_H_ */


