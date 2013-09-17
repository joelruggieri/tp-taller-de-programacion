/*
 * TextBox.cpp
 *
 *  Created on: 14/09/2013
 *      Author: ezequiel
 */
#define TAM_BUFFER 36 //definir acorde a lo que puede entrar en el textbox
#include "TextBox.h"
#define BACKSPACE 8
#define TAM_FUENTE 13
TextBox::TextBox(int x, int y, int w, int h, SDL_Texture* imagen) {
this->seleccionado = false ;

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
	TTF_SizeText(this->fuente, this->textoCurrent.c_str(), &(dstTxt.w), NULL);



	this->surfaceTexto = TTF_RenderText_Solid(fuente, this->textoCurrent.c_str(), this->color);
	this->textureTexto = SDL_CreateTextureFromSurface(render, this->surfaceTexto);


	SDL_RenderCopy(render,this->textureTexto, NULL, &dstTxt);




}

void TextBox::agregarCaracter(char caracter) {
	this->texto += caracter ;
	this->textoCurrent	+= caracter;
	if (textoCurrent.size() >= TAM_BUFFER)
	{
		this->textoCurrent.erase(0, 1);	//elimino el primer caracter de esa cadena
	}
	cout << this->texto << endl;
	cout << this->textoCurrent << endl;

}

void TextBox::borrarCaracter() {
	if ((this->texto.size() == 0)||(this->textoCurrent.size() == 0)) return;
	this->texto.erase((this->texto.size()-1), 1);
	this->textoCurrent.erase((this->textoCurrent.size()-1), 1);

	if (this->texto.size() > TAM_BUFFER)
	{

	  int posLetraAgregada = texto.size() - (TAM_BUFFER-1) ;
		char letraAgregada ;
		letraAgregada= this->texto.at(posLetraAgregada);	//creo qe ahi recibo la letra
		 this->textoCurrent = letraAgregada + this->textoCurrent;	//forma hipercavernicola de concatenar

	}
	if (this->texto.size() == TAM_BUFFER ) this->textoCurrent = this->texto ;
	cout << this->texto << endl;
	cout << this->textoCurrent << endl;
}

void TextBox::setearTexto() {
	this->texto = "" ;
	this->textoCurrent = this->texto ;


}

bool TextBox::fueSeleccionado(int x, int y) {
	return (this->x <= x && this->x + this->w > x && this->y <= y && this->y + this->h > y );		//TODO logica de seleccion

}

void TextBox::presionarMouse() {
	if (!seleccionado) seleccionado = true ;
	return this->resetearTexto();//TODO ver como ejecutar el textbox


}

void TextBox::desPresionarMouse() {
//this->seleccionado = false;
}



void TextBox::resetearTexto() {
	this->texto.clear();
	this->textoCurrent.clear();

}

void TextBox::ejecutarTecla(char key) {
	if (this->seleccionado)
	{	if (key == BACKSPACE) return this->borrarCaracter();
		this->agregarCaracter(key);

	}//TODO comprobacion del caracter backspace , en ese caso seria BorrarCaracter();
	//TODO cuando el key es un "enter" tengo que deseleccionarlo
}

void TextBox::clickeoFueraDeHerramienta() {
	this->seleccionado = false;
}
