/*
 * ThreadCleaner.h
 *
 *  Created on: 1/11/2013
 *      Author: jonathan
 */

#ifndef THREADCLEANER_H_
#define THREADCLEANER_H_
#include "Disponibilidad.h"
#include "src/threading/ThreadPTM.h"
#include "src/Logger.h"
class ThreadCleanerParams {
private:
	Disponibilidad * disponibilidad;
	int segundos;
	Logger log;
public:
	ThreadCleanerParams(Disponibilidad*, int seg);
	virtual ~ThreadCleanerParams();
	Disponibilidad* getDisponibilidad() ;
	int getSegundos();
};

class ThreadCleaner {
private:
	Disponibilidad * disponibilidad;
	ThreadPTM * th;
	ThreadCleanerParams * params;
	void deleteAll();
public:
	ThreadCleaner(Disponibilidad * dispo);
	virtual ~ThreadCleaner();
	void run (int segundos);
	void cancel();
};

#endif /* THREADCLEANER_H_ */
