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
#include "src/figura/Cuadrado.h"
#include "src/figura/Circulo.h"
#include "src/figura/Pelota.h"
#include "src/figura/Globo.h"
#include "src/figura/Resorte.h"
#include "src/figura/Martillo.h"
#include "src/figura/Bloque.h"
#include "src/figura/Cohete.h"
#include "src/figura/Rueda.h"
#include "src/figura/Carrito.h"
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
	}catch(YAML::ParserException& exc){
		std::string mensaje = "Error de parseo de datos del archivo yaml en la linea ";
		std::string s;
		std::stringstream out;
		out << exc.mark.line + 1;
		s = out.str();
		mensaje.append(s);
		mensaje.append(". Se procederà a sobreecribir el archivo");
		logg.error(mensaje);
	}
	Nivel *n = new Nivel(nombre);
	try {
		n->setFondo(nodoRaiz["Nivel"]["Fondo"].as<std::string>());
	} catch (YAML::Exception& exc) {
		std::string msj = "No se pudo cargar el fondo del nivel: " + string(exc.what());
		imprimirLinea(msj, nodoRaiz.Mark());

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
	}
}

std::list<Figura*> NivelDAO::leerFiguras(YAML::Node objetos){
	std::list<Figura*> lista;

		try{
			this->obtenerCirculos(lista,objetos);
			this->obtenerCuadrados(lista,objetos);
			this->obtenerTriangulos(lista,objetos);
			this->obtenerPelotas(lista,objetos);
			this->obtenerGlobos(lista,objetos);
			this->obtenerResortes(lista,objetos);
			this->obtenerMartillos(lista,objetos);
			this->obtenerBloques(lista,objetos);
			this->obtenerCohetes(lista,objetos);
			this->obtenerRuedas(lista,objetos);
			this->obtenerCarritos(lista,objetos);
		}catch(YAML::BadFile& exc){
			std::string mensaje = "No se pudo crear/abrir el archivo: ";
			mensaje.append(exc.what());
			logg.fatal(mensaje);
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

// Evidentemente hay una forma de parametrizar esto,
// pero a esta hora no se me ocurre cual es.

void NivelDAO::obtenerCirculos(std::list<Figura*> &lista, YAML::Node objetos){
	YAML::Node circulos = objetos["Circulos"];

	for (std::size_t i = 0; i < circulos.size(); i++) {
		try {
			Circulo obj = circulos[i].as<Circulo>();
			bool salir = validar(obj, circulos, i);
			if(!salir ) continue;
			lista.push_back( new Circulo(obj));

			//lista.push_back(new Circulo(obj.getX(), obj.getY(),0, obj.getRadio()));
		} catch (YAML::Exception &exc) {
			std::string mensaje = "Error al leer circulo: ";
			mensaje.append(exc.what());
			imprimirLinea(mensaje, circulos[i].Mark() );
		}
	}
}

void NivelDAO::obtenerCuadrados(std::list<Figura*> &lista, YAML::Node objetos){
	YAML::Node cuadrados = objetos["Cuadrados"];

	for (std::size_t i = 0; i < cuadrados.size(); i++) {
		try {
			Cuadrado obj = cuadrados[i].as<Cuadrado>();
			lista.push_back( new Cuadrado(obj));
			//lista.push_back( new Cuadrado(obj.getX(), obj.getY(),0, obj.getAncho(), obj.getAlto()));
		} catch (YAML::Exception &exc) {
			std::string mensaje = "Error al leer cuadrado: ";
			mensaje.append(exc.what());
			imprimirLinea(mensaje,  cuadrados[i].Mark() );
		}
	}
}

void NivelDAO::obtenerTriangulos(std::list<Figura*> &lista, YAML::Node objetos){
	YAML::Node triangulos = objetos["Triangulos"];

	for (std::size_t i = 0; i < triangulos.size(); i++) {
		try {
			Triangulo obj = triangulos[i].as<Triangulo>();
			lista.push_back( new Triangulo(obj.getX(), obj.getY(),0, obj.getAncho(), obj.getAlto()));
		} catch (YAML::Exception &exc) {
			std::string mensaje = "Error al leer Triangulos: ";
			mensaje.append(exc.what());
			imprimirLinea(mensaje,  triangulos[i].Mark() );
		}
	}
}

void NivelDAO::obtenerPelotas(std::list<Figura*> &lista, YAML::Node objetos){
	YAML::Node pelotas = objetos["Pelotas"];

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
	YAML::Node globos = objetos["Globos"];
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


void NivelDAO::obtenerResortes(std::list<Figura*> &lista, YAML::Node objetos){
	YAML::Node resortes = objetos["Resortes"];
	for (std::size_t i = 0; i < resortes.size(); i++) {
		try {
			Resorte obj = resortes[i].as<Resorte>();
			bool salir = validar(obj, resortes, i);
			if(!salir ) continue;
			lista.push_back( new Resorte(obj));
			//lista.push_back( new Resorte(obj.getX(), obj.getY(), 0, obj.getAncho(), obj.getAlto()));
		} catch (YAML::Exception &exc) {
			std::string mensaje = "Error al leer resortes: ";
			mensaje.append(exc.what());
			imprimirLinea(mensaje,  resortes[i].Mark() );
		}
	}
}


void NivelDAO::obtenerMartillos(std::list<Figura*> &lista, YAML::Node objetos){
	YAML::Node martillos = objetos["Martillos"];
	for (std::size_t i = 0; i < martillos.size(); i++) {
		try {
			Martillo obj = martillos[i].as<Martillo>();
			bool salir = validar(obj, martillos, i);
			if(!salir ) continue;
			lista.push_back( new Martillo(obj));
			//lista.push_back( new Martillo(obj.getX(), obj.getY(), 0, obj.getAncho(), obj.getAlto()));
		} catch (YAML::Exception &exc) {
			std::string mensaje = "Error al leer martillos: ";
			mensaje.append(exc.what());
			imprimirLinea(mensaje, martillos[i].Mark() );
		}
	}
}


void NivelDAO::obtenerBloques(std::list<Figura*> &lista, YAML::Node objetos){
	YAML::Node bloques = objetos["Bloques"];
	for (std::size_t i = 0; i < bloques.size(); i++) {
		try {
			Bloque obj = bloques[i].as<Bloque>();
			bool salir = validar(obj, bloques, i);
			if(!salir ) continue;
			lista.push_back( new Bloque(obj));
			//lista.push_back( new Bloque(obj.getX(), obj.getY(), 0, obj.getAncho(), obj.getAlto()));
		} catch (YAML::Exception &exc) {
			std::string mensaje = "Error al leer bloques: ";
			mensaje.append(exc.what());
			imprimirLinea(mensaje,  bloques[i].Mark() );
		}
	}
}


void NivelDAO::obtenerCohetes(std::list<Figura*> &lista, YAML::Node objetos){
	YAML::Node Cohetes = objetos["Cohetes"];
	for (std::size_t i = 0; i < Cohetes.size(); i++) {
		try {
			Cohete obj = Cohetes[i].as<Cohete>();
			bool salir = validar(obj, Cohetes, i);
			if(!salir ) continue;
			lista.push_back( new Cohete(obj));
			//lista.push_back( new Cohete(obj.getX(), obj.getY(), 0, obj.getAncho(), obj.getAlto()));
		} catch (YAML::Exception &exc) {
			std::string mensaje = "Error al leer Cohetes: ";
			mensaje.append(exc.what());
			imprimirLinea(mensaje,  Cohetes[i].Mark() );
		}
	}
}


void NivelDAO::obtenerRuedas(std::list<Figura*> &lista, YAML::Node objetos){
	YAML::Node Ruedas = objetos["Ruedas"];
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

void NivelDAO::obtenerCarritos(std::list<Figura*> &lista, YAML::Node objetos){
	YAML::Node Carritos = objetos["Carritos"];
	for (std::size_t i = 0; i < Carritos.size(); i++) {
		try {
			Carrito obj = Carritos[i].as<Carrito>();
			bool salir = validar(obj, Carritos, i);
			if(!salir ) continue;
			lista.push_back( new Carrito(obj));
			//lista.push_back( new Carrito(obj.getX(), obj.getY(), 0, obj.getAncho(), obj.getAlto()));
		} catch (YAML::Exception &exc) {
			std::string mensaje = "Error al leer Carritos: ";
			mensaje.append(exc.what());
			imprimirLinea(mensaje,  Carritos[i].Mark() );
		}
	}
}

Nivel* NivelDAO::cargarPrimerNivel() {
	std::list<std::string> nombres = AdministradorDeArchivos::getNombres();
	std::string nombre = nombres.front().substr(0, nombres.front().size() - 5);
	return leerNivel(nombre);
}
