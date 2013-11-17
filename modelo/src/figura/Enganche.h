/*
 * Enganche.h
 *
 *  Created on: Oct 5, 2013
 *      Author: matias
 */

#ifndef ENGANCHE_H_
#define ENGANCHE_H_
#include <list>
#include "Box2D/Box2D.h"

class Figura;
class Soga;
using namespace std;

class Enganche {
private:
	bool ocupado;
	b2Vec2 pos;
	Figura* centro;
	bool requiereEslabon;
	b2Body * eslabon;
	Soga * soga;
public:
	Enganche(Figura* centro, float posX, float posY);
	virtual ~Enganche();
	float getPosX();
	float getPosY();
	b2Vec2 & getPos();
	b2Vec2 getWorldPos();
	bool estaOcupado();
	void ocupar(Soga *);
	void liberar();
	b2Body * getBody();
	bool getRequiereEslabon();
	void setRequiereEslabon( bool );
	void setEslabon(b2Body * b);
	b2Body * getEslabon();
	void desprender();
};

typedef list<Enganche*> Lista_Enganches; //OJO que se viene typedef Switch() Ezequiel()

#endif /* ENGANCHE_H_ */
