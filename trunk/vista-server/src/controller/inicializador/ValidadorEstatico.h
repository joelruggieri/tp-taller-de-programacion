/*
 * ValidadorEstatico.h
 *
 *  Created on: 07/10/2013
 *      Author: jonathan
 */

#ifndef VALIDADORESTATICO_H_
#define VALIDADORESTATICO_H_

#include "src/figura/VisitorFigura.h"
#include "src/figura/Figura.h"
#include <string>
using namespace std;
#include "src/Constantes.h"
#include "src/objeto/Motor.h"
#include "src/objeto/Plataforma.h"
#include "src/objeto/Balancin.h"
#include "src/objeto/GloboHelio.h"
#include "src/objeto/PelotaJuego.h"
#include "src/objeto/CintaTransportadora.h"
#include "src/objeto/BolaBoliche.h"
#include "src/objeto/Engranaje.h"
#include "src/objeto/Correa.h"
#include "src/objeto/Soga.h"
#include "src/objeto/Yunque.h"
#include "src/objeto/Clavo.h"
//Esta clase valida cosas como ancho de una figura, angulos validos, radios predefinidos, etc,etc
//Las validaciones mas complejas como si estan solapadas dos figuras o bien un enganche invalido
//las debería hacer el mapa.
class ValidadorEstatico: public VisitorFigura {
private:
	bool ultimaValidacion;
	bool validarPosicion(Figura *);
	bool extremosYDeCorreaValidos(const Correa* c);
	bool extremosXDeCorreaValidos(const Correa* c);
	string errorValidacion;
	float xmin,xmax,ymin,ymax;
public:
	ValidadorEstatico(float xmin, float xmax, float ymin, float ymax);
	virtual ~ValidadorEstatico();
	void visit(Motor*);
	void visit(Plataforma*);
	void visit(Balancin*);
	void visit(CintaTransportadora*);
	void visit (BolaBoliche*);
	void visit(PelotaJuego*);
	void visit (GloboHelio*);
	void visit (Engranaje*);
	void visit (Correa*);
	void visit(Soga*);
	void visit(Yunque*);
	void visit(Clavo*);
	string getErrorValidacion();
	bool isValido();
	void validar(Figura *);
};

#endif /* VALIDADORESTATICO_H_ */
