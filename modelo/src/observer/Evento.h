/*
 * Evento.h
 *
 *  Created on: 19/10/2013
 *      Author: jonathan
 */

#ifndef EVENTO_H_
#define EVENTO_H_

enum Evento_type {ANTES_DESTRUCCION, DESPUES_DESTRUCCION, FISICA_REMOVIDA, FISICA_CREADA, CAMBIO_ESPACIAL, DESACTIVADO};
class Evento {
public:
	Evento();
	virtual ~Evento();
};

#endif /* EVENTO_H_ */
