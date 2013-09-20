/*
 * Herramientas.h
 *
 *  Created on: 12/09/2013
 *      Author: ezequiel
 */

#ifndef HERRAMIENTAS_H_
#define HERRAMIENTAS_H_
#include "Dibujable.h"
#include "View.h"
class Herramientas :  public View {
public:
	Herramientas(int x, int y , int w, int h):View(x,y,w,h){

	}



	virtual void dibujarse(SDL_Renderer *) = 0;
	virtual bool fueSeleccionado(int x, int y) = 0;
	virtual void presionarMouse() = 0 ;
	virtual void desPresionarMouse() = 0;
	virtual void ejecutarTecla(char key) = 0;
	virtual void clickeoFueraDeHerramienta() = 0;
	virtual void desEjecutarTecla() = 0 ;
	virtual void resizear() = 0;


};
//TODO refactorizacion: de herramientas que hereden ckickeables y tecleables
// los primeros que tengan presionar, desperecionarmouse y los segundos ejecutar tecla
//y cliqueoFueraDeHerramientas , herramientas que tenga solo dibujarse
#endif /* HERRAMIENTAS_H_ */
