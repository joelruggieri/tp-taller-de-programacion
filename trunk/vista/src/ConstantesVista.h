/*
 * ConstantesVista.h
 *
 *  Created on: 09/10/2013
 *      Author: jonathan
 */

namespace CLIENTE {
#ifndef CONSTANTESVISTA_H_
#define CONSTANTESVISTA_H_
/*
 * PARAMETRIZACION GENERAL
 */
#define VELOCIDAD_REFRESCO 40
#define VELOCIDAD_REFRESCO_VISTA 50.0 //HZ


#define TAMANIO_PANTALLA 600
/**
 * FACTORIES VISTAS
 */
#define ANCHO_VISTA_DEFAULT 10


#define ALTO_PANEL_LOG 80
#define ALTO_VISTA_BALANCIN_LOG 4.0 //U logicas
#define ALTO_VISTA_PLATAFORMA_LOG 4.0 //U logicas
#define ALTO_VISTA_CINTA_LOG 8.0 //U logicas
#define ANCHO_ENGRANAJE 13

#define ALTO_VISTA_CINTA_RAMPA_LOG 1.0
#define RADIO_EJE_CINTA_LOG 2.6
#define PATH_VISTA_BALANCIN "resource/balancin.png"
#define PATH_VISTA_CORREA "resource/correa.png"
#define PATH_VISTA_BALANCIN_F "resource/balancin_f.png"
#define PATH_VISTA_TIJERA_ABIERTA "resource/tijeras.png"
#define PATH_VISTA_CARRITO "resource/autito.png"
#define PATH_VISTA_PLATAFORMA_F "resource/plataforma_f.png"
#define PATH_VISTA_PLATAFORMA "resource/plataforma.png"
#define PATH_VISTA_GLOBO "resource/globo.png"
#define PATH_VISTA_AREA "resource/area.png"
#define PATH_VISTA_CARTEL "resource/textbox.png"
#define PATH_VISTA_PELOTA "resource/pelota.png"
#define PATH_VISTA_YUNQUE "resource/yunque.png"
#define PATH_VISTA_BOLA "resource/bolaBoliche.png"
#define PATH_VISTA_CINTA "resource/cinta.png"
#define PATH_VISTA_CINTA_PLATAF "resource/baseCinta.png"
#define PATH_VISTA_CUERDA "resource/cuerda.png"
#define PATH_VISTA_ENGRANAJE "resource/engranaje1.png"
#define PATH_VISTA_MOTOR "resource/mot.png"
#define PATH_VISTA_CLAVO "resource/clavo.png"
#define PATH_VISTA_CLAVO_F "resource/clavo_f.png"
#define PATH_VISTA_GANCHO "resource/arandela.png"
#define PATH_VISTA_POLEA "resource/polea.png"
#define PATH_VISTA_CONTROL "resource/tacho3.png"
#define PATH_VISTA_BOMBA "resource/bomba2.png"
#define PATH_VISTA_TIJERA1 "resource/tijeraN2.png"
#define PATH_VISTA_TIJERA2 "resource/tijeraN.png"
#define PATH_VISTA_RUEDAS "resource/ruedaAuto.png"
#define PATH_EDICION_UNION "resource/seleccionUnion.png"
#define PATH_AGRANDAR_IMG "resource/agrandar.png"
#define PATH_ROTACION_IMG "resource/rotacion.png"
#define PATH_ERROR_IMG "resource/error.jpg"
#define PATH_ZONA_CREACION "resource/fondoHerramientas.jpg"
#define PATH_BOTON_PLAY "resource/play.png"
#define PATH_BOTON_STOP "resource/stop.png"
#define IMG_ERROR "error.jpg"
#define PATH_FONDO "resource/fondoNivel1.jpg"
#define PATH_VISTA_FLECHA_SCROLL "resource/flecha.png"
#define PATH_VISTA_CARRITO_CUERPO "resource/madera.png"
#define LAYER_DEFAULT 1
#define LAYER_UNIONES 2
#define LAYER_ENGRANAJES 2
#define LAYER_CINTA 3
#define LAYER_TACHO 5
#define LAYER_CANVAS_TABLERO 0
#define LAYER_AREA 1
#define LAYER_CANVAS_CREACION 10
#define LAYER_FACTORIES 11
#define LAYER_BORDES 15
#define LAYER_FLECHAS 14
#define LAYER_CANVAS_PLAY 12
#define LAYER_BOTON_PLAY 13
#define LAYER_HIGHLIGHT 50
#define LAYER_CANVAS_RELLENO 12

#define ID_MARCO_ESCENARIO 0
#define ID_CANVAS 1
#define ID_BORDE_CANVAS 2
#define ID_CANVAS_CREAC 3
#define ID_BORDE_CANVAS_CREAC 4
#define ID_BOTON_PLAY_BORDE 6
#define ID_BOTON_PLAY_FONDO 7
#define ID_CANVAS_RELLENO 8
#define ID_BORDE_RELLENO 8
#define ID_SCROLL_ARRIBA 9
#define ID_SCROLL_ABAJO 10
#define ID_AREA 11
#define ID_CARTEL 12

//////////// Constantes de dibujo /////////
#define RADIO_GANCHO 1.0
#define RADIO_POLEA 4.0
#define RADIO_PELOTA 3.0
#define RADIO_BOLA 3.0
#define RADIO_GLOBO 3.5
#define ANCHO_ESLABON_SOGA 1
#define ANCHO_PLATAFORMA 10.0
#define ALTO_PLATAFORMA 2.5
#define ALTO_UNION_ESTATICA 10.0
#define ANCHO_UNION_ESTATICA 10.0
#define RADIO_CORREA_ESTATICA 2.0
#define RADIO_SOGA_ESTATICA 1.0
#define ANCHO_YUNQUE 8.4
#define ALTO_YUNQUE 10.0

#define ANCHO_CARRITO 15.0
#define ALTO_CARRITO 4
#define RADIO_RUEDA_CARRITO 1.5
#define ANCHO_BALANCIN 15.0
#define ALTO_BALANCIN 1.6
#define ANCHO_TIJERA 15.0
#define ALTO_TIJERA 8.0


#define ANCHO_CLAVO 5
#define ALTO_CLAVO 2.5
#define ANCHO_CONTROL 9.0
#define ALTO_CONTROL 9.0
#define ALTO_CINTA 5
#define ANCHO_CINTA 20
#define RADIO_EJE_CINTA 3.0

#define RADIO_ENGRANAJE_CHICO 2.5
#define RADIO_ENGRANAJE 3.5
#define RADIO_ENGRANAJE_GRANDE 5.5
#define RADIO_MOTOR 3.5

//CONSTANTES DE SONIDOS
#define ID_SONIDO_SUBIBAJA 10
#define ID_SONIDO_BOLA 11
#define ID_SONIDO_BOMBA_CONTACTO 12
#define ID_SONIDO_BOMBA_EXPLOSION 13
#define ID_SONIDO_GLOBO 14
#define ID_SONIDO_PELOTA 15
#define ID_SONIDO_SOGA 16
#define ID_SONIDO_YUNKE 17
#define ID_SONIDO_CINTA 18
#define ID_SONIDO_MOTOR 19

#endif /* CONSTANTESVISTA_H_ */
}
