/*
 * Resizer.h
 *
 *  Created on: 08/09/2013
 *      Author: ezequiel
 */

#ifndef RESIZER_H_
#define RESIZER_H_
#include <list>
#include "../vista/Resizeable.h"
#include "../modelo/Transformacion.h"
using namespace std;
namespace CLIENTE {
class Resizer {
private:
	Transformacion transf;
public:
	static Resizer* Instance(int x, int y, float xLogico, float yLogico);
	static Resizer* Instance();
	int resizearDistanciaX(int valor);
	int resizearDistanciaY(int valor);
	void setearResizer(int xNuevo, int yNuevo);
	int resizearDistanciaLogicaX(float valor);
	int resizearDistanciaLogicaY(float valor);
	float resizearDistanciaPixelX(int valor);
	float resizearDistanciaPixelY(int valor);

	float resizearPosicionPixelY(int valor);
	int resizearPosicionLogicaY(float valor);
	int resizearPosicionY(int valor);
	int getAltoPantalla();
	void addResizeable(Resizeable* resizeable);
	void quitarResizeable(Resizeable* resizeable);
	void resizearResizeables();


	//METODOS MAS FACILES DE USAR.
	void adaptarPosicionLogica(float x, float y, int & xNuevo, int & yNuevo);
	void adaptarDimensionLogica(float w, float h, int & wNuevo, int & hNuevo);

	void adaptarPosicionPixel(int x, int y, float & xNuevo, float & yNuevo);
	void adaptarDimensionPixel(int w, int h, float & wNuevo, float & hNuevo);


	float getRelacionX();
	float getRelacionY();
	Transformacion & getTransformacionToModelo();
	//Resizer();
	//virtual ~Resizer();
protected:
	Resizer(int x, int y,float xLogico, float yLogico);
	Resizer(const Resizer & ) ;
	Resizer &operator= (const Resizer & ) ;


private:
	int xViejo, yViejo, xNuevo, yNuevo ;
	float  relacionX,relacionY, xLogico, yLogico, relacionXLogica, relacionYLogica;// valores de la pantalla
	list<Resizeable* > resizeables ;

	static Resizer* pinstance;

};

}

#endif /* RESIZER_H_ */
