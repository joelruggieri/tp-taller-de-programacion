/*
 * Tijera.h
 *
 *  Created on: 15/11/2013
 *      Author: joel
 */

#ifndef TIJERA_H_
#define TIJERA_H_
#include "Objeto.h"
class Tijera: public Objeto {
private:
	float ancho;
	float alto;
	double rotacionAspa2;
	double rotacionAspa1;
	//b2RevoluteJoint * jointAspa1Tierra;
	//b2RevoluteJoint * jointAspa2Tierra;
	//b2Body* aspa1;
	b2Body* aspa2;
	typedef Objeto super;
	double getRotacionAspa2() const;
	double getRotacionAspa1() const;
	void setRotacionAspa1(double rotation);
	void setRotacionAspa2(double rotation);
	void crearFisicaEstaticaTemplate(b2World * w, b2Body* ground);
public:
	Tijera();
	virtual ~Tijera();
	Tijera(const Tijera& tijera);
	Tijera(float x ,float y, float ancho, float alto);
	float getAlto() const;
	float getAncho() const;
	void setAlto(float alto);
	void setAncho(float ancho);
	void crearFisica();
	void acept(VisitorFigura*);
	void setBodyAspa2(b2Body* body);
	b2Body* getbodyAspa2();
	bool crearFisicaEstatica();
	void removerFisica();
	void setRotacion(double);
};

#endif /* TIJERA_H_ */
