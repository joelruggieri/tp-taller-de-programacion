#include "NetworkMensaje.h"

int NetworkMensaje::getDestinatario() {
	return destinatario;
}

NetworkMensaje::NetworkMensaje(int destinatario) {
	this->destinatario = destinatario;
}


void NetworkMensaje::setDestinatario(int destinatario) {
	this->destinatario = destinatario;
}
