/*
 * Carrito.h
 *
 *  Created on: 14/11/2013
 *      Author: joel
 */

#ifndef CARRITO_H_
#define CARRITO_H_
#include "Objeto.h"

class Carrito: public Objeto {
private:
	float ancho;
	float alto;
	b2Body* ruedaIzquierda;
	b2Body* ruedaDerecha;
	typedef Objeto super;
public:
	Carrito();
	Carrito(const Carrito& figura);
	Carrito(float x, float y, float ancho, float alto);
	virtual ~Carrito();
	float getAlto() const;
	float getAncho() const;
	void setAlto(float alto);
	void setAncho(float ancho);
	void crearFisica();
	void acept(VisitorFigura*);
	void setRuedaDerecha(b2Body*);
	void setRuedaIzquierda(b2Body*);
	bool crearFisicaEstatica();
	void removerFisica();
};

#endif /* CARRITO_H_ */
