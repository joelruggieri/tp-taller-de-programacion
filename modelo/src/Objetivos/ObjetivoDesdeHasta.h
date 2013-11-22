/*
 * ObjetivoDesdeHasta.h
 *
 *  Created on: 21/11/2013
 *      Author: ezequiel
 */

#ifndef OBJETIVODESDEHASTA_H_
#define OBJETIVODESDEHASTA_H_
#include "Objetivo.h"
#include "../figura/Figura.h"
class ObjetivoDesdeHasta : public Objetivo {
public:
	ObjetivoDesdeHasta(float xD, float yD, float xH, float yH, float numeroObj);
	virtual ~ObjetivoDesdeHasta();
	void crearFiguras(std::list<Figura*>&);
private:
	float xH,yH;
};

#endif /* OBJETIVODESDEHASTA_H_ */
