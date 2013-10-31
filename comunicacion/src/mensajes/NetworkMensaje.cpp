#include "NetworkMensaje.h"

int NetworkMensaje::getDestinatario() {
	return destinatario;
}

NetworkMensaje::NetworkMensaje() {
	destinatario = -1;
}


void NetworkMensaje::setDestinatario(int destinatario) {
	this->destinatario = destinatario;
}

NetworkMensaje::~NetworkMensaje() {
}

string NetworkMensaje::serialize() {
	return NULL;
}
