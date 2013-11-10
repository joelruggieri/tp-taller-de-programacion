/*
 * DistribuidorMensajes.cpp
 *
 *  Created on: 5/11/2013
 *      Author: jonathan
 */

#include "DistribuidorMensajes.h"
#include <iostream>
#include "MensajePlano.h"
#include "userEvents/UserEventMsj.h"
#include "viewMensaje/ViewMsj.h"
#include "internos/MensajeInterno.h"
#include "../ConstantesComunicacion.h"
using namespace std;

DistribuidorMensajes::DistribuidorMensajes(UserEventVisitor* u, ViewMsjVisitor * v, MensajePlanoVisitor * p,
		MensajeInternoVisitor * i) {
	user = u;
	views = v;
	planos = p;
	internos = i;

}

void DistribuidorMensajes::procesar(NetworkMensaje* msj) {
	msj->acept(this);
	delete msj;
}

DistribuidorMensajes::~DistribuidorMensajes() {

}

void DistribuidorMensajes::visit(UserEventMsj* m) {
	if (user != NULL) {
		m->acept(user);
	}

}

void DistribuidorMensajes::visit(ViewMsj* m) {
	if (views != NULL) {
//		log.debug("Se pocesa mensaje de Vista");
		m->acept(views);
	}

}

void DistribuidorMensajes::visit(MensajePlano* m) {
	//Puede venir un mensaje por timeout generado por comunicacion, en ese caso lo deleteo.
	if (m->getTag() != TAG_MSJ_NOTIMEOUT) {
		if (planos != NULL) {
//			log.debug("Se pocesa mensaje plano");
			m->acept(planos);
		}

	}
}

void DistribuidorMensajes::visit(MensajeInterno * m) {
	if (internos != NULL) {
//		log.("Se pocesa mensaje interno");
		m->acept(internos);
	}
}
