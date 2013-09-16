/*
 * Archivo.h
 *
 *  Created on: 15/09/2013
 *      Author: javier
 */

#ifndef ARCHIVO_H_
#define ARCHIVO_H_

#include <fstream>
#include <yaml-cpp/yaml.h>

enum TIPO {LECTURA, ESCRITURA, APPEND};

class Archivo {
public:
	Archivo(const char* nombre, TIPO tipo);
	virtual ~Archivo();
	void escribir(std::string dato);
	std::string leer();
	std::string getNombre();
	YAML::Node obtenerNodo(std::string nombre);
	void sobreescribir(YAML::Node nodo);
	Archivo(const Archivo &a);
	void cerrar();
private:
	std::string nombre;
	std::fstream archivo;
};

#endif /* ARCHIVO_H_ */
