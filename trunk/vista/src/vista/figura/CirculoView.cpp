/*
 * CirculoView.cpp
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#include "CirculoView.h"
#include "../../controller/DropController.h"

void CirculoView::dropTemplate() {
	controller->dropNuevaFigura(this);
}

CirculoView::CirculoView(int x, int y, int w, int h, SDL_Texture * textura, DropController * controller):FiguraView(x, y, w, h,textura, controller) {

}

CirculoView::~CirculoView() {

}

EditorNivel* CirculoView::getEditor() {
	//TODO ESTA CLASE NO DEBERÍA LLAMARSE, TIENE QUE DEVOLVER UN EDITOR VALIDO.
	return 0;
}
