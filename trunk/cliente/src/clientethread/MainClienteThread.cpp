/*
 * MainClienteThread.cpp
 *
 *  Created on: 01/11/2013
 *      Author: ezequiel
 */

#include "MainClienteThread.h"
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "src/mensajes/MensajePlano.h"
MainClienteThread::MainClienteThread() {
	colaEntrada = new ColaEventos();
	colaSalida = new ColaEventos();
	thread =0;
}

MainClienteThread::~MainClienteThread() {
}

void MainClienteThread::run() {
	int sockfd;
	struct sockaddr_in dest_addr;
	// Guardará la dirección de destino
	sockfd = socket(AF_INET, SOCK_STREAM, 0); // ¡Comprueba errores!
	dest_addr.sin_family = AF_INET;
	// Ordenación de máquina
	dest_addr.sin_port = htons(6006);
	// short, Ordenación de la red
	dest_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(&(dest_addr.sin_zero), '\0', 8); // Poner a cero el resto de la
	// no olvides comprobar los errores de connect()!
	int st =connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(struct sockaddr));
	cout << st << endl;
	Status* status = new Status(90);

	if(thread == 0){
		thread = new IOThread(colaEntrada,colaSalida,status,sockfd);
		thread->run();
	}
	MensajePlano * msj;
	while(true){
		sleep(1);
		msj= new MensajePlano("prueba");
		colaSalida->push(msj);
	}

}
