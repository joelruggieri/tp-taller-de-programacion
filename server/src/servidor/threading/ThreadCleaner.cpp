/*
 * ThreadCleaner.cpp
 *
 *  Created on: 1/11/2013
 *      Author: jonathan
 */

#include "ThreadCleaner.h"
#include "Disponibilidad.h"
#include <unistd.h>
ThreadCleaner::ThreadCleaner(Disponibilidad * dispo) {
	this->disponibilidad = dispo;
	th = 0;
	params = 0;
}

ThreadCleaner::~ThreadCleaner() {
	if(th) {
		//JOINEA;
		delete th;
	}
}



void * cleanDeaths(void * arg) {
	ZonaSeguraMemoria * zona = (ZonaSeguraMemoria *) arg;
	ThreadCleanerParams * params = (ThreadCleanerParams *) zona->getParams();
	Disponibilidad * dispo =  params->getDisponibilidad();
	int segs = params->getSegundos();
	while(true){
		sleep(segs);
		dispo->lock();
		dispo->cleanDeaths();
		dispo->unlock();
	}
	pthread_exit(NULL);
}

void ThreadCleaner::run(int segundos) {
	if(! th){
		params = new ThreadCleanerParams(this->disponibilidad,segundos);
		th = new ThreadPTM(cleanDeaths, 0, (void*)params);
	}


}

Disponibilidad* ThreadCleanerParams::getDisponibilidad() {
	return disponibilidad;
}

ThreadCleanerParams::~ThreadCleanerParams() {
}

int ThreadCleanerParams::getSegundos() {
	return segundos;
}

ThreadCleanerParams::ThreadCleanerParams(Disponibilidad* dispo, int seg) {
	this->disponibilidad = dispo;
	this->segundos = seg;
}



void ThreadCleaner::cancel() {
	if (th) {
		th->cancel();
		deleteAll();
	}

}

void ThreadCleaner::deleteAll() {
	delete th;
	delete params;
	th = NULL;
	params = NULL;
}
