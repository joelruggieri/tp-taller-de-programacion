/*
 * ThreadCleaner.cpp
 *
 *  Created on: 1/11/2013
 *      Author: jonathan
 */

#include "ThreadCleaner.h"
#include "Disponibilidad.h"
#include <unistd.h>
#include <iostream>
#include <src/Logger.h>
#include <list>
#include "src/mensajes/internos/ConexionUsuario.h"
#include "ThreadStatus.h"
using namespace std;

ThreadCleaner::ThreadCleaner(Disponibilidad * dispo, ColaEventos * entrada) {
	this->disponibilidad = dispo;
	this->entrada = entrada;
	th = 0;
	params = 0;
}

ThreadCleaner::~ThreadCleaner() {
	if (th) {
		//JOINEA;
		delete th;
	}
}

void * cleanDeaths(void * arg) {
	ZonaSeguraMemoria * zona = (ZonaSeguraMemoria *) arg;
	ThreadCleanerParams * params = (ThreadCleanerParams *) zona->getParams();
	Disponibilidad * dispo = params->getDisponibilidad();
	int segs = params->getSegundos();
	ColaEventos * entrada = params->getEntrada();
	Logger log;
	while (true) {
		sleep(segs);
		log.debug("Ejecutando servicio de limpieza de threads muertos");
		dispo->lock();
		list<ThreadStatus*> statuses = dispo->getStatuses();
		dispo->unlock();
		list<ThreadStatus*>::iterator it;
		ThreadStatus * status;
		ConexionUsuario * msj = NULL;
		for (it = statuses.begin(); it != statuses.end(); ++it) {
			status = *it;
			status->lock();

			if (status->getThread() && !status->isAlive()) {
				log.debug("Status : Liberando thread");
				status->getThread()->cancel();
				delete status->getThread();
				log.debug("Status: Thread Liberado");
				status->setThread(NULL);
				msj = new ConexionUsuario(false);
				msj->setDestinatario(status->getNroJugador());
				//TODO POR LAS DUDAS LO PONGO A VER SI PROCESA LA SALIDA.
				status->getColaSalida()->clear();
			}
			status->unlock();
			if (msj != NULL) {
				entrada->push(msj);
				msj = NULL;
			}
		}

	}
	pthread_exit(NULL);
}

void ThreadCleaner::run(int segundos) {
	if (!th) {
		params = new ThreadCleanerParams(this->disponibilidad, entrada, segundos);
		th = new ThreadPTM(cleanDeaths, 0, (void*) params);
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

ThreadCleanerParams::ThreadCleanerParams(Disponibilidad* dispo, ColaEventos * entrada, int seg) {
	this->disponibilidad = dispo;
	this->segundos = seg;
	this->entrada = entrada;
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

ColaEventos* ThreadCleanerParams::getEntrada() {
	return entrada;
}
