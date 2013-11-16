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
#include "src/objeto/Carrito.h"
#include "src/objeto/CintaTransportadora.h"
#include "src/objeto/BolaBoliche.h"
#include "src/objeto/Gancho.h"
#include "src/objeto/GloboHelio.h"
#include "src/objeto/PelotaJuego.h"
#include "src/objeto/Motor.h"
#include "src/objeto/Correa.h"
#include "src/objeto/Soga.h"
#include "src/objeto/Engranaje.h"
#include "src/objeto/Yunque.h"
#include "src/objeto/Clavo.h"
#include "src/Logger.h"
#include "constructoresYAML.h"
#include "ObjetoDAO.h"
#include "NivelInexistenteException.h"
#include "NoSePuedeGuardarNivelException.h"
#include <fstream>
#include <iostream>
#include <cstdio>
using namespace std;

//#include "src/controller/RotadorSistemaCoordenadas.h"

#define OBJETOS "Objetos"
#define JUGADORES "Jugadores"

NivelDAO::NivelDAO() {
	// TODO Auto-generated constructor stub

}

NivelDAO::~NivelDAO() {
	// TODO Auto-generated destructor stub
}

Nivel* NivelDAO::leerNivel(const std::string &nombre) {
	return leerNivel(nombre.c_str());
}

