/*
 * NivelDAO.cpp
 *
 *  Created on: 15/09/2013
 *      Author: javier
 */

#include "NivelDAO.h"
#include <yaml-cpp/yaml.h>
#include "src/figura/Figura.h"
#include "src/objeto/Plataforma.h"
#include "src/objeto/Balancin.h"
#include "src/objeto/CintaTransportadora.h"
#include "src/objeto/BolaBoliche.h"
#include "src/objeto/GloboHelio.h"
#include "src/objeto/PelotaJuego.h"
#include "src/objeto/Motor.h"
#include "src/objeto/Correa.h"
#include "src/objeto/Soga.h"
#include "src/objeto/Engranaje.h"
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
			this->obtenerCintas(lista,objetos);
			this->obtenerPlataformas(lista,objetos);
			this->obtenerBalancines(lista,objetos);
			this->obtenerBolasDeBoliche(lista,objetos);
			this->obtenerGlobosHelio(lista,objetos);
			this->obtenerPelotasJuego(lista,objetos);
			this->obtenerMotores(lista,objetos);
			this->obtenerEngranajes(lista,objetos);
			this->obtenerCorreas(lista,objetos);
			this->obtenerSogas(lista,objetos);
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

//bool NivelDAO::validar(const Figura& obj, const YAML::Node& circulos,
//		std::size_t i) {
//	if (obj.getX() > 100 || obj.getX() < 0 || obj.getY() < 0
//			|| obj.getY() > 100) {
//		Logger log;
//		std::string msj = "Objeto con posicion invalida, es omitido (";
//		log.concatenar(msj, obj.getX());
//		msj = msj + ";";
//		log.concatenar(msj, obj.getY());
//		msj = msj + ")";
//		YAML::Mark marca = circulos[i].Mark();
//		msj = msj + " en la linea ";
//		log.concatenar(msj, marca.line);
//		log.warning(msj);
//		return false;
//	}
//	return true;
//}




void NivelDAO::obtenerGlobosHelio(std::list<Figura*> &lista, YAML::Node objetos){
	YAML::Node globos = objetos["GlobosHelio"];
	if(globos.Mark().line == -1 ){
		std::string mensaje = "No se encuentrò la etiqueta GlobosHelio";
		logg.info(mensaje);
		}
	for (std::size_t i = 0; i < globos.size(); i++) {
		try {
			GloboHelio obj = globos[i].as<GloboHelio>();
//			bool salir = validar(obj, globos, i);
//			if(!salir ) continue;
			lista.push_back( new GloboHelio(obj));
			//lista.push_back( new Pelota(obj.getX(), obj.getY(), NULL, obj.getRadio()));
		} catch (YAML::Exception &exc) {
			std::string mensaje = "Error al leer Globos: ";
			mensaje.append(exc.what());
			imprimirLinea(mensaje,  globos[i].Mark() );
		}
	}
}


void NivelDAO::obtenerPlataformas(std::list<Figura*> &lista, YAML::Node objetos){
	YAML::Node plataformas = objetos["Plataformas"];
	if(plataformas.Mark().line == -1 ){
		std::string mensaje = "No se encuentrò la etiqueta Plataformas";
		logg.info(mensaje);
	}
	for (std::size_t i = 0; i < plataformas.size(); i++) {
		try {
			Plataforma obj = plataformas[i].as<Plataforma>();
//			bool salir = validar(obj, plataformas, i);
//			if(!salir ) continue;
			lista.push_back( new Plataforma(obj));
			//lista.push_back( new Rueda(obj.getX(), obj.getY(), 0, obj.getRadio()));
		} catch (YAML::Exception &exc) {
			std::string mensaje = "Error al leer Plataformas: ";
			mensaje.append(exc.what());
			imprimirLinea(mensaje, plataformas[i].Mark() );
		}
	}
}

void NivelDAO::obtenerCorreas(std::list<Figura*> &lista, YAML::Node objetos){
	YAML::Node correas = objetos["Correas"];
	if(correas.Mark().line == -1 ){
		std::string mensaje = "No se encuentrò la etiqueta Correas";
		logg.info(mensaje);
	}
	for (std::size_t i = 0; i < correas.size(); i++) {
		try {
			Correa obj = correas[i].as<Correa>();
			lista.push_back( new Correa(obj));
		} catch (YAML::Exception &exc) {
			std::string mensaje = "Error al leer Correas: ";
			mensaje.append(exc.what());
			imprimirLinea(mensaje, correas[i].Mark() );
		}
	}
}

void NivelDAO::obtenerSogas(std::list<Figura*> &lista, YAML::Node objetos){
	YAML::Node correas = objetos["Sogas"];
	if(correas.Mark().line == -1 ){
		std::string mensaje = "No se encuentrò la etiqueta Sogas";
		logg.info(mensaje);
	}
	for (std::size_t i = 0; i < correas.size(); i++) {
		try {
			Soga obj = correas[i].as<Soga>();
			lista.push_back( new Soga(obj));
		} catch (YAML::Exception &exc) {
			std::string mensaje = "Error al leer Sogas: ";
			mensaje.append(exc.what());
			imprimirLinea(mensaje, correas[i].Mark() );
		}
	}
}

