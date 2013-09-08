/*
 * Logger.cpp
 *
 *  Created on: 07/09/2013
 *      Author: javier
 */

#include "Logger.h"
#include <fstream>
#include <iostream>
#include <time.h>

const std::string fecha() {
	time_t tiempo = time(0);
	struct tm tiempoStruct = *localtime(&tiempo);
	char buf[80];
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tiempoStruct);
	return buf;
}

Logger::Logger(std::string nombre) :
		archivo(nombre.c_str()) {
	nivel = 0;
	this->nombre = nombre;
}

Logger::~Logger() {
	archivo.close();
}

void Logger::error(std::string mensaje) {
	if (nivel >= 1)
		archivo << fecha() << " [ERROR] " << ": " << mensaje;
}

void Logger::warning(std::string mensaje) {
	if (nivel >= 2)
		archivo << fecha() << " [WARN] " << ": " << mensaje;
}

void Logger::debug(std::string mensaje) {
	if (nivel >= 3)
		archivo << fecha() << " [DEBUG] " << ": " << mensaje;
}

void Logger::setNivel(int nivel) {
	this->nivel = nivel;
}
