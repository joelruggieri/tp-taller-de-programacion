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
enum ESTADOS { GANADO, PERDIDO , NOTERMINADO };
class ObjetivoDesdeHasta : public Objetivo {
public:
	ObjetivoDesdeHasta(float xD, float yD, float xH, float yH, float numeroObj);
	virtual ~ObjetivoDesdeHasta();
	void crearFiguras(std::list<Figura*>&);
	void notifyEvent(ObservableModelo* o, Evento_type t);
private:
	float xH,yH;
	int estado ;
};

#endif /* OBJETIVODESDEHASTA_H_ */
