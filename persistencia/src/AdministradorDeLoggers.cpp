/*
 * AdministradorDeLoggers.cpp
 *
 *  Created on: 10/09/2013
 *      Author: javier
 */

#include "AdministradorDeLoggers.h"

Logger AdministradorDeLoggers::logError("error.log");
Logger AdministradorDeLoggers::logWarn("warning.log");
Logger AdministradorDeLoggers::logFatal("fatal.log");
Logger AdministradorDeLoggers::logDebug("debug.log");
Logger AdministradorDeLoggers::logInfo("info.log");

AdministradorDeLoggers::AdministradorDeLoggers() {
	// TODO Auto-generated constructor stub

}

AdministradorDeLoggers::~AdministradorDeLoggers() {
	// TODO Auto-generated destructor stub
}

Logger &AdministradorDeLoggers::getLogger(TIPO_LOGGER tipo) {
	if (tipo == ERROR) {
		return logError;
	} else if (tipo == WARN) {
		return logWarn;
	} else if (tipo == FATAL) {
		return logFatal;
	} else if (tipo == DEBUG) {
		return logDebug;
	} else {
		return logInfo;
	}
}
