/*
 * AdministradorDeLoggers.h
 *
 *  Created on: 10/09/2013
 *      Author: javier
 */

#ifndef ADMINISTRADORDELOGGERS_H_
#define ADMINISTRADORDELOGGERS_H_

enum TIPO_LOGGER { ERROR, DEBUG, FATAL, INFO, WARN};

#include "Logger.h"
#include "Archivo.h"

class AdministradorDeLoggers {
public:
	static Archivo *getLogger(TIPO_LOGGER tipo);
	static Archivo *getLoggerUnificado();
	static void cerrarTodo();
private:
	static bool inicializado;
	AdministradorDeLoggers();
	virtual ~AdministradorDeLoggers();
//	static Archivo *logError, *logDebug, *logInfo, *logWarn, *logFatal;
	static Archivo *logUnificado;
};

#endif /* ADMINISTRADORDELOGGERS_H_ */