void NivelDAO::obtenerCintas(std::list<Figura*> &lista, YAML::Node objetos){
	YAML::Node cintas = objetos["Cintas"];
	if(cintas.Mark().line == -1 ){
		std::string mensaje = "No se encuentrò la etiqueta Cintas";
		logg.info(mensaje);
	}
	for (std::size_t i = 0; i < cintas.size(); i++) {
		try {
			CintaTransportadora obj = cintas[i].as<CintaTransportadora>();
			lista.push_back( new CintaTransportadora(obj));
			//lista.push_back( new Rueda(obj.getX(), obj.getY(), 0, obj.getRadio()));
		} catch (YAML::Exception &exc) {
			std::string mensaje = "Error al leer Cintas transportadoras: ";
			mensaje.append(exc.what());
			imprimirLinea(mensaje, cintas[i].Mark() );
		}
	}
}

void NivelDAO::obtenerBalancines(std::list<Figura*> &lista, YAML::Node objetos){
	YAML::Node balancines = objetos["Balancines"];
	if(balancines.Mark().line == -1 ){
		std::string mensaje = "No se encuentrò la etiqueta Balancines";
		logg.info(mensaje);
	}
	for (std::size_t i = 0; i < balancines.size(); i++) {
		try {
			Balancin obj = balancines[i].as<Balancin>();
//			bool salir = validar(obj,balancines, i);
//			if(!salir ) continue;
			lista.push_back( new Balancin(obj));
			//lista.push_back( new Rueda(obj.getX(), obj.getY(), 0, obj.getRadio()));
		} catch (YAML::Exception &exc) {
			std::string mensaje = "Error al leer Balancines: ";
			mensaje.append(exc.what());
			imprimirLinea(mensaje, balancines[i].Mark() );
		}
	}
}

void NivelDAO::obtenerBolasDeBoliche(std::list<Figura*> &lista, YAML::Node objetos){
	YAML::Node bolasboliche = objetos["BolasBoliche"];
	if(bolasboliche.Mark().line == -1 ){
		std::string mensaje = "No se encuentrò la etiqueta BolasBoliche";
		logg.info(mensaje);
	}
	for (std::size_t i = 0; i < bolasboliche.size(); i++) {
		try {
			BolaBoliche obj = bolasboliche[i].as<BolaBoliche>();
//			bool salir = validar(obj,bolasboliche, i);
//			if(!salir ) continue;
			lista.push_back( new BolaBoliche(obj));
			//lista.push_back( new Rueda(obj.getX(), obj.getY(), 0, obj.getRadio()));
		} catch (YAML::Exception &exc) {
			std::string mensaje = "Error al leer Balancines: ";
			mensaje.append(exc.what());
			imprimirLinea(mensaje, bolasboliche[i].Mark() );
		}
	}
}

Nivel* NivelDAO::cargarPrimerNivel() {
	std::list<std::string> nombres = AdministradorDeArchivos::getNombres();
	std::string nombre = nombres.front().substr(0, nombres.front().size() - 5);
	return leerNivel(nombre);
}

void NivelDAO::obtenerPelotasJuego(std::list<Figura*>& lista,
		YAML::Node objetos) {

	YAML::Node pelotasJuego = objetos["PelotasJuego"];
	if(pelotasJuego.Mark().line == -1 ){
		std::string mensaje = "No se encuentrò la etiqueta PelotasJuego";
		logg.info(mensaje);
		}
	for (std::size_t i = 0; i < pelotasJuego.size(); i++) {
		try {
			PelotaJuego obj = pelotasJuego[i].as<PelotaJuego>();
//			bool salir = validar(obj, pelotasJuego, i);
//			if(!salir ) continue;
			lista.push_back( new PelotaJuego(obj));
			//lista.push_back( new Pelota(obj.getX(), obj.getY(), NULL, obj.getRadio()));
		} catch (YAML::Exception &exc) {
			std::string mensaje = "Error al leer pelotas: ";
			mensaje.append(exc.what());
			imprimirLinea(mensaje,  pelotasJuego[i].Mark() );
		}
	}
}

void NivelDAO::obtenerMotores(std::list<Figura*>& lista,
		YAML::Node objetos) {

	YAML::Node motores = objetos["Motores"];
	if(motores.Mark().line == -1 ){
		std::string mensaje = "No se encuentrò la etiqueta Motores";
		logg.info(mensaje);
		}
	for (std::size_t i = 0; i < motores.size(); i++) {
		try {
			Motor obj = motores[i].as<Motor>();
//			bool salir = validar(obj, motores, i);
//			if(!salir ) continue;
			lista.push_back( new Motor(obj));
			//lista.push_back( new Pelota(obj.getX(), obj.getY(), NULL, obj.getRadio()));
		} catch (YAML::Exception &exc) {
			std::string mensaje = "Error al leer Motores: ";
			mensaje.append(exc.what());
			imprimirLinea(mensaje,  motores[i].Mark() );
		}
	}
}
void NivelDAO::obtenerEngranajes(std::list<Figura*>& lista,
		YAML::Node objetos) {

	YAML::Node engranajes = objetos["Engranajes"];
	if(engranajes.Mark().line == -1 ){
		std::string mensaje = "No se encuentrò la etiqueta Engranajes";
		logg.info(mensaje);
		}
	for (std::size_t i = 0; i < engranajes.size(); i++) {
		try {
			Engranaje obj = engranajes[i].as<Engranaje>();
//			bool salir = validar(obj, pelotasJuego, i);
//			if(!salir ) continue;
			lista.push_back( new Engranaje(obj));
			//lista.push_back( new Pelota(obj.getX(), obj.getY(), NULL, obj.getRadio()));
		} catch (YAML::Exception &exc) {
			std::string mensaje = "Error al leer Engranajes: ";
			mensaje.append(exc.what());
			imprimirLinea(mensaje,  engranajes[i].Mark() );
		}
	}
}

