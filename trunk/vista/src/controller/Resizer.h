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
using namespace std;

class Resizer {
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
	int getAltoPantalla();
	void addResizeable(Resizeable* resizeable);
	void quitarResizeable(Resizeable* resizeable);
	void resizearResizeables(int xNuevo, int yNuevo);
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

#endif /* RESIZER_H_ */
