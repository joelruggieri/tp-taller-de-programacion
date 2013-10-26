/*
 * TextBox.cpp
 *
 *  Created on: 14/09/2013
 *      Author: ezequiel
 */
 //definir acorde a lo que puede entrar en el textbox
#include "TextBox.h"



//TextBox::TextBox(int x, int y, int w, int h, SDL_Texture* imagen) {
//this->seleccionado = false ;
//this->shiftIn = false;
//TTF_Init();
//this->x = x;
//this->y = y ;
//this->w = w;
//this->h = h ;
//this->imagen = imagen ;
//this->fuente = TTF_OpenFont("resource/Arial Bold.ttf", TAM_FUENTE);
//this->texto = "";
//this->textoCurrent = texto ;
//
//this->color.a = 50;
//this->color.b = 20;
//this->color.g = 20;
//this->color.r = 200;
//this->surfaceTexto = NULL;
//this->textureTexto = NULL ;
//
//
//}

TextBox::~TextBox() {	// TODO Auto-generated destructor stub
}

void TextBox::desEjecutarTecla() {
	this->shiftIn = false ;
}

void TextBox::resizear() {
	this->setYc(Resizer::Instance()->resizearDistanciaY(this->getYCentro()));
//	this->setXc(Resizer::Instance()->resizearDistanciaX(this->getXCentro()));
//	this->setW(Resizer::Instance()->resizearDistanciaX(this->getW()));
//	this->setH(Resizer::Instance()->resizearDistanciaY(this->getH()));
}

//Devuelve una copia del string contenido en el textbox
string* TextBox::getTexto(){
	string* aDevolver = new string();
	aDevolver->append(this->texto);
	return aDevolver;
}

void TextBox::dibujarse(SDL_Renderer* render) {
	SDL_Rect dstFondo;
	dstFondo.x = this->getX() ;
	dstFondo.y =  this->getY();
	dstFondo.h = this->getH();
	dstFondo.w = this->getW() ;
	SDL_RenderCopy(render,this->imagen, NULL, &dstFondo);
	SDL_Rect dstTxt;
	dstTxt.x = this->getX()+7;
	dstTxt.y = this->getY() ;
	dstTxt.h = this->getH() - 4 ;
	TTF_SizeText(this->fuente, this->textoCurrent.c_str(), &(dstTxt.w), NULL);



	this->surfaceTexto = TTF_RenderText_Solid(fuente, this->textoCurrent.c_str(), this->color);
	this->textureTexto = SDL_CreateTextureFromSurface(render, this->surfaceTexto);


	SDL_RenderCopy(render,this->textureTexto, NULL, &dstTxt);
	SDL_FreeSurface(this->surfaceTexto);
	SDL_DestroyTexture(this->textureTexto);


}

void TextBox::agregarCaracter(char caracter) {
	this->texto += caracter ;
	this->textoCurrent	+= caracter;
	int ancho;
	TTF_SizeText(this->fuente, this->textoCurrent.c_str(), &ancho, NULL);
	while (ancho >= this->getW() - 10)
	{

		this->textoCurrent.erase(0, 1);	//elimino el primer caracter de esa cadena
		TTF_SizeText(this->fuente, this->textoCurrent.c_str(), &ancho, NULL);
	}
//	cout << this->texto << endl;
//	cout << this->textoCurrent << endl;

}

void TextBox::borrarCaracter() {
	if(this->texto.size()== 0 || this->textoCurrent.size()== 0)
	return this->resetearTexto();
	this->texto.erase((this->texto.size()-1), 1);
	this->textoCurrent.erase((this->textoCurrent.size()-1), 1);
	int ancho;

//	int posLetraAgregada;
	char letraAgregada ;
	if (texto.size() > textoCurrent.size()){
//	posLetraAgregada = texto.size() - textoCurrent.size();
	letraAgregada= this->texto.at(texto.size() - textoCurrent.size() - 1);	//creo qe ahi recibo la letra
	this->textoCurrent = letraAgregada + this->textoCurrent;
	TTF_SizeText(this->fuente, this->textoCurrent.c_str(), &ancho, NULL);
	while (ancho >= this->getW() - 10)
	{
		this->textoCurrent.erase(0, 1);
//		if (texto.size() > textoCurrent.size())
//		this->textoCurrent = this->texto.at(texto.size() - textoCurrent.size()) + this->textoCurrent;
		TTF_SizeText(this->fuente, this->textoCurrent.c_str(), &ancho, NULL);
//		if (ancho <= this->w - 10) this->textoCurrent = this->texto.at(texto.size() - textoCurrent.size()) + this->textoCurrent;
//		TTF_SizeText(this->fuente, this->textoCurrent.c_str(), &ancho, NULL);
	}
	}
	TTF_SizeText(this->fuente, this->texto.c_str(), &ancho, NULL);
	if (ancho <= this->getW() - 10) textoCurrent= texto ;






}

void TextBox::setearTexto() {
	this->texto = "" ;
	this->textoCurrent = this->texto ;


}

bool TextBox::fueSeleccionado(int x, int y) {
	return (this->getX() <= x && getX() + this->getW() > x && this->getY() <= y && this->getY() + this->getH() > y );		//TODO logica de seleccion

}

void TextBox::presionarMouse() {
	if (!this->seleccionado)
		{this->seleccionado = true;
	 this->resetearTexto();
		}
	return;

}

void TextBox::desPresionarMouse() {
//this->seleccionado = false;
}



void TextBox::resetearTexto() {
	this->texto.clear();
	this->textoCurrent.clear();

}

void TextBox::ejecutarTecla(char key) {
	if ((key >= 32 && key <=64) || (key >= 97 && key <= 125)  || (key == SHIFT) || (key == BACKSPACE) || key == MAYUS)
{
	if (this->seleccionado){
		if (shiftIn)
		{
			//logica de signos
			switch (key)
			{

			case 51:
				return this->agregarCaracter('#');
				break;
			case 50:
				return this->agregarCaracter('@');
				break;
			case 49:
				return this->agregarCaracter('!');
				break;
			case 52:
				return this->agregarCaracter('$');
				break;
			case 53:
				return this->agregarCaracter('%');
				break;
			case 54:
				return this->agregarCaracter('&');
				break;
			case 55:
				return this->agregarCaracter('/');
				break;
			case 56:
				return this->agregarCaracter('(');
				break;
			case 57:
				return this->agregarCaracter(')');
				break;
			case 46:
				return this->agregarCaracter(':');
				break;
			case 44:
				return this->agregarCaracter(';');
				break;
			case 45:
				return this->agregarCaracter('_');
				break;
			case 60:
				return this->agregarCaracter('>');
				break;
			}
		}
		if (shiftIn || mayusIn ){
			if (key >= 97 && key <= 122) {key = key - 32;
			return this->agregarCaracter(key);}}


		if (key == BACKSPACE) return this->borrarCaracter();

		if (key == SHIFT)
		{
			if (!this->shiftIn)
			{
				this->shiftIn = true ;

			}
			else {
				this->shiftIn = false;
			}
			return ;
		}
		if (key == MAYUS)
		{
//			cout << "hay un MAYUS" << endl ;
			if (!this->mayusIn)
			{
				this->mayusIn = true ;

			}
			else {
				this->mayusIn = false;
			}
			return ;
		}
		return this->agregarCaracter(key);



	}
	}
	}


void TextBox::clickeoFueraDeHerramienta() {
	this->seleccionado = false;
}

void TextBox::dibujarse(SDL_Renderer* render, SDL_Rect &dest) {

}
