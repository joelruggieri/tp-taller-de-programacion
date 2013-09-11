/*
 * ObjetoDAO.h
 *
 *  Created on: 31/08/2013
 *      Author: javier
 */

#ifndef OBJETODAO_H_
#define OBJETODAO_H_

#include <list>
#include <string>
#include "src/figura/Circulo.h"
#include "src/figura/Triangulo.h"
#include "src/figura/Cuadrado.h"
#include "src/figura/Figura.h"
#include "AdministradorDeArchivos.h"

class ObjetoDAO {
public:
	ObjetoDAO();
	ObjetoDAO(std::string nombre_archivo);
	virtual ~ObjetoDAO();
	bool guardar(Circulo *objeto);
	bool guardar(Cuadrado *objeto);
	bool guardar(Triangulo *objeto);
	std::list<Figura*> obtenerTodos();
private:
	AdministradorDeArchivos* archivo;
};

#endif /* OBJETODAO_H_ */
