/*
 * Serializador.cpp
 *
 *  Created on: 30/10/2013
 *      Author: ezequiel
 */

#include "Serializador.h"
#include "SerializacionException.h"
#include "mensajes/userEvents/ClickMsj.h"
#include "mensajes/ConfiguracionNivelMsj.h"
#include "src/ManejadorErrores.h"
#include "mensajes/userEvents/JugadorListo.h"
#include "mensajes/viewMensaje/FinDibujado.h"
#include "mensajes/viewMensaje/ViewBotonStartMsj.h"
#include "mensajes/viewMensaje/Highlight.h"
#include "mensajes/viewMensaje/ViewCarritoMsj.h"
#include "mensajes/viewMensaje/ViewTijeraMsj.h"
#include "mensajes/viewMensaje/MensajeCantidadRestante.h"
#include <errno.h>
#define MAX_BUFFER 524288
Serializador::Serializador(int destinatario) {
	this->mensajes.insert(
			pair<string, NetworkMensaje*>(string(TAG_VIEW_OBJETO_SIMPLE), new ViewObjetoUpdateMsj(0, 0, 0, 0, 'a', 0)));
	this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_MSJ_PLANO), new MensajePlano("")));
	this->mensajes.insert(
			pair<string, NetworkMensaje*>(string(TAG_VIEW_OBJETO_CON_ANCHO),
					new ViewObjetoConAnchoUpdateMsj(0, 0, 0, 0, 0, 'a', 0)));
	this->mensajes.insert(
			pair<string, NetworkMensaje*>(string(TAG_VIEW_OBJETO_UNION),
					new ViewObjetoUnionUpdateMsj(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'a', 0)));
	this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_CLICK), new ClickMsj(0, 0, 0, 0, 0, 0)));
	this->mensajes.insert(pair<string, NetworkMensaje*>(string(MSJ_CONFIG_JUGADOR), new ConfiguracionNivelMsj()));
	this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_MOUSE_MOTION), new MouseMotionMsj(0, 0, 0, 0)));
	this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_CREACION_OBJETO), new CreacionMsj("", 0, 0)));
	this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_JUGADOR_LISTO), new JugadorListo(false)));
	this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_FIN_DIBUJADO), new FinDibujado()));
	this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_BOTON_LISTO), new ViewBotonStartMsj(0, false)));
	this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_HIGHLIGHT), new Highlight(0)));
	this->mensajes.insert(
			pair<string, NetworkMensaje*>(string(TAG_VIEW_CARRITO),
					new ViewCarritoMsj(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)));
	this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_VIEW_TIJERA), new ViewTijeraMsj(0, 0, 0, 0, 0, 0)));
	this->mensajes.insert(
			pair<string, NetworkMensaje*>(string(TAG_CANTIDAD_RESTANTE), new MensajeCantidadRestante(0, 0)));

	this->destinatario = destinatario;

}

Serializador::~Serializador() {
	map<string, NetworkMensaje*>::const_iterator iter;
	for (iter = this->mensajes.begin(); iter != this->mensajes.end(); ++iter) {
		delete iter->second;
	}
}

void Serializador::leer(int sock, list<NetworkMensaje*> & lista) {

//	string buffer;
	char buffer[MAX_BUFFER] = "";
//	char bufferAux[25000] = "";
	int longitudTotal;
	int recibidos = 0;

	//
	int result = recv(sock, &longitudTotal, sizeof(int), MSG_NOSIGNAL);
//	string mje= "bytes ";
//	log.concatenar(mje, longitudTotal);
//	log.debug(mje);
	if (result == -1) {
		ManejadorErrores::manejarWriteError(errno);
		throw SerializacionException("No se pudo recibir el mensaje del host");
	}

	while (recibidos < longitudTotal) {
//		result = recv(sock, &longRecibida, sizeof(int),MSG_NOSIGNAL);
		if (result == -1) {
			ManejadorErrores::manejarWriteError(errno);
			throw SerializacionException("No se pudo recibir el mensaje del host");
		}
		result = recv(sock, &(buffer[recibidos]), longitudTotal - recibidos, MSG_NOSIGNAL);

		if (result == -1) {
			ManejadorErrores::manejarWriteError(errno);
			throw SerializacionException("No se pudo recibir el mensaje del host");
		}
		recibidos += result;
//		strcat(buffer, bufferAux);s
	}

	string clave;

	string aux = buffer;
//	cout <<  longitud << endl;
	YAML::Node lineup = YAML::Load(aux.substr(0, longitudTotal));
	NetworkMensaje * msj;
	YAML::const_iterator it = lineup.begin();
	//TODO PROBAR ESTO DE ENVIAR MIERDA A VER QUE HACE
	while (it != lineup.end()) {
		bool tagEncontrado = false;
		while (!tagEncontrado && it != lineup.end()) {
			try {
				tagEncontrado = true;
				clave = it->as<string>();
				it++;
			} catch (YAML::Exception &exc) {
				//AVANZO A VER SI ENCUENTRO ALGO INTERESANTE PARA LEER
				log.debug("Error de yaml");
				tagEncontrado = false;
				it++;
			}
		}

		if (tagEncontrado) {
//			cout << clave<<endl;
			std::map<string, NetworkMensaje*>::iterator msjCreator = this->mensajes.find(clave);
			if (msjCreator != mensajes.end()) {
				try {
					msj = msjCreator->second->deserialize(it);
					msj->setDestinatario(this->destinatario);
					lista.push_back(msj);
				} catch (YAML::Exception &exc) {
					//AVANZO A VER SI ENCUENTRO ALGO INTERESANTE PARA LEER
					string msj ="Error de serializacion :";
					msj.append(exc.what());
					log.error(msj);
					it++;
				}
			} else {
				log.debug(("No encontro tag " + clave));
				//AVANZO A VER SI ENCUENTRO ALGO INTERESANTE PARA LEER
				it++;
			}
		}
	}
}

void Serializador::escribir(list<NetworkMensaje*>& lista, int socket) {
	list<NetworkMensaje*>::iterator it = lista.begin();
	YAML::Node nodo;
	YAML::Emitter o;
	o << YAML::BeginSeq;
	while (it != lista.end()) {
		(*it)->serialize(o);
		it++;

	}
	o << YAML::EndSeq;

	int enviados = 0;
	int len = strlen(o.c_str());
	int longEnviada;
	if (len <= MAX_BUFFER) {
		int result = send(socket, &len, sizeof(int), MSG_NOSIGNAL);	//envio longitud total
		if (result == -1) {
			ManejadorErrores::manejarWriteError(errno);
			throw SerializacionException("No se pudo enviar el mensaje al host");
		}
		while (enviados < len) {
			longEnviada = len - enviados;
			//Ahora intento enviar lo restante.
			result = send(socket, &(o.c_str()[enviados]), longEnviada, MSG_NOSIGNAL);
			//Si da error cancelo
			if (result == -1) {
				ManejadorErrores::manejarWriteError(errno);
				throw SerializacionException("No se pudo enviar el mensaje al host");
			}

			//Sumo a los enviados lo que envié.
			enviados += result;
//			cout<< "Se enviaron "<< longEnviada<< "restantes  de " << enviados << "/"<<len<<endl;
		}
	} else {
			Logger log;
			log.debug("Se omiten mensjaes por exceder el limitedel buffer");
	}
}

void Serializador::escribir(NetworkMensaje* msj, int socket) {
	list<NetworkMensaje*> lista;
	lista.push_back(msj);
	this->escribir(lista, socket);
}
