/*
 * Dibujable.h
 *
 *  Created on: 04/09/2013
 *      Author: ezequiel
 */

#ifndef DIBUJABLE_H_
#define DIBUJABLE_H_
#include "SDL2/SDL_image.h"
#include "SDL2/SDL.h"
#include <iostream>
#include "src/mensajes/viewMensaje/ViewMsj.h"
#include <list>
using namespace std;

class Dibujable{
private:
	int id;
 static int idSequence;
 static void incrementarIdSequence();

public:
	Dibujable();
	virtual ~Dibujable();
	virtual int getLayer();
	int getNext();
	virtual void dibujarse(list<ViewMsj*> & lista) = 0;
	int getId();


};


#endif /* DIBUJABLE_H_ */
