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

public:
	Dropeable(string modelo);
	Dropeable(string modelo, Cuerpo cuerpo);
	virtual ~Dropeable();
	const string getModelo();
	const Cuerpo getCuerpo();
};

#endif /* DROPEABLE_H_ */
