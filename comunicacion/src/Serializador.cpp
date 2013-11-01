/*
 * Serializador.cpp
 *
 *  Created on: 30/10/2013
 *      Author: ezequiel
 */

#include "Serializador.h"
#define MAX_BUFFER 1024
Serializador::Serializador() {
this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_VIEW_GLOBO), new ViewGloboUpdateMsj(0,0,0)));
this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_MSJ_PLANO), new MensajePlano("")));
this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_VIEW_BOLA), new ViewBolaBolicheUpdateMsj(0,0,0)));
this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_VIEW_PELOTA), new ViewPelotaUpdateMsj(0,0,0)));
this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_VIEW_PLATAFORMA), new ViewPlataformaUpdateMsj(0,0,0,0)));
this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_VIEW_MOTOR), new ViewMotorUpdateMsj(0,0,0)));
this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_VIEW_CINTA), new ViewCintaUpdateMsj(0,0,0,0)));
this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_VIEW_ENGRANAJE), new ViewEngranajeUpdateMsj(0,0,0,0)));
this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_VIEW_BALANCIN), new ViewBalancinUpdateMsj(0,0,0)));
this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_VIEW_SOGA), new ViewSogaUpdateMje(0,0,0,0)));
}

Serializador::~Serializador() {
	map<string, NetworkMensaje* >::const_iterator iter;
	for(iter = this->mensajes.begin(); iter != this->mensajes.end(); ++iter)
	{
		iter->second->~NetworkMensaje();
	}
}

list<NetworkMensaje*> Serializador::leer(int sock) {
	list<NetworkMensaje*> retorno;

//	string buffer;
	int longitud;
	int bLeidos = 0;
//	read(sock, &longitud, 4);
	char buffer[MAX_BUFFER];
//	if (longitud < 450){
//	while (bLeidos < longitud){
	bLeidos = read(sock, &buffer,MAX_BUFFER);
	//ENTREG3EZE armar el buffer con lo que va llegando
//	}
//	}
//	cout << bLeidos << " " << longitud << endl;
	string clave;

	string aux = buffer;

	YAML::Node lineup = YAML::Load(aux);

	YAML::const_iterator it=lineup.begin();

	while(it != lineup.end())
	{


		clave = it->as<string>();
		it++;
//		cout << clave << endl;
		retorno.push_back(this->mensajes.find(clave)->second->deserialize(it));

	}
cout << "sali" << endl;
return retorno;
}

void Serializador::escribir(list<NetworkMensaje*>& lista, int socket) {
	list<NetworkMensaje*>::iterator it = lista.begin();
	YAML::Node * nodo = new YAML::Node() ;
	stringstream envio;

	while(it != lista.end())
	{
		(*it)->serialize(nodo);
		it++;

	}
	 envio << *nodo;
	 const char * str = envio.str().c_str();
	 int len = strlen(envio.str().c_str());
//	 send(socket, &len, sizeof(int), 0);
	 int bytes_sent = send(socket, str, MAX_BUFFER, 0);



}
