//============================================================================
// Name        : ClientePruebaMensajes.cpp
// Author      : Ezequiel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include "src/Serializador.h"
using namespace std;
#include <iostream>
#include <list>
#include "src/mensajes/MensajePlano.h"
#include "src/mensajes/ViewGloboUpdateMsj.h"
#include "src/mensajes/ViewBolaBolicheUpdateMsj.h"
#define h_addr h_addr_list[0]

void error(const char *msg)
{
    perror(msg);

}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

//    char buffer[1024];

    if (argc < 2) {
        fprintf(stderr,"usage %s hostname\n", argv[0]);
        return 1;
    }
    portno = 6007;
    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("ERROR creando socket.\n");
        return 1;
    }
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no existe el host.\n");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    //// conexion al server ///
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
         perror("ERROR de conexion.\n");
         exit(1);
    }

//    /* Leo la respuesta del server. */
//    bzero(buffer,1024);
//    n = read(sockfd,buffer,1023);
    Serializador* unS = new Serializador();
    list <NetworkMensaje*> lista ;

    lista = unS->leer(sockfd);
//    ViewGloboUpdateMsj* mje = (ViewGloboUpdateMsj*)lista.front();
//    lista.pop_front();
    while(!lista.empty()){

    MensajePlano* mje2 = (MensajePlano*)lista.front();
    lista.pop_front();
//     ViewBolaBolicheUpdateMsj* mje3 = (ViewBolaBolicheUpdateMsj*)lista.front();
//     lista.pop_front();
//      ViewPelotaUpdateMsj* mje4 = (ViewPelotaUpdateMsj*)lista.front();
//      lista.pop_front();
//         ViewPlataformaUpdateMsj* mje5 = (ViewPlataformaUpdateMsj*)lista.front();
//         lista.pop_front();
//            ViewMotorUpdateMsj* mje6 = (ViewMotorUpdateMsj*)lista.front();
//            lista.pop_front();
//            ViewCintaUpdateMsj* mje7 = (ViewCintaUpdateMsj*)lista.front();
//            lista.pop_front();
//             ViewEngranajeUpdateMsj* mje8 = (ViewEngranajeUpdateMsj*)lista.front();
//             lista.pop_front();
//             ViewBalancinUpdateMsj* mje9 = (ViewBalancinUpdateMsj*)lista.front();
//             lista.pop_front();
//              ViewSogaUpdateMje* mje10 = (ViewSogaUpdateMje*)lista.front();


//         mje2->getMensaje() ;
    cout << mje2->getMensaje() << endl;
    lista = unS->leer(sockfd);
    }
//    mje3->getMensaje();
//    mje4->getMensaje();
//    mje5->getMensaje();
//    mje6->getMensaje();
//    mje7->getMensaje();
//    mje8->getMensaje();
//    mje9->getMensaje();
//    mje10->getMensaje();



//    if (n < 0)
//    {
//         perror("ERROR leyendo del socket.\n");
//         exit(1);
//    }
//
//    while (strcmp(buffer,"fin\n") != 0)
//    	{
//
//
//       		bzero(buffer,1024);
//        		read(sockfd, buffer , 1020 );
//        		cout << buffer << endl;
//        		bzero(buffer,1024);
//        		fgets(buffer,1023,stdin);
//        		write(sockfd, buffer, 1020);
//    	}
//    	cout << "fin conversacion cliente" << endl;
    return 0;
}
