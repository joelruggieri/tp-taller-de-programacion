/*
 * ObjetivoAccionar.h
 *
 *  Created on: 21/11/2013
 *      Author: ezequiel
 */

#ifndef OBJETIVOACCIONARJUEGO_H_
#define OBJETIVOACCIONARJUEGO_H_
#include "ObjetivoJuego.h"
#include "src/figura/Figura.h"
#include "src/Objetivos/ObjetivoDesdeHasta.h"
class ObjetivoAccionarJuego : public ObjetivoJuego{
public:
	ObjetivoAccionarJuego(bool esBomba);
	virtual ~ObjetivoAccionarJuego();
	void crearFiguras(std::list<Figura*>&);
	void notifyEvent(ObservableModelo* o, Evento_type t);
	void setConfig(Objetivo &);
	string getDescripcion();
private:
	typedef ObjetivoJuego super;
	bool esBomba;
};

#endif /* OBJETIVOACCIONAR_H_ */
