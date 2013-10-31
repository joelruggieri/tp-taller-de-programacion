/*
 * ObjetoCompartido.cpp
 *
 *  Created on: 26/10/2013
 *      Author: joel
 */

#include "ObjetoCompartido.h"

ObjetoCompartido::ObjetoCompartido() {
	pthread_mutex_init(&(this->mutex), NULL);

}

ObjetoCompartido::~ObjetoCompartido() {
	pthread_mutex_destroy(&(this->mutex));
}

void ObjetoCompartido::lock() {
	pthread_mutex_lock(&(this->mutex));
}

void ObjetoCompartido::unlock() {
	pthread_mutex_unlock(&(this->mutex));
}
