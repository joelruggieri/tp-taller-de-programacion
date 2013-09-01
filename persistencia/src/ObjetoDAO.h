/*
 * ObjetoDAO.h
 *
 *  Created on: 31/08/2013
 *      Author: javier
 */

#ifndef OBJETODAO_H_
#define OBJETODAO_H_

#include "Objeto.h"

class ObjetoDAO {
public:
	ObjetoDAO();
	virtual ~ObjetoDAO();
	bool guardar(Objeto *objeto);
};

#endif /* OBJETODAO_H_ */
