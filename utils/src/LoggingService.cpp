/*
 * LoggingService.cpp
 *
 *  Created on: 03/11/2013
 *      Author: jonathan
 */

#include "LoggingService.h"
#include "Logger.h"
namespace LOG {
ColaLogs * LoggingService::colaLogs = new ColaLogs();

void * func_Log(void * arg) {
	ColaLogs* colaSalida = (ColaLogs *) arg;
	while (true) {
		usleep(100000);
		while (colaSalida->hasNext()) {
			string msj = colaSalida->front();
			Archivo *a = AdministradorDeLoggers::getLogger();
			cout << msj << endl;
			a->escribir(msj);

		}
	}
	pthread_exit(NULL);
}

LoggingService::LoggingService() {
	worker = new Worker(func_Log,0,(void *)colaLogs);
}

LoggingService::~LoggingService() {
	worker->cancel();
	delete worker;
}

} /* namespace LOG */
