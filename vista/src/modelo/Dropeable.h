/*
 * Dropeable.h
 *
 *  Created on: 29/08/2013
 *      Author: jonathan
 */

#ifndef DROPEABLE_H_
#define DROPEABLE_H_
#include <string>
#include "Cuerpo.h"
using namespace std;


class Dropeable {
private:
	Cuerpo cuerpo;
	string modelo;
//	EslabonCreacion * creador;
public:
	Dropeable(string modelo);
	Dropeable(string modelo, Cuerpo cuerpo);
	virtual ~Dropeable();
	const string getModelo();
	Cuerpo *getCuerpo();
	//se encarga de volver a su lugar de creacion
	void invalidar();
};

#endif /* DROPEABLE_H_ */
