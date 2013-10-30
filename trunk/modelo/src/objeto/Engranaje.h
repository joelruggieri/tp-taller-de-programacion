/*
 * Engranaje.h
 *
 *  Created on: 11/10/2013
 *      Author: javier
 */

#ifndef ENGRANAJE_H_
#define ENGRANAJE_H_
#include "Objeto.h"
#include "Estirable.h"
class Engranaje: public Objeto, public virtual Estirable {
public:
	Engranaje();
	Engranaje(const Engranaje & engranaje);
	Engranaje(float x, float, float radio);
	virtual ~Engranaje();
	void crearFisica();
	void acept(VisitorFigura* visitor);
	void crearFisicaEstaticaTemplate();
	void removerFisica();
	bool crearFisicaEstatica();
	b2RevoluteJoint* & getJointATierra();
	b2Body * getDiscoGiro();
	void modificarSentido();
	int getDireccion() const;
	void setDireccion(int dir);
	float getRadio();
	void estirar(float delta);
	void ocupar();
	void liberar();
	bool estaLibre();
	void setRotacion(double rotation);
	void makeBackUp();
	void restoreBackUp();
	float getRadio() const;
	void setRadio(float radio);
	float getAncho() const;
private:
	typedef Objeto super;
	void getSiguienteRadio();
	void getAnteriorRadio();
	bool libre;
protected:
	b2RevoluteJoint * jointCuerpoTierra;
	float radio, radiob;
	b2Body* radioAccion;
	int direccion;
	void crearLazo(Engranaje*, b2World*);

};

#endif /* ENGRANAJE_H_ */