YAML::Node NivelDAO::getNodoObjetos(YAML::Node nodoRaiz){
	YAML::Node nodoObjetos;
	try{
		nodoObjetos = nodoRaiz[OBJETOS];
		if(nodoObjetos.Mark().line == -1 ){
			std::string mensaje = "No se encontrò la etiqueta Objetos, en consecuencia no se cargan figuras";
			logg.warning(mensaje);
		}
	}catch(YAML::ParserException& exc){
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
	return nodoObjetos;
}


YAML::Node NivelDAO::getNodoJugadores(YAML::Node nodoRaiz){
	YAML::Node nodoJugadores;
	try{
		nodoJugadores = nodoRaiz[JUGADORES];
		if(nodoJugadores.Mark().line == -1 ){
			std::string mensaje = "No se encontrò la etiqueta Jugadores, en consecuencia no se carga la configuracion de jugadores";
			logg.warning(mensaje);
		}
	}catch(YAML::ParserException& exc){
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
	return nodoJugadores;
}

Nivel* NivelDAO::leerNivel(const char *nombre) {

	std::string nombreArchivo(nombre);
	YAML::Node nodoRaiz;
	try{
		nodoRaiz = YAML::LoadFile(nombreArchivo);
	}catch(YAML::BadFile& exception){
		throw NivelInexistenteException();
	}
	YAML::Node nodoObjetos = getNodoObjetos(nodoRaiz);
	YAML::Node nodoJugadores = getNodoJugadores(nodoRaiz);

	Nivel *n = new Nivel();
	try {
			n->setNombre(nodoRaiz["Nivel"]["Nombre"].as<std::string>());
		} catch (YAML::BadConversion& exc) {
			std::string msj = "No se pudo cargar el nombre del nivel: " + string(exc.what());
			logg.error(msj);
	}
	try {
		n->setFondo(nodoRaiz["Nivel"]["Fondo"].as<std::string>());
	} catch (YAML::BadConversion& exc) {
		std::string msj = "No se pudo cargar el fondo del nivel: " + string(exc.what());
		logg.error(msj);
	}
	try {
			n->setNumeroMaximoJugadores(nodoRaiz["Nivel"]["NumeroMaximoDeJugadores"].as<int>());
		} catch (YAML::BadConversion& exc) {
			std::string msj = "No se pudo cargar el numero de jugadores del nivel: " + string(exc.what());
			logg.error(msj);
	}

	std::list<Jugador*> jugadores = leerJugadores(nodoJugadores);
	std::list<Figura*> figuras = leerFiguras(nodoObjetos);
	std::list<Figura*>::iterator itFiguras;
	std::list<Jugador*>::iterator itJugadores;
	for (itFiguras = figuras.begin(); itFiguras != figuras.end(); ++itFiguras){
		n->agregar(*itFiguras);
	}
	for (itJugadores = jugadores.begin(); itJugadores != jugadores.end(); ++itJugadores){
			n->agregarJugador(*itJugadores);
	}
	return n;
}

void NivelDAO::guardarNivel(Nivel *nivel) {
	std::string nombreArchivo = nivel->getNombre();
	nombreArchivo += ".yaml";
	Archivo* archivoDelNivel;
	try{
		archivoDelNivel = new Archivo(nombreArchivo.c_str(),LECTOESCRITURA);
	}catch (std::exception& exc){ //no existe el archivo del ese nivel
		try{
			archivoDelNivel = new Archivo(nombreArchivo.c_str(),ESCRITURA);
		}catch(std::exception& exc){ //no pudo crear el archivo para el nivel
				throw NoSePuedeGuardarNivelException();
		}
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
	//////////////////
	std::list<Jugador*> &listaJugadores = nivel->getJugadores();
	std::list<Jugador*>::iterator iterador;
	YAML::Node nodoJugadores;
	bool vacio1 = true;
	for (iterador = listaJugadores.begin(); iterador != listaJugadores.end(); ++iterador) {
		oDao.guardarJugador(*iterador, &nodoJugadores);
		vacio1 = false;
	}
	if(!vacio1) nodoRaiz[JUGADORES] = nodoJugadores;
	archivoDelNivel->sobreescribir(nodoRaiz);
	delete archivoDelNivel;
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
			this->obtenerCarritos(lista,objetos);
			this->obtenerBolasDeBoliche(lista,objetos);
			this->obtenerGlobosHelio(lista,objetos);
			this->obtenerPelotasJuego(lista,objetos);
			this->obtenerMotores(lista,objetos);
			this->obtenerEngranajes(lista,objetos);
			this->obtenerCorreas(lista,objetos);
			this->obtenerSogas(lista,objetos);
			this->obtenerGanchos(lista,objetos);
			this->obtenerClavos(lista, objetos);
			this->obtenerYunques(lista,objetos);
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

/*Area* NivelDAO::leerArea (YAML::Node nodoJugador){
	Area area = nodoJugador["Area"].as<Area>();
	Area* elArea = new Area(area);
	return elArea;
}

std::list<FactoryParam*> NivelDAO::leerParametrosDeFactories(YAML::Node nodoJugador){
	std::list<FactoryParam*> lista;
	YAML::Node nodoFactories = nodoJugador["ParametrosFactories"];
	for (std::size_t i = 0; i < nodoFactories.size(); i++) {
			try {
				FactoryParam obj = nodoFactories[i].as<FactoryParam>();
				lista.push_back( new FactoryParam(obj));
			}catch(YAML::BadFile& exc){
				std::string mensaje = "No se pudo crear/abrir el archivo: ";
				mensaje.append(exc.what());
				logg.fatal(mensaje);
			}catch (YAML::BadSubscript& exc) {
				std::string msj = "No hay reconocimiento de parametrios para las objetos del jugador";
				std::string s;
				std::stringstream out;
				out << nodoFactories.Mark().line;
				s = out.str();
				msj.append(s);
				logg.error(msj);

			}catch (YAML::Exception &exc) {
				std::string mensaje = "Error al leer parametros de objetos del jugador: ";
				mensaje.append(exc.what());
				imprimirLinea(mensaje, nodoFactories[i].Mark() );
			}
		}
		return lista;
}*/

std::list<Jugador*> NivelDAO::leerJugadores(YAML::Node jugadores){
	std::list<Jugador*> lista;
	std::list<FactoryParam*> objetosDeJugador;
	for (std::size_t i = 0; i < jugadores.size(); i++) {
		try {
			Jugador obj = jugadores[i].as<Jugador>();
			lista.push_back(new Jugador(obj));
		}catch(YAML::BadFile& exc){
			std::string mensaje = "No se pudo crear/abrir el archivo: ";
			mensaje.append(exc.what());
			logg.fatal(mensaje);
		}catch (YAML::BadSubscript& exc) {
			std::string msj = "No hay reconocimiento de jugadores validos en la linea ";
			std::string s;
			std::stringstream out;
			out << jugadores.Mark().line;
			s = out.str();
			msj.append(s);
			logg.error(msj);

		}catch (YAML::Exception &exc) {
			std::string mensaje = "Error al leer jugadores: ";
			mensaje.append(exc.what());
			imprimirLinea(mensaje, jugadores[i].Mark() );
		}
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

void NivelDAO::obtenerCarritos(std::list<Figura*> &lista, YAML::Node objetos){
	YAML::Node carritos = objetos["Carritos"];
	if(carritos.Mark().line == -1 ){
		std::string mensaje = "No se encuentrò la etiqueta Carritos";
		logg.info(mensaje);
	}
	for (std::size_t i = 0; i < carritos.size(); i++) {
		try {
			Carrito obj = carritos[i].as<Carrito>();
//			bool salir = validar(obj,balancines, i);
//			if(!salir ) continue;
			lista.push_back( new Carrito(obj));
			//lista.push_back( new Rueda(obj.getX(), obj.getY(), 0, obj.getRadio()));
		} catch (YAML::Exception &exc) {
			std::string mensaje = "Error al leer Carritos: ";
			mensaje.append(exc.what());
			imprimirLinea(mensaje, carritos[i].Mark() );
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

void NivelDAO::obtenerGanchos(std::list<Figura*> &lista, YAML::Node objetos){
	YAML::Node ganchos = objetos["Ganchos"];
	if(ganchos.Mark().line == -1 ){
		std::string mensaje = "No se encuentrò la etiqueta Ganchos";
		logg.info(mensaje);
		}
	for (std::size_t i = 0; i < ganchos.size(); i++) {
		try {
			Gancho obj = ganchos[i].as<Gancho>();
//			bool salir = validar(obj, globos, i);
//			if(!salir ) continue;
			lista.push_back( new Gancho(obj));
			//lista.push_back( new Pelota(obj.getX(), obj.getY(), NULL, obj.getRadio()));
		} catch (YAML::Exception &exc) {
			std::string mensaje = "Error al leer Globos: ";
			mensaje.append(exc.what());
			imprimirLinea(mensaje,  ganchos[i].Mark() );
		}
	}
}

void NivelDAO::obtenerYunques(std::list<Figura*>& lista, YAML::Node objetos) {
	YAML::Node yunques = objetos["Yunques"];
	if(yunques.Mark().line == -1 ){
		std::string mensaje = "No se encuentrò la etiqueta Yunques";
		logg.info(mensaje);
		}
	for (std::size_t i = 0; i < yunques.size(); i++) {
		try {
			Yunque obj = yunques[i].as<Yunque>();
//			bool salir = validar(obj, globos, i);
//			if(!salir ) continue;
			lista.push_back( new Yunque(obj));
			//lista.push_back( new Pelota(obj.getX(), obj.getY(), NULL, obj.getRadio()));
		} catch (YAML::Exception &exc) {
			std::string mensaje = "Error al leer Yunque: ";
			mensaje.append(exc.what());
			imprimirLinea(mensaje,  yunques[i].Mark() );
		}
	}
}

void NivelDAO::obtenerClavos(std::list<Figura*>& lista, YAML::Node objetos) {
	YAML::Node clavos = objetos["Clavos"];
	if(clavos.Mark().line == -1 ){
		std::string mensaje = "No se encuentrò la etiqueta Clavos";
		logg.info(mensaje);
		}
	for (std::size_t i = 0; i < clavos.size(); i++) {
		try {
			Clavo obj = clavos[i].as<Clavo>();
//			bool salir = validar(obj, globos, i);
//			if(!salir ) continue;
			lista.push_back( new Clavo(obj));
			//lista.push_back( new Pelota(obj.getX(), obj.getY(), NULL, obj.getRadio()));
		} catch (YAML::Exception &exc) {
			std::string mensaje = "Error al leer Clavo: ";
			mensaje.append(exc.what());
			imprimirLinea(mensaje,  clavos[i].Mark() );
		}
	}
}
