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

#include "Archivo.h"
#include "AdministradorDeLoggers.h"

const std::string fecha() {
	time_t tiempo = time(0);
	struct tm tiempoStruct = *localtime(&tiempo);
	char buf[80];
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tiempoStruct);
	return buf;
}

//Logger::Logger(const char* nombre) :
//		archivo(nombre) {
//	this->nombre = nombre;
//}

Logger::~Logger() {
	archivo.close();
}

void Logger::error(std::string mensaje) {
	Archivo *a = AdministradorDeLoggers::getLogger(ERROR);
	a->escribir(fecha() + " [ERROR]: " + mensaje);
}

void Logger::warning(std::string mensaje) {
	Archivo *a = AdministradorDeLoggers::getLogger(WARN);
	a->escribir(fecha() + " [WARN]: " + mensaje);
}

void Logger::debug(std::string mensaje) {
	Archivo *a = AdministradorDeLoggers::getLogger(DEBUG);
	a->escribir(fecha() + " [DEBUG]: " + mensaje);
}

void Logger::fatal(std::string mensaje) {
	Archivo *a = AdministradorDeLoggers::getLogger(FATAL);
	a->escribir(fecha() + " [FATAL]: " + mensaje);
}

void Logger::info(std::string mensaje) {
	Archivo *a = AdministradorDeLoggers::getLogger(INFO);
	a->escribir(fecha() + " [INFO]: " + mensaje);
}


//void Logger::borrar() {
//	archivo.close();
//	archivo.open(nombre.c_str(),std::ofstream::trunc);
//}

void Logger::concatenar(std::string& mensajeOriginal,float numero){
	 std::stringstream ss (std::stringstream::out);
	 ss << numero;
	 mensajeOriginal.append(ss.str());
}

Logger::Logger() {
	this->nombre = "";
}
