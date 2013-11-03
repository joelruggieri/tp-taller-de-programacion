/*
 * Worker.h
 *
 *  Created on: 03/11/2013
 *      Author: jonathan
 */

#ifndef WORKER_H_
#define WORKER_H_
namespace LOG {
#include <pthread.h>
class Worker {
private:
	pthread_t th;
	bool cancelado;
public:
	Worker(void *(*__start_routine)(void *), void *(*cleaner)(void *), void * param);
	void cancel();
	virtual ~Worker();

};
} /* namespace LOG */
#endif /* WORKER_H_ */
