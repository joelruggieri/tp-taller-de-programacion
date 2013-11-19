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
#include "../Vista.h"
#include "Enganche.h"
#include "Registro.h"
#include "../interaccion/ValidadorInteraccion.h"
#include "../Area.h"
//ENTREGA3 HAY QUE AGREGAR UN ATRIBUTO QUE SEA "SELECCIONABLE" Y ADEMAS UN JUGADOR ASIGNADO PARA QUE NO PUEDA SER ELEGIDA POR CUALQUIERA
// EL SEGUNDO SE PUEDE IMPLEMENTAR COMO UNA MASCARA IGUAL QUE BOX2D O UN INT XD
#include "../observer/ObservableModelo.h"
#include "../observer/Evento.h"

class Mapa;
class Figura: public Posicionable, public ObservableModelo {
protected:
	float x;
	float y;
	int numeroJugadorDuenio;
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
    bool validarContacto(b2Fixture* prim,const b2Transform& trfprim, b2Fixture* sec,const b2Transform& trfsec);
    //Cosas tercera entrega

    bool viva;
    //es el que valida para una interaccion.
	ValidadorInteraccion * validador;

	//Este metodo se llama una vez q la interaccion fue validada por el validador
	virtual void interactuarTemplate();
	bool accionado;
public:
	static double gradosARadianes(float g);
	Figura();
	Figura(float x, float y);
	Figura(float x, float y, ValidadorInteraccion * validador);
	Figura(const Figura & fig);
	virtual ~Figura();
	virtual bool contacto(float, float)= 0;
	float getX() const;
	float getY() const;
	double getRotacion() const;
	//actualiza a quienes estan observando la figura
	virtual void setPosicion(float, float);
	void setX(float x);
	void setY(float y);
	virtual void setNumeroJugador(int numero);
	int getNumeroJugador();
	virtual void setRotacion(double rotation);
	virtual void crearFisica() = 0;
	virtual bool crearFisicaEstatica();
	virtual void acept(VisitorFigura*) = 0;
	virtual void removerFisica();
	bool esTraccionable();
	Vista* getVista();
	void setVista(Vista* vista);
	virtual b2Body * getBody();
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
	virtual void setWorld(b2World * w, b2Body * ground);
	virtual void limpiarReferenciasB2D();
	virtual void explotar();
	virtual void recibirImpacto(b2Vec2 direccion);
	void realizarImpacto(b2Vec2 direccion);
	virtual void interactuarNoArea(Area & area, int jugador);
	bool isViva();
	//cosas de la tercera parte
	//interactuar es el metodo usado para la accion del jugador sobre un objeto. Por defecto se llama a interactuar template.
	virtual void  interactuar(Area & area, int jugador);
	//accionar es la accion que sucede cuando choca contra otro objeto que lo hace ejecutar su accion: ejemplo el globo rebentar.
	virtual void accionar();
	virtual void accionesPostFisica();
	virtual void desenganchado(Enganche *);
};

#endif /* FIGURA_H_ */


