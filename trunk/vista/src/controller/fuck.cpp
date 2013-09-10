////============================================================================
//// Name        : fuck.cpp
//// Author      :
//// Version     :
//// Copyright   : Your copyright notice
//// Description : Hello World in C++, Ansi-style
////============================================================================
//
//#include <iostream>
//#include "SDL2/SDL.h"
//#include "SDL2/SDL_image.h"
//#include "SDL2/SDL_ttf.h"
//#include "Dibujable.h"
//#include "BotonAgregar.h"
//#include "Background.h"
//#include "Canvas.h"
//#include "Dragueable.h"
//
//#include "TextBox.h"
//
//using namespace std;
//
//SDL_Texture* cargarTexture (const string &file, SDL_Renderer* ren){
//	SDL_Texture* texture = IMG_LoadTexture(ren, file.c_str() );
//	if (texture == NULL) cout << "IMG_Load error: " << IMG_GetError() <<endl;
//
//	return texture;
//}
//
//int main() {
//	int tamVentanaX, tamVentanaY;
//	tamVentanaX = 400;
//	tamVentanaY = 400;
//	SDL_Window *ventana = NULL ;
//	int draggin = false;
//
//	SDL_Init(SDL_INIT_VIDEO);
//	ventana = SDL_CreateWindow("Hola mundo", 400,400,400,400,SDL_WINDOW_RESIZABLE);
//
//
//
//	//// Eventos ////
//
//	SDL_Event evento;
//
//	///// Render ////
//
//	SDL_Renderer* render = SDL_CreateRenderer(ventana,-1, SDL_RENDERER_ACCELERATED);
//
//	////// Texturas ////////////
//
//	SDL_Texture* botonTexture = cargarTexture("pelota.PNG", render);
//	SDL_Texture* canvasTexture = cargarTexture("Fondo4.jpg", render);
//	SDL_Texture* fondoTexture = cargarTexture("Background.jpg", render);
//	SDL_Texture* textBoxTexture = cargarTexture("textbox.jpg", render);
//	SDL_Texture* pelotaTexture = cargarTexture("pelota.PNG", render);
//
//
//	///// Declaracion de objetos /////
//
//
//	BotonAgregar *boton = new BotonAgregar(250,350,25,25,botonTexture,render);
//	Background *canvas = new Background(0,0, 400,400,fondoTexture,render);
//	Canvas* canvas = new Canvas(0,0,300,300, canvasTexture, render);
//	TextBox* textBox = new TextBox(15, 345,50,233, textBoxTexture, render);
//	Dragueable* pelota = new Dragueable(50,50,50,50, pelotaTexture, render);
//
//
//
//	//// Ciclo de juego //////
//
//	bool terminar = 0;
//	int x,y ;
//	int nuevaPosX, nuevaPosY;
//	int tamNuevoX, tamNuevoY;
//	x = y = 0;
//	while (!terminar)
//	{
//
//
//		SDL_PollEvent(&evento);
//		switch(evento.type)
//		{
//		case SDL_QUIT:
//		terminar = true;
//
//		break;
//        case SDL_MOUSEBUTTONDOWN:
//
//
//        	if(SDL_GetMouseState(&x,&y) &SDL_BUTTON(1))
//        	{
//        	if (boton->FueSeleccionado(x,y))	//los seleccionables actuan
//        	{
//        		boton->ModificarFondo(canvas, "Fondo2.jpg");
//        	}
//        	}
//        	break;
//
//        case SDL_WINDOWEVENT:
//        {
//        		switch (evento.window.event)
//        		{
//
//        		case SDL_WINDOWEVENT_RESIZED:
//        			cout << "Hubo un resize" << endl;
//        			SDL_GetWindowSize(ventana,&tamNuevoX,&tamNuevoY);
//
//        			canvas->Resizear(tamNuevoX,  tamNuevoY);
//        			canvas->Resizear(tamNuevoX - tamVentanaX, tamNuevoY - tamVentanaY);
//        			boton->Resizear(tamNuevoX - tamVentanaX, tamNuevoY - tamVentanaY);
//        			textBox->Resizear(tamNuevoX - tamVentanaX, tamNuevoY - tamVentanaY);
//        			tamVentanaX = tamNuevoX ;
//        			tamVentanaY = tamNuevoY;
//        			//Resizeables tienen que resizear
//        			break;
//        		}
//        		break;
//        }
//
//
//		}
//
//
//		if(SDL_GetMouseState(&nuevaPosX,&nuevaPosY) &SDL_BUTTON(1))
//
//
//		{
//
//
//			if (pelota->FueSeleccionado(x,y))
//			{if(!draggin){
//								x = nuevaPosX;
//								y = nuevaPosY;
//			}
//			draggin = true;
//			     pelota->Draguear(x - nuevaPosX, y - nuevaPosY);
//					x = nuevaPosX;
//					y = nuevaPosY;
//			}
//
//			//cout << x << " " << y << endl;
//
//		}
//		else draggin = false;
//
//
//
//
//			SDL_RenderClear(render);
//			canvas->Dibujarse();
//			canvas->Dibujarse();
//			boton->Dibujarse();
//			textBox->Dibujarse();
//			pelota->Dibujarse();
//			SDL_RenderPresent(render);
//
//
//		}
//
//	//// Destructores /////
//
//	SDL_DestroyRenderer(render);
//	SDL_DestroyWindow(ventana);
//	IMG_Quit();
//	SDL_Quit();
//	return 0;
//}
