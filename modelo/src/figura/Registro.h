/*
 * Registro.h
 *
 *  Created on: 07/10/2013
 *      Author: jonathan
 */

#ifndef REGISTRO_H_
#define REGISTRO_H_
#include <string>
using namespace std;

class Registro {
private:
	int linea;
	string etiqueta;
public:
	Registro();
	virtual ~Registro();
	const string& getEtiqueta() ;
	void setEtiqueta(string etiqueta);
	int getLinea();
	void setLinea(int linea);
};

#endif /* REGISTRO_H_ */
