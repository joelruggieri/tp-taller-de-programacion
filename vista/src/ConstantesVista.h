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
#define VELOCIDAD_REFRESCO 30
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
#define PATH_VISTA_PLATAFORMA_F "resource/plataforma_f.png"
#define PATH_VISTA_PLATAFORMA "resource/plataforma.png"
#define PATH_VISTA_GLOBO "resource/globo.png"
#define PATH_VISTA_PELOTA "resource/pelota.png"
#define PATH_VISTA_BOLA "resource/bolaBoliche.png"
#define PATH_VISTA_CINTA "resource/cinta.png"
#define PATH_VISTA_CINTA_PLATAF "resource/baseCinta.png"
#define PATH_VISTA_CUERDA "resource/cuerda.png"
#define PATH_VISTA_ENGRANAJE "resource/engranaje1.png"
#define PATH_VISTA_MOTOR "resource/motor2.png"
#define PATH_EDICION_UNION "resource/seleccionUnion.png"
#define PATH_AGRANDAR_IMG "resource/agrandar.png"
#define PATH_ROTACION_IMG "resource/rotacion.png"
#define PATH_ERROR_IMG "resource/error.jpg"
#define PATH_ZONA_CREACION "resource/fondoHerramientas.jpg"
#define PATH_BOTON_PLAY "resource/play.png"
#define PATH_BOTON_STOP "resource/stop.png"
#define IMG_ERROR "error.jpg"
#define PATH_FONDO "resource/fondo.jpg"
#define PATH_VISTA_FLECHA_SCROLL "resource/flecha.png"

#define LAYER_DEFAULT 0
#define LAYER_UNIONES 1
#define LAYER_ENGRANAJES 2
#define LAYER_CINTA 3

#define ID_MARCO_ESCENARIO 0
#define ID_CANVAS 1
#define ID_BORDE_CANVAS 2
#define ID_CANVAS_CREAC 3
#define ID_BORDE_CANVAS_CREAC 4
#define ID_BOTON_PLAY 5
#define ID_BOTON_PLAY_BORDE 6
#define ID_BOTON_PLAY_FONDO 7
#define ID_CANVAS_RELLENO 8
#define ID_BORDE_RELLENO 8
#define ID_SCROLL_ARRIBA 9
#define ID_SCROLL_ABAJO 10

#define ID_FACTORY_BALANCIN 50
#define ID_FACTORY_BOLA 51
#define ID_FACTORY_CINTA 52
#define ID_FACTORY_CORREA 53
#define ID_FACTORY_ENGRANAJE 54
#define ID_FACTORY_GLOBO 55
#define ID_FACTORY_MOTOR 56
#define ID_FACTORY_PELOTA 57
#define ID_FACTORY_PLATAFORMA 58
#define ID_FACTORY_SOGA 59

//////////// Constantes de dibujo /////////

#define RADIO_PELOTA 3.0
#define RADIO_BOLA 3.0
#define RADIO_GLOBO 3.5
#define ANCHO_PLATAFORMA 10.0
#define ALTO_PLATAFORMA 2.5
#define ALTO_UNION_ESTATICA 10.0
#define ANCHO_UNION_ESTATICA 10.0

#define ANCHO_BALANCIN 15.0
#define ALTO_BALANCIN 1.6

#define ALTO_CINTA 5
#define ANCHO_CINTA 20
#define RADIO_EJE_CINTA 3.0

#define RADIO_ENGRANAJE_CHICO 2.5
#define RADIO_ENGRANAJE 3.5
#define RADIO_ENGRANAJE_GRANDE 5.5
#define RADIO_MOTOR 3.5

#endif /* CONSTANTESVISTA_H_ */
}
