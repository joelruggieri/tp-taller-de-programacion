/*
 * Nivel.h
 *
 *  Created on: 15/09/2013
 *      Author: javier
 */

#ifndef NIVEL_H_
#define NIVEL_H_

#include <list>
#include "figura/Figura.h"
#include <string>
#include "Jugador.h"
#include "Objetivos/Objetivo.h"
//ENTREGA3 hay que hacer que tenga:
//Por lo tanto el nivel consta de:
//
//1. La cantidad de jugadores que participan de él
//
//2. La configuración inicial de ítems fijos
//
//3. Las áreas del escenario que cada jugador puede modificar
//
//4. Los ítems que corresponden a cada área
//
//5. Un objetivo
class Nivel {
public:
	Nivel();
	Nivel(std::string nombrem);
	Nivel(std::string nombre,int cantJugadores, Objetivo * objetivo);
	virtual ~Nivel();
	void agregar(Figura* figura);
	int cantidadFiguras() const;
	std::list<Figura*>& getFiguras();
	const std::string& getNombre() const;
	void setNombre(const std::string& nombre);
	void setFondo(std::string fondo);
	std::string getFondo() const;
	std::list<Jugador*>& getJugadores();
	void agregarJugador(Jugador*);
	void setNumeroMaximoJugadores(int jugadores);
	int getNumeroMaximoJugadores() const;
	int getNumeroJugadores() const;
	Objetivo* getObjetivo();
	void setObjetivo(int obj);

private:
	std::list<Figura*> objetos;
	std::string nombre;
	std::string fondo;
	int numeroMaximoDeJugadores;
	std::list<Jugador*> jugadores;
	Objetivo* objetivoJuego;

};

#endif /* NIVEL_H_ */
