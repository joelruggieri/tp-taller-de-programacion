/*
 * Worker.cpp
 *
 *  Created on: 03/11/2013
 *      Author: jonathan
 */

#include "Worker.h"

namespace LOG {

#include <stdio.h>
#include <pthread.h>

Worker::Worker(void *(*function)(void *), void *(*cleaner)(void *), void * param) {
	int ret = pthread_create(&th, NULL, function, (void *)param);
	if (ret != 0) {
		perror("pthread_create failed\n");
		//TODO REVISAR SALIDA
//		cancel(EXIT_FAILURE);
	}
	cancelado = false;
}

void Worker::cancel() {
	if (!cancelado) {
		cancelado = true;
		pthread_cancel(this->th);
		pthread_join(this->th,0);
	}
}

Worker::~Worker() {
	if (!cancelado) {
		pthread_join(this->th, 0);
	}
}

} /* namespace LOG */
