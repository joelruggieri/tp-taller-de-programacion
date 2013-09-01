/*
 * prueba.cpp
 *
 *  Created on: 31/08/2013
 *      Author: javier
 */

#include "Objeto.h"
#include "ObjetoDAO.h"

int main(int argc, char **argv){
	Objeto *objeto1 = new Objeto(3.5, 2.5);
	ObjetoDAO *dao = new ObjetoDAO();
	dao->guardar(objeto1);
	return 0;
}


