/*
 * ObjetoDAO.h
 *
 *  Created on: 31/08/2013
 *      Author: javier
 */

#ifndef OBJETODAO_H_
#define OBJETODAO_H_

#include "Objeto.h"
#include <list>
#include <string>
#include "src/figura/Circulo.h"
#include "src/figura/Triangulo.h"
#include "src/figura/Cuadrado.h"
#include "src/figura/Figura.h"
#include <yaml-cpp/yaml.h>

class ObjetoDAO {
private:
	bool guardarCirculo(Circulo* circulo);
	bool guardarCuadrado(Cuadrado* cuadrado);
	bool guardarTriangulo(Triangulo* triangulo);

public:
	ObjetoDAO();
	virtual ~ObjetoDAO();
	bool guardar(Figura *objeto);
	std::list<Figura*> obtenerTodos();
};

#endif /* OBJETODAO_H_ */
