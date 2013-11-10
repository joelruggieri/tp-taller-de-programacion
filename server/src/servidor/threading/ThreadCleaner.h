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
#include "src/threading/ColaEventos.h"
class ThreadCleanerParams {
private:
	Disponibilidad * disponibilidad;
	int segundos;
	Logger log;
	ColaEventos * entrada;
public:
	ThreadCleanerParams(Disponibilidad*,ColaEventos * entrada, int seg);
	virtual ~ThreadCleanerParams();
	Disponibilidad* getDisponibilidad() ;
	int getSegundos();
	ColaEventos * getEntrada();
};

class ThreadCleaner {
private:
	Disponibilidad * disponibilidad;
	ThreadPTM * th;
	ThreadCleanerParams * params;
	ColaEventos * entrada;
	void deleteAll();
public:
	ThreadCleaner(Disponibilidad * dispo,ColaEventos * entrada);
	virtual ~ThreadCleaner();
	void run (int segundos);
	void cancel();
};

#endif /* THREADCLEANER_H_ */
