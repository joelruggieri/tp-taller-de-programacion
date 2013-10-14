/*
 * Figura.h
 *
 *  Created on: 04/09/2013
 *      Author: jonathan
 */

#ifndef FIGURA_H_
#define FIGURA_H_
#include "../Posicionable.h"
#include "VisitorFigura.h"
#include "Box2D/Box2D.h"
#include "Rotador.h"
#include "../Vista.h"
#include "Enganche.h"
#include "Registro.h"
class Figura: public Posicionable {
protected:
	float x;
	float y;
	double rotacion;

	float xb,yb;
	double rotacionb;

	Registro reg;


	Lista_Enganches enganches;

	Vista * vista;
	b2Body * body;
	double radianesAGrados(float r);
	double gradosARadianes(float g);
    virtual void crearFisicaEstaticaTemplate(b2World * w, b2Body* ground);
    bool validarContacto(b2World * w, b2Body * verf, b2Body * b);
public:
	Figura();
	Figura(float x, float y);
	Figura(const Figura & fig);
	virtual ~Figura();
	virtual bool contacto(float, float)= 0;
	float getX() const;
	float getY() const;
	double getRotacion() const;
	void setX(float x);
	void setY(float y);
	virtual void setRotacion(double rotation);
	virtual void agrandar (float delta);
	virtual float getAncho() const;
	virtual void crearFisica(b2World * w, b2Body* ground) = 0;
	virtual bool crearFisicaEstatica(b2World *, b2Body* ground);
	virtual void acept(VisitorFigura*) = 0;
	virtual void removerFisica(b2World * w);

	Vista* getVista();
	void setVista(Vista* vista);
	b2Body * getBody();
	void setBody(b2Body *);


	virtual void updateModelo();
	virtual void updateVista(Transformacion &);

	virtual void makeBackUp();
	virtual void restoreBackUp();

	virtual Lista_Enganches getEnganches();
	Registro & getReg() ;
	void setReg(Registro r) ;


	virtual void modificarSentido();


};

#endif /* FIGURA_H_ */

