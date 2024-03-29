/*
 * AdministradorDeLoggers.cpp
 *
 *  Created on: 10/09/2013
 *      Author: javier
 */

#include "AdministradorDeLoggers.h"

//Archivo *AdministradorDeLoggers::logError = new Archivo("error.log", APPEND);
//Archivo *AdministradorDeLoggers::logWarn = new Archivo("warning.log", APPEND);
//Archivo *AdministradorDeLoggers::logFatal = new Archivo("fatal.log", APPEND);
//Archivo *AdministradorDeLoggers::logDebug = new Archivo("debug.log", APPEND);
//Archivo *AdministradorDeLoggers::logInfo = new Archivo("info.log", APPEND);
Archivo *AdministradorDeLoggers::logUnificado = new Archivo("programa.log", APPEND);

AdministradorDeLoggers::AdministradorDeLoggers() {
	// TODO Auto-generated constructor stub

}

AdministradorDeLoggers::~AdministradorDeLoggers() {
	// TODO Auto-generated destructor stub
}

Archivo *AdministradorDeLoggers::getLogger() {
//	if (tipo == ERROR) {
//		return logError;
//	} else if (tipo == WARN) {
//		return logWarn;
//	} else if (tipo == FATAL) {
//		return logFatal;
//	} else if (tipo == DEBUG) {
//		return logDebug;
//	} else {
//		return logInfo;
//	}
	return logUnificado;
}

void AdministradorDeLoggers::cerrarTodo() {
//	logError->cerrar();
//	logDebug->cerrar();
//	logInfo->cerrar();
//	logWarn->cerrar();
//	logFatal->cerrar();
	logUnificado->cerrar();
}

Archivo* AdministradorDeLoggers::getLoggerUnificado() {
	return logUnificado;
}
