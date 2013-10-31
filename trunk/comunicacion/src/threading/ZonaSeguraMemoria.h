/*
 * ZonaSeguraMemoria.h
 *
 *  Created on: 31/10/2013
 *      Author: jonathan
 */

#ifndef ZONASEGURAMEMORIA_H_
#define ZONASEGURAMEMORIA_H_

class ZonaSeguraMemoria {
private:
	void *(*cleaner) (void *);
	void * liberable;
	void * params;
public:
	ZonaSeguraMemoria(void *(*cleaner) (void *), void * paramsFunc);
	virtual ~ZonaSeguraMemoria();
	void cancel();
	void * getParams();
	void setDatosLiberables(void * liberables);
};

#endif /* ZONASEGURAMEMORIA_H_ */
