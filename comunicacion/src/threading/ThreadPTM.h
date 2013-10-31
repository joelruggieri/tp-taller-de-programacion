/*
 * ThreadPTM.h
 *
 *  Created on: 31/10/2013
 *      Author: jonathan
 */

#ifndef THREADPTM_H_
#define THREADPTM_H_
#include <pthread.h>
#include "ZonaSeguraMemoria.h"


//Recibe una funcion para hacer clean de objetos que que puedan quedar muertos al cancelar este thread
//El destructor intenta joinear si no se cancelo antes
//Si se cancela lo que se hace es usar la funcion cleaner para limpiar la zona de memoria previo cancelar thread.

class ThreadPTM {
private:
	pthread_t th;
	ZonaSeguraMemoria * zona;
	bool cancelado;
public:
	ThreadPTM(void *(*__start_routine) (void *),  void *(*cleaner) (void *), void * param);
	void cancel();
	virtual ~ThreadPTM();

};

#endif /* THREADPTM_H_ */
