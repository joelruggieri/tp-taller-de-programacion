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
#include "../Transformacion.h"
#include "../observer/ObserverModelo.h"
using namespace std;

class Union;
class Figura;
class Mapa: public ObserverModelo {
private:
	list<Figura*> figuras;
	list<Union*> uniones;
	list<Figura*> figurasBorrar;
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
	bool add(Figura*);
	bool remove(Figura*);
	bool addFigura(Figura*);
	bool removeFigura(Figura*);
	bool addUnion(Union*);
	bool removeUnion(Union*);
	list<Figura*> & getFiguras();
	list<Union*> & getUniones();
	Figura * pickUp(float x, float y, uint16 mascara);
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
	void notifyEvent(ObservableModelo*, Evento_type);
	void cleanDeletes();
};

#endif /* MAPA_H_ */
