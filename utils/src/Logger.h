/*
 * Logger.h
 *
 *  Created on: 07/09/2013
 *      Author: javier
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>
#include <fstream>
#include <sstream>
#include "AdministradorDeLoggers.h"


enum NIVEL_LOGGER {DEBUG_N, INFO_N, WARN_N, ERROR_N, FATAL_N};
class Logger {
private:
	static NIVEL_LOGGER nivel;
	void log(std::string, TIPO_LOGGER, NIVEL_LOGGER);
public:
	Logger();
//	void abrir(const char* nombre);
	virtual ~Logger();
	void fatal(std::string mensaje);
	void error(std::string mensaje);
	void warning(std::string mensaje);
	void info(std::string mensaje);
	void debug(std::string mensaje);
//	void borrar();
	void concatenar(std::string& mensajeOriginal, float numero);
	void concatenar(std::string& mensajeOriginal, double numero);
	static void setNivel(NIVEL_LOGGER);
};
#endif /* LOGGER_H_ */
