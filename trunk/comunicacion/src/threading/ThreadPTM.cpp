/*
 * ThreadPTM.cpp
 *
 *  Created on: 31/10/2013
 *      Author: jonathan
 */

#include "ThreadPTM.h"

#include <stdio.h>
#include <pthread.h>

ThreadPTM::ThreadPTM(void *(*function)(void *), void *(*cleaner)(void *), void * param) {
	this->zona = new ZonaSeguraMemoria(cleaner, param);
	int ret = pthread_create(&th, NULL, function, zona);
	if (ret != 0) {
		perror("pthread_create failed\n");
		//TODO REVISAR SALIDA
//		cancel(EXIT_FAILURE);
	}
	cancelado = false;
}

void ThreadPTM::cancel() {
	if (!cancelado) {
		cancelado = true;
		pthread_cancel(this->th);
		pthread_join(this->th,0);
		this->zona->cancel();
	}
}

ThreadPTM::~ThreadPTM() {
	if (!cancelado) {
		pthread_join(this->th, 0);
	}
	delete zona;
}

