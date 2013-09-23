/*
 * FiguraFactory.cpp
 *
 *  Created on: 04/09/2013
 *      Author: jonathan
 */

#include "FiguraFactory.h"
#include "../figura/Cuadrado.h"
#include "../figura/Circulo.h"
#include "../figura/Triangulo.h"
#include "../figura/Rueda.h"
#include "../figura/Globo.h"
#include "../figura/Pelota.h"
#include "../figura/Resorte.h"
#include "../figura/Martillo.h"
#include "../figura/Bloque.h"
#include "../figura/Cohete.h"
#include "../figura/Carrito.h"


FiguraFactory::FiguraFactory(Rotador * rotador) {
	this->rotador = rotador;

}

FiguraFactory::~FiguraFactory() {
	// TODO Auto-generated destructor stub
}

Figura * FiguraFactory::crearCuadrado(float x,float y){
	return new Cuadrado(x,y, rotador,10,10);
}
Figura* FiguraFactory::crearCirculo(float x, float y) {
	return new Circulo(x,y, rotador,4.3);
}

Figura* FiguraFactory::crearTriangulo(float x,float y) {
	return new Triangulo(x,y,rotador,10,10);
}

Figura* FiguraFactory::crearRueda(float x, float y) {
	return new Rueda(x,y, rotador,5);
}

Figura* FiguraFactory::crearGlobo(float x, float y){
	return new Globo(x,y,rotador,5);
}

Figura* FiguraFactory::crearPelota(float x, float y){
	return new Pelota(x,y,rotador,5);
}

Figura* FiguraFactory::crearResorte(float x, float y){
	return new Resorte(x,y,rotador,7,10);
}

Figura* FiguraFactory::crearMartillo(float x, float y){
	return new Martillo(x,y,rotador,10,10);
}

Figura* FiguraFactory::crearBloque(float x, float y){
	return new Bloque(x,y,rotador,9.5,9.5);
}

Figura* FiguraFactory::crearCohete(float x, float y){
	return new Cohete(x,y,rotador,4,5);
}

Figura* FiguraFactory::crearCarrito(float x, float y){
	return new Carrito(x,y,rotador,6,6);
}

Figura* FiguraFactory::crear(Cuadrado* c) {
	return this->crearCuadrado(c->getX(),c->getY());
}

Figura* FiguraFactory::crear(Circulo* c) {
	return this->crearCirculo(c->getX(),c->getY());
}

Figura* FiguraFactory::crear(Triangulo* c) {
	return this->crearTriangulo(c->getX(),c->getY());
}

Figura* FiguraFactory::crear(Rueda* c) {
	return this->crearRueda(c->getX(),c->getY());
}

Figura* FiguraFactory::crear(Globo* c) {
	return this->crearGlobo(c->getX(),c->getY());
}

Figura* FiguraFactory::crear(Pelota* c) {
	return this->crearPelota(c->getX(),c->getY());
}

Figura* FiguraFactory::crear(Resorte* c) {
	return this->crearResorte(c->getX(),c->getY());
}

Figura* FiguraFactory::crear(Martillo* c) {
	return this->crearMartillo(c->getX(),c->getY());
}

Figura* FiguraFactory::crear(Bloque*c) {
	return this->crearBloque(c->getX(),c->getY());
}

Figura* FiguraFactory::crear(Cohete* c) {
	return this->crearCohete(c->getX(),c->getY());
}

Figura* FiguraFactory::crear(Carrito* c) {
	return this->crearCarrito(c->getX(),c->getY());
}
