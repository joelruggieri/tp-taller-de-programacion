/*
 * ObjetivoDesdeHastaJuego.h
 *
 *  Created on: 21/11/2013
 *      Author: ezequiel
 */

#ifndef OBJETIVODESDEHASTAJUEGO_H_
#define OBJETIVODESDEHASTAJUEGO_H_
#include "ObjetivoJuego.h"
#include "src/figura/Figura.h"
#include "src/Objetivos/ObjetivoDesdeHasta.h"
enum ESTADOS { GANADO, PERDIDO , NOTERMINADO };
class ObjetivoDesdeHastaJuego : public ObjetivoJuego {
public:
	ObjetivoDesdeHastaJuego();
	virtual ~ObjetivoDesdeHastaJuego();
	void crearFiguras(std::list<Figura*>&);
	void notifyEvent(ObservableModelo* o, Evento_type t);
	void setConfig(Objetivo &);
private:
	float xH,yH;
	typedef ObjetivoJuego super;
};

#endif /* OBJETIVODESDEHASTAJUEGO_H_ */
