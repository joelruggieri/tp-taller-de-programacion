/*
 * StepModeloThread.h
 *
 *  Created on: 07/11/2013
 *      Author: jonathan
 */

#ifndef StepModeloThreadING_H_
#define StepModeloThreadING_H_
#include "src/threading/ColaEventos.h"
#include "src/threading/ThreadPTM.h"
class StepModeloThread {
private:
	ColaEventos * cola;
	ThreadPTM * th;
	void cleanAll();
public:
	StepModeloThread(ColaEventos * colaEntrada);
	virtual ~StepModeloThread();
	void run();
	void cancel();
};


#endif /* StepModeloThreadING_H_ */
