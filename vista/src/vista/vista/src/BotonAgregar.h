/*
 * BotonAgregar.h
 *
 *  Created on: 31/08/2013
 *      Author: ezequiel
 */

#ifndef BOTONAGREGAR_H_
#define BOTONAGREGAR_H_
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "Canvas.h"
#include <iostream>
#include "Dibujable.h"
#include "Resizeable.h"

namespace std {

class BotonAgregar : public Dibujable, public Resizeable {
	/*int positionX, positionY, ancho, alto;
	SDL_Texture* imagenBoton;
	SDL_Renderer* renderer;*/

public:
	BotonAgregar(int x, int y, SDL_Texture* imagen, SDL_Renderer* renderer, int ancho, int alto);
	virtual ~BotonAgregar();
//	void Dibujarse();
	bool FueSeleccionado(int x, int y);
	void MoverPelota(int movimiento);
	int ModificarFondo(Canvas* fondo,char* rutaNueva);
	void Resizear(int x, int y);





};

} /* namespace std */
#endif /* BOTONAGREGAR_H_ */
