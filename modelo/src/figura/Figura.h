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



#include "../observer/ObservableModelo.h"
#include "../observer/Evento.h"

class Mapa;
class Figura: public Posicionable, public ObservableModelo {
protected:
	float x;
	float y;
	double rotacion;
	bool traccionable;
	float xb,yb;
	double rotacionb;
	Registro reg;

	b2World * myWorld;
	b2Body * ground;

	Lista_Enganches enganches;

	Vista * vista;
	b2Body * body;
	double radianesAGrados(float r);
    virtual void crearFisicaEstaticaTemplate();
    bool validarContacto(b2Body * verf, b2Body * b);
public:
	static double gradosARadianes(float g);
	Figura();
	Figura(float x, float y);
	Figura(const Figura & fig);
	virtual ~Figura();
	virtual bool contacto(float, float)= 0;
	float getX() const;
	float getY() const;
//	float getRadio() const;
	double getRotacion() const;
	//actualiza a quienes estan observando la figura
	void setPosicion(float, float);
	void setX(float x);
	void setY(float y);
	virtual void setRotacion(double rotation);
	virtual void crearFisica() = 0;
	virtual bool crearFisicaEstatica();
	virtual void acept(VisitorFigura*) = 0;
	virtual void removerFisica();
	bool esTraccionable();
	Vista* getVista();
	void setVista(Vista* vista);
	b2Body * getBody();
	void setBody(b2Body *);

	virtual void updateModelo();
	virtual void updateVista();

	virtual void makeBackUp();
	virtual void restoreBackUp();

	virtual Lista_Enganches& getEnganches();
	Registro & getReg();
	void setReg(Registro r) ;


	virtual void modificarSentido();

	virtual bool agregar(Mapa *);
	virtual bool remover(Mapa *);
	void setWorld(b2World * w, b2Body * ground);
};

#endif /* FIGURA_H_ */


