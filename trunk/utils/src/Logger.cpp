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

using namespace std;

NIVEL_LOGGER Logger::nivel = DEBUG_N;

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
}

void Logger::error(std::string mensaje) {
	std::string salida = fecha() + " [ERROR]: " + mensaje;
	log(salida,ERROR,ERROR_N);
}

void Logger::warning(std::string mensaje) {
	std::string salida = fecha() + " [WARN]: " + mensaje;
	log(salida,WARN,WARN_N);
}

void Logger::debug(std::string mensaje) {
	std::string salida = fecha() + " [DEBUG]: " + mensaje;
	log(salida,DEBUG,DEBUG_N);

}

void Logger::fatal(std::string mensaje) {
	std::string salida = fecha() + " [FATAL]: " + mensaje;
	log(salida,FATAL,FATAL_N);

}

void Logger::info(std::string mensaje) {
	std::string salida = fecha() + " [INFO]: " + mensaje;
	log(salida,INFO,INFO_N);
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

void Logger::concatenar(std::string& mensajeOriginal,double numero){
	 std::stringstream ss (std::stringstream::out);
	 ss << numero;
	 mensajeOriginal.append(ss.str());
}

void Logger::concatenar(std::string& mensajeOriginal,int numero){
	 std::stringstream ss (std::stringstream::out);
	 ss << numero;
	 mensajeOriginal.append(ss.str());
}

Logger::Logger() {
}

void Logger::setNivel(NIVEL_LOGGER n) {
	Logger::nivel = n;
}


void Logger::log(std::string mensaje, TIPO_LOGGER tLogger,	NIVEL_LOGGER nLog) {
	if(Logger::nivel <= nLog ){
		Archivo *a = AdministradorDeLoggers::getLogger(tLogger);
		cout<< mensaje<< endl;
		a->escribir(mensaje);
	}
}
