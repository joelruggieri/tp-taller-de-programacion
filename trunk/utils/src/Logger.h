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

class Logger {
public:
	Logger();
//	void abrir(const char* nombre);
	virtual ~Logger();
	void error(std::string mensaje);
	void warning(std::string mensaje);
	void debug(std::string mensaje);
	void fatal(std::string mensaje);
	void info(std::string mensaje);
//	void borrar();
	void concatenar(std::string& mensajeOriginal,float numero);
	void concatenar(std::string& mensajeOriginal,double numero);
private:
	std::string nombre;
	std::ofstream archivo;
};

#endif /* LOGGER_H_ */
