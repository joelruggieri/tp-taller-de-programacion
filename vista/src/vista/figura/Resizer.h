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
	static Resizer* Instance(int x, int y);
	int resizearDistanciaX(int valor);
	int resizearDistanciaY(int valor);
	void setearResizer(int xNuevo, int yNuevo);

	//Resizer();
	//virtual ~Resizer();
protected:
	Resizer(int x, int y);
	Resizer(const Resizer & ) ;
	Resizer &operator= (const Resizer & ) ;


private:
	int xViejo, yViejo, xNuevo, yNuevo ;
	float  relacionX,relacionY;// valores de la pantalla


	static Resizer* pinstance;



};

#endif /* RESIZER_H_ */
