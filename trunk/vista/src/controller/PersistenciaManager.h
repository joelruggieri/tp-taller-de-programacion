/*
 * PersistenciaManager.h
 *
 *  Created on: 14/09/2013
 *      Author: jonathan
 */

#ifndef PERSISTENCIAMANAGER_H_
#define PERSISTENCIAMANAGER_H_
#include <list>
using namespace std;
#include "src/figura/Figura.h"
#include "src/figura/Mapa.h"
#include "src/NivelDAO.h"
#include <string>
using namespace std;

class PersistenciaManager {
private:
	std::string nivelActual;
	NivelDAO * dao;
	Nivel * nivel;
public:
	PersistenciaManager();
	virtual ~PersistenciaManager();
	list<Figura*> & getFiguras();
	void setFiguras(list<Figura*> & figuras);
	void cambiarNivel(int nivel);
	void cambiarImagenFondo(string);
	void persistir();
	string getImagenFondo();
	Nivel * getNivel();
	void liberarNivel();
};

#endif /* PERSISTENCIAMANAGER_H_ */
