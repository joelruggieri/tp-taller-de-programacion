/*
 * EjecutorMensajes.cpp
 *
 *  Created on: 3/11/2013
 *      Author: jonathan
 */

#include "EjecutorMensajes.h"
#include "src/mensajes/userEvents/MouseMotionMsj.h"
#include "src/mensajes/userEvents/ClickMsj.h"
#include "src/mensajes/userEvents/KeyMsj.h"
#include "src/mensajes/userEvents/UserEventMsj.h"
#include "src/mensajes/viewMensaje/ViewMsj.h"

EjecutorMensajes::EjecutorMensajes() {
	// TODO Auto-generated constructor stub

}

EjecutorMensajes::~EjecutorMensajes() {
	// TODO Auto-generated destructor stub
}

void EjecutorMensajes::visit(MouseMotionMsj*) {
}

void EjecutorMensajes::visit(ClickMsj*) {
}

void EjecutorMensajes::visit(KeyMsj*) {
}

void EjecutorMensajes::visit(UserEventMsj*) {
}

void EjecutorMensajes::visit(ViewMsj*) {
}
