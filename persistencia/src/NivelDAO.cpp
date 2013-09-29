/*
 * NivelDAO.cpp
 *
 *  Created on: 15/09/2013
 *      Author: javier
 */

#include "NivelDAO.h"
#include <yaml-cpp/yaml.h>
#include "src/figura/Figura.h"
#include "src/figura/Triangulo.h"
#include "src/figura/Circulo.h"
#include "src/figura/Pelota.h"
#include "src/figura/Rueda.h"
#include "src/figura/Globo.h"
#include "constructoresYAML.h"
#include "ObjetoDAO.h"
#include "NivelInexistenteException.h"
using namespace std;

//#include "src/controller/RotadorSistemaCoordenadas.h"

#define OBJETOS "Objetos"

NivelDAO::NivelDAO() {
	// TODO Auto-generated constructor stub

}

NivelDAO::~NivelDAO() {
	// TODO Auto-generated destructor stub
}

Nivel* NivelDAO::leerNivel(const std::string &nombre) {
	return leerNivel(nombre.c_str());
}

Nivel* NivelDAO::leerNivel(const char *nombre) {
	Archivo *a = administrador.obtenerArchivoNivel(nombre);
	YAML::Node nodoRaiz;
	YAML::Node nodo;
	if (!a) {

		logg.error("No se pudo cargar el nivel. El archivo no existe.");
		throw NivelInexistenteException();
	}
	try{
	nodoRaiz = a->obtenerNodoRaiz();
	nodo = a->obtenerNodo(OBJETOS);
	if(nodo.Mark().line == -1 ){
		std::string mensaje = "No se encontrò la etiqueta Objetos, en consecuencia no se cargan figuras";
		logg.warning(mensaje);
	}
	}catch(YAML::BadFile& exc){
		std::string mensaje = "No se pudo crear/abrir el archivo: ";
		mensaje.append(a->getNombre());
		logg.fatal(mensaje);
	}
	catch(YAML::ParserException& exc){
		std::string mensaje = "Error de parseo de datos del archivo yaml en la linea ";
		std::string s;
		std::stringstream out;
		out << exc.mark.line;
		s = out.str();
		mensaje.append(s);
		mensaje.append(". Se procederà a sobreecribir el archivo");
		logg.error(mensaje);
	}catch (YAML::BadConversion& exc) {
		std::string msj = "No se pudo cargar el nivel: " + string(exc.what());
		std::string s;
		std::stringstream out;
		//out << nodoRaiz.Mark().line/*nodoRaiz.Mark().line +1*/;
		s = out.str();
		msj.append(s);
		logg.error(msj);

	}

	Nivel *n = new Nivel(nombre);
	try {
		n->setFondo(nodoRaiz["Nivel"]["Fondo"].as<std::string>());
	} catch (YAML::BadConversion& exc) {
		std::string msj = "No se pudo cargar el fondo del nivel: " + string(exc.what());
		logg.error(msj);
	}
	std::list<Figura*> figuras = leerFiguras(nodo);
	std::list<Figura*>::iterator it;
	for (it = figuras.begin(); it != figuras.end(); ++it){
		n->agregar(*it);
	}
	return n;
}

void NivelDAO::guardarNivel(Nivel *nivel) {
	Archivo *a = administrador.obtenerArchivoNivel(nivel->getNombre());
	if (!a) {
		// Se esta guardando un nivel nuevo, sin archivo previo
		// O el archivo no se registro antes.
		a = AdministradorDeArchivos::crearArchivoNivel(nivel->getNombre().c_str());
	}
	YAML::Node nodoRaiz;
	nodoRaiz["Nivel"] = *nivel;
	YAML::Node nodoFiguras;
	std::list<Figura*>::iterator it;
	ObjetoDAO oDao;
	std::list<Figura*> &listaFiguras = nivel->getFiguras();
	bool vacio = true;
	for (it = listaFiguras.begin(); it != listaFiguras.end(); ++it) {
		oDao.guardarFigura(*it, &nodoFiguras);
		vacio = false;
	}
	if(!vacio) nodoRaiz[OBJETOS] = nodoFiguras;
	a->sobreescribir(nodoRaiz);
	a->cerrar();
}

void NivelDAO::imprimirLinea(std::string & msj, YAML::Mark marca) {
	if (msj.find("line") == std::string::npos) {
		std::stringstream aux;
		aux << msj << " en la linea " << marca.line;
		logg.error(aux.str());
	} else {
		logg.error(msj);
	}
}

