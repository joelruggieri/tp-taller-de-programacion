/*
 * JugadorThread.h
 *
 *  Created on: 25/10/2013
 *      Author: jonathan
 */

#ifndef JUGADORTHREAD_H_
#define JUGADORTHREAD_H_
#include <thread>
#include "src/threading/ColaEventos.h"
using namespace std;

class ThreadStatus;
class JugadorThread {
private:
	thread * thEntrada, *thSalida;
	int nroJugador;
	int socketDesc;
	ColaEventos * colaEntrada;
	ColaEventos * colaSalida;
	ThreadStatus * status;
public:
	//ENTREGA3 RECIBIR EL SOCKET PARA ESCUCHAR LAS PETICIONES DEL CLIENTE QUE ATIENDE Y LA COLA DE ENTRADA DE EVENTOS para ir cargando..
	//Este muchacho debería abrirse un thread separado PARA LABURAR.
	//ENTREGA3 TIENE QUE TENER UN TIMER PARA QUE SI PASAN MAS DE 10 SEGUNDOS DE NO RECIBIR NI SIQUIERA UN MSJ "ESTOY VIVO" HAGA ALGO PARA
	//MORIR Y PERMITIR EL LUGAR A OTRO.
	JugadorThread(ColaEventos*c,ThreadStatus *status);
	void run();
	void exit();
	virtual ~JugadorThread();
};

#endif /* JUGADORTHREAD_H_ */
