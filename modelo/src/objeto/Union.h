/*
 * Union.h
 *
 *  Created on: 14/10/2013
 *      Author: jonathan
 */

#ifndef UNION_H_
#define UNION_H_

#include "Objeto.h"

class Union: public Objeto {
public:
	Union();
	virtual ~Union();
	void setFin(const b2Vec2& fin);
	void setInicio(const b2Vec2& inicio);
	float getXInicial();
	float getYInicial();
	float getXFinal();
	float getYFinal();
protected:
	b2Vec2 inicio;
	b2Vec2 fin;
};

#endif /* UNION_H_ */
