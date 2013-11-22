/*
 * Vista.h
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#ifndef VISTA_H_
#define VISTA_H_
#include "Constantes.h"
class Vista {
protected:
	int numeroEvento;
public:
	virtual ~Vista(){

	};
	void alertarEvento(int numero){
		this->numeroEvento = numero;
	}
	int getNumeroEvento(){
		return numeroEvento;
	}
	void resetearNumeroEvento(){
		this->numeroEvento = VALOR_DESACTIVAR_SONIDO;
	}

};

#endif /* VISTA_H_ */
