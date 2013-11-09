/*
 * EditorNivel.h
 *
 *  Created on: 03/10/2013
 *      Author: jonathan
 */

#ifndef EDITORNIVEL_H_
#define EDITORNIVEL_H_
#include "SDL2/SDL.h"
#include "src/mensajes/viewMensaje/ViewMsj.h"
#include <list>
using namespace std;
class EditorNivel {
private:
	bool shift, ctrl;
protected:
	int numeroJugadorDuenio;
public:
	EditorNivel() {
		shift = false;
		ctrl = false;
		numeroJugadorDuenio = -1;
	}
	virtual ~EditorNivel() {};
	virtual void clickDown(float x, float y) = 0;
	virtual void clickUp(float x, float y) = 0;
	virtual void rightClickUp(float x, float y) = 0;
	virtual void rightClickDown(float x, float y) = 0;
	virtual bool isEnd() = 0;
	virtual void dibujarEdicion(list<ViewMsj*> &) = 0;
	virtual void mouseMotion(float x, float y) = 0;
	bool isCtrl() const;
	void setCtrl(bool ctrl);
	bool isShift() const;
	void setShift(bool shift);
	virtual EditorNivel * clone()=0;
		void setNumeroJugador(int numero){
		this->numeroJugadorDuenio = numero;
	}
};

inline bool EditorNivel::isCtrl() const {
	return ctrl;
}

inline void EditorNivel::setCtrl(bool ctrl) {
	this->ctrl = ctrl;
}

inline bool EditorNivel::isShift() const {
	return shift;
}

inline void EditorNivel::setShift(bool shift) {
	this->shift = shift;
}

#endif /* EDITORNIVEL_H_ */
