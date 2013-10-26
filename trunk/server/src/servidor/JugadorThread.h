/*
 * JugadorThread.h
 *
 *  Created on: 25/10/2013
 *      Author: jonathan
 */

#ifndef JUGADORTHREAD_H_
#define JUGADORTHREAD_H_
#include <thread>
#include "ColaEntrada.h"
#include "Disponibilidad.h"
using namespace std;

class JugadorThread {
private:
	thread * th;
	int nroJugador;
	int socketDesc;
	void join();
	ColaEntrada * cola;
	Disponibilidad * dispo;
public:
	//ENTREGA3 RECIBIR EL SOCKET PARA ESCUCHAR LAS PETICIONES DEL CLIENTE QUE ATIENDE Y LA COLA DE ENTRADA DE EVENTOS para ir cargando..
	//Este muchacho debería abrirse un thread separado PARA LABURAR.
	//ENTREGA3 TIENE QUE TENER UN TIMER PARA QUE SI PASAN MAS DE 10 SEGUNDOS DE NO RECIBIR NI SIQUIERA UN MSJ "ESTOY VIVO" HAGA ALGO PARA
	//MORIR Y PERMITIR EL LUGAR A OTRO.
	JugadorThread(Disponibilidad* d, ColaEntrada*c,int jugador, int socketDesc);
	void run();
	virtual ~JugadorThread();
};

#endif /* JUGADORTHREAD_H_ */
