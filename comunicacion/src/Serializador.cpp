/*
 * Serializador.cpp
 *
 *  Created on: 30/10/2013
 *      Author: ezequiel
 */

#include "Serializador.h"

Serializador::Serializador() {
this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_VIEW_GLOBO), new ViewGloboUpdateMsj(0,0,0)));
this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_MSJ_PLANO), new MensajePlano("")));
this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_VIEW_BOLA), new ViewBolaBolicheUpdateMsj(0,0,0)));
this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_VIEW_PELOTA), new ViewPelotaUpdateMsj(0,0,0)));
this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_VIEW_PLATAFORMA), new ViewPlataformaUpdateMsj(0,0,0,0)));
this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_VIEW_MOTOR), new ViewMotorUpdateMsj(0,0,0)));
this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_VIEW_CINTA), new ViewCintaUpdateMsj(0,0,0,0)));
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
	char buffer[1024];
//	string buffer;
	read(sock, &buffer,1023);
	string clave;
//	cout << buffer << endl;
	string aux;
	aux = buffer;
	YAML::Node lineup = YAML::Load(aux);

	YAML::const_iterator it=lineup.begin();

	while(it != lineup.end())
	{


		clave = it->as<string>();
		it++;
//		cout << clave << endl;
		retorno.push_back(this->mensajes.find(clave)->second->deserialize(it));

	}
//cout << "sali" << endl;
return retorno;
}
