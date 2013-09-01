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

class ObjetoDAO {
public:
	ObjetoDAO();
	virtual ~ObjetoDAO();
	bool guardar(Objeto *objeto);
	std::list<Objeto*> obtenerTodos();
};

#endif /* OBJETODAO_H_ */
