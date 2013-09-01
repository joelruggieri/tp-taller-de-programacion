/*
 * prueba.cpp
 *
 *  Created on: 31/08/2013
 *      Author: javier
 */

#include "Objeto.h"
#include "ObjetoDAO.h"
#include <list>
#include <iostream>

int main(int argc, char **argv){
	Objeto *objeto1 = new Objeto(3.5, 6.5);
	Objeto *objeto2 = new Objeto(2.5, 2.5);
	Objeto *objeto3 = new Objeto(1.1, 2.5);
	ObjetoDAO *dao = new ObjetoDAO();
	dao->guardar(objeto1);
	dao->guardar(objeto2);
	dao->guardar(objeto3);

	std::list<Objeto*> objetos = dao->obtenerTodos();
	std::list<Objeto*>::iterator iter;
	for (iter = objetos.begin(); iter != objetos.end(); ++iter){
		Objeto *objeto = *iter;
		std::cout << objeto->getPosX() << ", " << objeto->getPosY() << std::endl;
	}

	delete objeto1;
	delete objeto2;
	delete objeto3;
	delete dao;

	for (iter = objetos.begin(); iter != objetos.end(); ++iter){
		Objeto *objeto = *iter;
		delete objeto;
	}

	return 0;
}


