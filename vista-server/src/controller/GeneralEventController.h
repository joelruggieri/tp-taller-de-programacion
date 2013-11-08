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
#include "JuegoEventsController.h"
#include "src/Logger.h"
#include "src/Jugador.h"
#include <map>
using namespace std;



//ENTREGA3 REFACTOR HAY QUE HACER QUE TENGA LOS 4 JUEGOS EVENT CONTROLLERS Y YA OLVIDARSE DE LA GENERALIDAD YA QUE SACAMOS TODA BARRA DE CAMBIAR FONDO Y DEMAS
//SE PUEDE PROGRAMAR OTRO GENERALEVENTCONTROLLER Y NO TOCAR ESTE.
class GeneralEventController: public UserEventVisitor, public MensajeInternoVisitor {
private:
	DrawController * drawController;
	map <int, JuegoEventsController * > controllers;
	Logger log;
public:
	GeneralEventController(std::list<Jugador*>& jugadoresNivel, DrawController * dController);
	virtual ~GeneralEventController();
	void procesarEventos(UserEventMsj *);
	void addJugador(JuegoEventsController *);
	void visit(MouseMotionMsj *);
	void visit(ClickMsj *);
	void visit(KeyMsj *);
	void visit(JugadorListo *);
	void visit(DrawEvent *);
	//ENTREGA3 AGREGAR AL VISITOR EL USEREVENT DE CREACION.
	//EN ESE METODO HAY QUE LLAMAR  AL CREARVISTA DEL JUEGOEVENTCONTROLLER.
};

#endif /* GENERALEVENTCONTROLLER_H_ */


