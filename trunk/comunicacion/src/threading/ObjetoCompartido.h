/*
 * ObjetoCompartido.h
 *
 *  Created on: 26/10/2013
 *      Author: joel
 */

#ifndef OBJETOCOMPARTIDO_H_
#define OBJETOCOMPARTIDO_H_
#include <pthread.h>
using namespace std;

class ObjetoCompartido {
private:
	pthread_mutex_t mutex;
public:
	ObjetoCompartido();
	virtual ~ObjetoCompartido();
	void lock();
	void unlock();
};

#endif /* OBJETOCOMPARTIDO_H_ */
