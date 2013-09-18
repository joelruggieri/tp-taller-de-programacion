/*
 * TextBox.cpp
 *
 *  Created on: 14/09/2013
 *      Author: ezequiel
 */
#define TAM_BUFFER 39 //definir acorde a lo que puede entrar en el textbox
#include "TextBox.h"
#define BACKSPACE 8
#define TAM_FUENTE 10
TextBox::TextBox(int x, int y, int w, int h, SDL_Texture* imagen) {
this->seleccionado = false ;
this->shiftIn = false;
TTF_Init();
this->x = x;
this->y = y ;
this->w = w;
this->h = h ;
this->imagen = imagen ;
this->fuente = TTF_OpenFont("resource/Arial Bold.ttf", TAM_FUENTE);
this->texto = "";
this->textoCurrent = texto ;

this->color.a = 50;
this->color.b = 20;
this->color.g = 20;
this->color.r = 200;
this->surfaceTexto = NULL;
this->textureTexto = NULL ;


}

TextBox::~TextBox() {	// TODO Auto-generated destructor stub
}

//Devuelve una copia del string contenido en el textbox
string* TextBox::getTexto(){
	string* aDevolver = new string();
	aDevolver->append(this->texto);
	return aDevolver;
}

void TextBox::dibujarse(SDL_Renderer* render) {
	SDL_Rect dstFondo;
	dstFondo.x = this->x ;
	dstFondo.y =  this ->y;
	dstFondo.h = this->h ;
	dstFondo.w = this->w ;
	SDL_RenderCopy(render,this->imagen, NULL, &dstFondo);
	SDL_Rect dstTxt;
	dstTxt.x = this->x + 5;
	dstTxt.y = this->y ;
	dstTxt.h = this->h - 4 ;
//	dstTxt.w = this->textoCurrent.size() * 8 ;	//TODO
//	TTF_SizeText(this->fuente, this->textoCurrent.c_str(), &(dstTxt.w), NULL);
	TTF_SizeText(this->fuente, this->textoCurrent.c_str(), &(dstTxt.w), NULL);



	this->surfaceTexto = TTF_RenderText_Solid(fuente, this->textoCurrent.c_str(), this->color);
	this->textureTexto = SDL_CreateTextureFromSurface(render, this->surfaceTexto);


	SDL_RenderCopy(render,this->textureTexto, NULL, &dstTxt);




}

void TextBox::agregarCaracter(char caracter) {
	this->texto += caracter ;
	this->textoCurrent	+= caracter;
	int ancho;
	TTF_SizeText(this->fuente, this->textoCurrent.c_str(), &ancho, NULL);
	while (ancho >= this->w - 10)
	{

		this->textoCurrent.erase(0, 1);	//elimino el primer caracter de esa cadena
		TTF_SizeText(this->fuente, this->textoCurrent.c_str(), &ancho, NULL);
	}
	cout << this->texto << endl;
	cout << this->textoCurrent << endl;

}

void TextBox::borrarCaracter() {
	if(this->texto.size()== 0 || this->textoCurrent.size()== 0)
	return this->resetearTexto();
	this->texto.erase((this->texto.size()-1), 1);
	this->textoCurrent.erase((this->textoCurrent.size()-1), 1);
	int ancho;
	TTF_SizeText(this->fuente, this->texto.c_str(), &ancho, NULL);
	if (ancho >= this->w)
	{
		//cout << this->textoCurrent << " " << ancho << endl;
		cout << "entro" << endl ;
	  int posLetraAgregada = texto.size() - textoCurrent.size() - 1;
		char letraAgregada ;
		letraAgregada= this->texto.at(posLetraAgregada);	//creo qe ahi recibo la letra
		 this->textoCurrent = letraAgregada + this->textoCurrent;
//		 TTF_SizeText(this->fuente, this->textoCurrent.c_str(), &ancho, NULL);//forma hipercavernicola de concatenar
	}
	else
		textoCurrent = texto;

}

void TextBox::setearTexto() {
	this->texto = "" ;
	this->textoCurrent = this->texto ;


}

bool TextBox::fueSeleccionado(int x, int y) {
	return (this->x <= x && this->x + this->w > x && this->y <= y && this->y + this->h > y );		//TODO logica de seleccion

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
	if (this->seleccionado){
		if (shiftIn)
		{
			//logica de signos
			switch (key)
			{
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
			}
		}
		if (key == BACKSPACE) return this->borrarCaracter();
		if (key >= 65 && key <= 90) {key = key +32;
		return this->agregarCaracter(key);}
		if (key == 160)
			{this->shiftIn = true;
				return;}
		if (key == 12)
			{this->shiftIn = false;
				return;}
		return this->agregarCaracter(key);



	}
	//TODO cuando el key es un "enter" tengo que deseleccionarlo
}

void TextBox::clickeoFueraDeHerramienta() {
	this->seleccionado = false;
}
