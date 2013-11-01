/*
 * IOThread.h
 *
 *  Created on: 01/11/2013
 *      Author: ezequiel
 */

#ifndef IOTHREAD_H_
#define IOTHREAD_H_
#include "src/threading/ColaEventos.h"
#include "src/threading/ThreadPTM.h"
class IOThread {
public:
	IOThread(ColaEventos* , ColaEventos* , int );
//	virtual ~IOThread();
	void run();
private:
//	ThreadPTM* aNombrar1, aNombrar2;
};

#endif /* IOTHREAD_H_ */
