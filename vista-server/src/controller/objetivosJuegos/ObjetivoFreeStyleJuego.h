/*
 * ObjetivoFreeStyleJuego.h
 *
 *  Created on: 26/11/2013
 *      Author: ezequiel
 */

#ifndef OBJETIVOFREESTYLEJUEGO_H_
#define OBJETIVOFREESTYLEJUEGO_H_
#include "ObjetivoJuego.h"
class ObjetivoFreeStyleJuego : public ObjetivoJuego {
public:
	ObjetivoFreeStyleJuego();
	virtual ~ObjetivoFreeStyleJuego();
	string getDescripcion() ;
	void crearFiguras(std::list<Figura*>&);
	void notifyEvent(ObservableModelo* o, Evento_type t);
};

#endif /* OBJETIVOFREESTYLEJUEGO_H_ */
