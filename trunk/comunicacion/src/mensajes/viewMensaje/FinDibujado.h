/*
 * FinDibujado.h
 *
 *  Created on: 11/11/2013
 *      Author: jonathan
 */

#ifndef FINDIBUJADO_H_
#define FINDIBUJADO_H_

#include "ViewMsj.h"

class FinDibujado: public ViewMsj {
public:
	FinDibujado();
	virtual ~FinDibujado();
	void serialize(YAML::Emitter & out);
	NetworkMensaje * deserialize(YAML::const_iterator & it);
	void acept(ViewMsjVisitor *);
	ViewMsj* clone(int destinatario);

};

#endif /* FINDIBUJADO_H_ */
