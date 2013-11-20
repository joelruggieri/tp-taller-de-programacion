/*
 * Vista.h
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#ifndef VISTA_H_
#define VISTA_H_

class Vista {
private:
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

};

#endif /* VISTA_H_ */
