/*
 * FiguraView.h
 *
 *  Created on: 04/09/2013
 *      Author: jonathan
 */

#ifndef FIGURAVIEW_H_
#define FIGURAVIEW_H_
#include "src/figura/Figura.h"
//#include "../../modelo/figura/Figura.h"
#include <iostream>
#include "../View.h"
using namespace std;

class DropManager;
class FiguraView: public View {
private:
	Figura * modelo;
protected:
	virtual void dropTemplate(DropManager*) = 0;
public:
	FiguraView();
	virtual ~FiguraView();
	Figura * getModelo();
	void setModelo(Figura* modelo);
	void drop(DropManager* manager);
	void dibujarse();
};

class CuadradoView: public FiguraView {
private:
	void dropTemplate(DropManager*);
public:
	CuadradoView();
	virtual ~CuadradoView();

};

class TrianguloView: public FiguraView {
private:
	void dropTemplate(DropManager*);
public:
	TrianguloView();
	virtual ~TrianguloView();
};

class CirculoView: public FiguraView {
private:
	void dropTemplate(DropManager*);
public:
	CirculoView();
	virtual ~CirculoView();
};
#endif /* FIGURAVIEW_H_ */
