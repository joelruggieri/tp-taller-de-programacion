/*
 * Resizer.h
 *
 *  Created on: 08/09/2013
 *      Author: ezequiel
 */

#ifndef RESIZER_H_
#define RESIZER_H_

class Resizer {
public:
	static Resizer* Instance(int x, int y, float xLogico, float yLogico);
	static Resizer* Instance();
	int resizearDistanciaX(int valor);
	int resizearDistanciaY(int valor);
	void setearResizer(int xNuevo, int yNuevo);
	int resizearDistanciaLogicaX(int valor);
	int resizearDistanciaLogicaY(int valor);
	//Resizer();
	//virtual ~Resizer();
protected:
	Resizer(int x, int y,float xLogico, float yLogico);
	Resizer(const Resizer & ) ;
	Resizer &operator= (const Resizer & ) ;


private:
	int xViejo, yViejo, xNuevo, yNuevo ;
	float  relacionX,relacionY, xLogico, yLogico, relacionXLogica, relacionYLogica;// valores de la pantalla


	static Resizer* pinstance;



};

#endif /* RESIZER_H_ */