std::list<Figura*> NivelDAO::leerFiguras(YAML::Node objetos){
	std::list<Figura*> lista;

		try{
			this->obtenerPelotas(lista,objetos);
			this->obtenerGlobos(lista,objetos);
			this->obtenerRuedas(lista,objetos);
		}catch(YAML::BadFile& exc){
			std::string mensaje = "No se pudo crear/abrir el archivo: ";
			mensaje.append(exc.what());
			logg.fatal(mensaje);
		}catch (YAML::BadSubscript& exc) {
		std::string msj = "No hay reconocimiento de figuras validas en la linea ";
		std::string s;
		std::stringstream out;
		out << objetos.Mark().line;
		s = out.str();
		msj.append(s);
		logg.error(msj);

	}
	return lista;
}

bool NivelDAO::validar(const Figura& obj, const YAML::Node& circulos,
		std::size_t i) {
	if (obj.getX() > 100 || obj.getX() < 0 || obj.getY() < 0
			|| obj.getY() > 100) {
		Logger log;
		std::string msj = "Objeto con posicion invalida, es omitido (";
		log.concatenar(msj, obj.getX());
		msj = msj + ";";
		log.concatenar(msj, obj.getY());
		msj = msj + ")";
		YAML::Mark marca = circulos[i].Mark();
		msj = msj + " en la linea ";
		log.concatenar(msj, marca.line);
		log.warning(msj);
		return false;
	}
	return true;
}



void NivelDAO::obtenerPelotas(std::list<Figura*> &lista, YAML::Node objetos){
	YAML::Node pelotas = objetos["Pelotas"];
	if(pelotas.Mark().line == -1 ){
		std::string mensaje = "No se encuentrò la etiqueta Pelotas";
		logg.info(mensaje);
		}
	for (std::size_t i = 0; i < pelotas.size(); i++) {
		try {
			Pelota obj = pelotas[i].as<Pelota>();
			bool salir = validar(obj, pelotas, i);
			if(!salir ) continue;
			lista.push_back( new Pelota(obj));
			//lista.push_back( new Pelota(obj.getX(), obj.getY(), NULL, obj.getRadio()));
		} catch (YAML::Exception &exc) {
			std::string mensaje = "Error al leer pelotas: ";
			mensaje.append(exc.what());
			imprimirLinea(mensaje,  pelotas[i].Mark() );
		}
	}
}

void NivelDAO::obtenerGlobos(std::list<Figura*> &lista, YAML::Node objetos){
	YAML::Node globos =  objetos["Globos"];
	if(globos.Mark().line == -1 ){
		std::string mensaje = "No se encuentrò la etiqueta Globos";
		logg.info(mensaje);
	}
	for (std::size_t i = 0; i < globos.size(); i++) {
		try {
			Globo obj = globos[i].as<Globo>();
			bool salir = validar(obj, globos, i);
			if(!salir ) continue;
			lista.push_back( new Globo(obj));
			//lista.push_back( new Globo(obj.getX(), obj.getY(), NULL, obj.getRadio()));
		} catch (YAML::Exception &exc) {
			std::string mensaje = "Error al leer globos\n";
			mensaje.append(exc.what());
			imprimirLinea(mensaje,  globos[i].Mark() );
		}
	}
}


void NivelDAO::obtenerRuedas(std::list<Figura*> &lista, YAML::Node objetos){
	YAML::Node Ruedas = objetos["Ruedas"];
	if(Ruedas.Mark().line == -1 ){
		std::string mensaje = "No se encuentrò la etiqueta Ruedas";
		logg.info(mensaje);
	}
	for (std::size_t i = 0; i < Ruedas.size(); i++) {
		try {
			Rueda obj = Ruedas[i].as<Rueda>();
			bool salir = validar(obj, Ruedas, i);
			if(!salir ) continue;
			lista.push_back( new Rueda(obj));
			//lista.push_back( new Rueda(obj.getX(), obj.getY(), 0, obj.getRadio()));
		} catch (YAML::Exception &exc) {
			std::string mensaje = "Error al leer Ruedas: ";
			mensaje.append(exc.what());
			imprimirLinea(mensaje, Ruedas[i].Mark() );
		}
	}
}


Nivel* NivelDAO::cargarPrimerNivel() {
	std::list<std::string> nombres = AdministradorDeArchivos::getNombres();
	std::string nombre = nombres.front().substr(0, nombres.front().size() - 5);
	return leerNivel(nombre);
}
