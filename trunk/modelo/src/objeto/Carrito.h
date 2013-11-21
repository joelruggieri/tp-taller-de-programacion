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
	float rotI, rotD, xi,yi,xd,yd;
	float rotIb, rotDb, xib,yib,xdb,ydb;
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
	void crearFisicaEstaticaTemplate();
	void updateModelo();
	void setRotacion(double rotation);
	float getRotD() const;
	float getRotI() const;
	float getXd() const;
	float getXi() const;
	float getYd() const;
	float getYi() const;
	void setPosicion(float,float);
	void makeBackUp();
	void restoreBackUp();
	void recibirImpacto(b2Vec2 direccion);
	void limpiarReferenciasB2D();
};

#endif /* CARRITO_H_ */
