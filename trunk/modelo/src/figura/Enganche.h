/*
 * Enganche.h
 *
 *  Created on: Oct 5, 2013
 *      Author: matias
 */

#ifndef ENGANCHE_H_
#define ENGANCHE_H_
#include <list>
using namespace std;

class Enganche {
private:
	bool ocupado;
	int posX;
	int posY;
public:
	Enganche(int posX, int posY);
	virtual ~Enganche();
	int getPosX();
	int getPosY();
	bool estaOcupado();
	void ocupar();
	void liberar();
};

typedef list<Enganche*> Lista_Enganches; //OJO que se viene typedef Switch() Ezequiel()

#endif /* ENGANCHE_H_ */
