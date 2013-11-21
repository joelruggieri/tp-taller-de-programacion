/*
 * Evento.h
 *
 *  Created on: 19/10/2013
 *      Author: jonathan
 */

#ifndef EVENTO_H_
#define EVENTO_H_
//El evento destruir el unico que debe capturarlo es el mapa, porque da la orden de destruir al objeto.
enum Evento_type {DESTRUCCION_FORZADA, ANTES_DESTRUCCION, DESPUES_DESTRUCCION, FISICA_REMOVIDA, FISICA_E_CREADA, CAMBIO_ESPACIAL_FORZADO, DESACTIVADO,ACCIONADO};
class Evento {
public:
	Evento();
	virtual ~Evento();
};

#endif /* EVENTO_H_ */
