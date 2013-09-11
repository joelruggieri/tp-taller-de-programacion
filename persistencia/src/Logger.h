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

class Logger {
public:
	Logger(const char *nombre);
	Logger();
//	void abrir(const char* nombre);
	virtual ~Logger();
	void error(std::string mensaje);
	void warning(std::string mensaje);
	void debug(std::string mensaje);
	void setNivel(int nivel);
	void borrar();
private:
	std::string nombre;
	std::ofstream archivo;
};

#endif /* LOGGER_H_ */