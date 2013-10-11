/*
 * Mapa.h
 *
 *  Created on: 04/09/2013
 *      Author: jonathan
 */

#ifndef MAPA_H_
#define MAPA_H_

#include <list>
#include "Box2D/Box2D.h"
#include "Figura.h"
using namespace std;

class Mapa {
private:
	list<Figura*> figuras;
	b2World* myWorld;
	float x,y, w,h;
	float32 frecuencia;
	int32 velocidad, posicion;
	void inicializar(float  x, float y, float w, float h,float32 hz, int32 velocityIterations,int32 positionIterations);
	void crearMundo();
	b2Body* groundBody;
public:
	Mapa(float  x, float y, float w, float h,float32 hz, int32 velocityIterations,int32 positionIterations);
	Mapa(float  x, float y, float w, float h);
	virtual ~Mapa();
	bool addFigura(Figura*);
	bool removeFigura(Figura*);
	list<Figura*> & getFiguras();
	Figura * pickUp(float x, float y);
	float getX() const;
	void setX(float x);
	float getY() const;
	void setY(float y);
	bool isAdentro1D(float pos, float posCentro, float ancho);
	bool isAdentro(float,float);
	void makeBackUp();
	void restoreBackUp(Transformacion & tl);
	void step(Transformacion & tl);
	void despertar();
};

#endif /* MAPA_H_ */
