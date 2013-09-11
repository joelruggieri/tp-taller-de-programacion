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

class AdministradorDeLoggers {
public:
	static Logger &getLogger(TIPO_LOGGER tipo);
private:
	static bool inicializado;
	AdministradorDeLoggers();
	virtual ~AdministradorDeLoggers();
	static Logger logError, logDebug, logInfo, logWarn, logFatal;
};

#endif /* ADMINISTRADORDELOGGERS_H_ */
