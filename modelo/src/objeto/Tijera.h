/*
 * Tijera.h
 *
 *  Created on: 15/11/2013
 *      Author: joel
 */

#ifndef TIJERA_H_
#define TIJERA_H_
#include "Objeto.h"
#include "Aspa.h"
class Aspa;
class Tijera: public Objeto {
private:
	float ancho;
	float alto;
	Aspa* aspa1;
	Aspa* aspa2;
	bool accionada;
	typedef Objeto super;
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
	bool crearFisicaEstatica();
	void removerFisica();
	void setRotacion(double);
	void updateModelo();
	void setPosicion(float x,float y);
	void setWorld(b2World * w, b2Body * ground);
	void makeBackUp();
	void restoreBackUp();
	void setNumeroJugador(int);
	void accionar();
	float getRotacionAspa1();
	float getRotacionAspa2();
	void limpiarReferenciasB2D();
	b2Body * getBody();
	bool hacerContacto(float numero);
};

#endif /* TIJERA_H_ */
