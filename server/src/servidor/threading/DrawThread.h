/*
 * DrawThread.h
 *
 *  Created on: 07/11/2013
 *      Author: jonathan
 */

#ifndef DRAWTHREADING_H_
#define DRAWTHREADING_H_
#include "src/threading/ColaEventos.h"
#include "src/threading/ThreadPTM.h"
class DrawThread {
private:
	ColaEventos * cola;
	ThreadPTM * th;
	void cleanAll();
public:
	DrawThread(ColaEventos * colaEntrada);
	virtual ~DrawThread();
	void run();
	void cancel();
};


#endif /* DRAWTHREADING_H_ */
