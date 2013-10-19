/*
 * Plataforma.h
 *
 *  Created on: 02/10/2013
 *      Author: joel
 */

#ifndef PLATAFORMA_H_
#define PLATAFORMA_H_
#include "Objeto.h"
#include "Estirable.h"

class Plataforma:  public Objeto, public virtual Estirable{
private:
	float alto;
	float ancho;
	float anchoBack;
	typedef Figura super;
public:
	Plataforma(const Plataforma& plataforma);
	Plataforma();
	Plataforma(float x ,float y, float ancho, float alto );
	virtual ~Plataforma();
	float getAlto() const;
	float getAncho() const;
	void setAlto(float alto);
	void setAncho(float ancho);
	void crearFisica();
	void acept(VisitorFigura*);
	void estirar(float delta);
	void makeBackUp();
	void restoreBackUp();

};

#endif /* PLATAFORMA_H_ */
