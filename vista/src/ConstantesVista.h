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

#define ALTO_PANEL_LOG 80
#define ALTO_VISTA_BALANCIN_LOG 4.0 //U logicas
#define ALTO_VISTA_PLATAFORMA_LOG 4.0 //U logicas
#define ALTO_VISTA_CINTA_LOG 8.0 //U logicas
#define ANCHO_ENGRANAJE 13
#define ALTO_VISTA_CINTA_RAMPA_LOG 1.0
#define RADIO_EJE_CINTA_LOG 3
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
#define PATH_VISTA_FLECHA_SCROLL "resource/flecha.png"
#define PATH_EDICION_UNION "resource/seleccionUnion.png"
#define PATH_AGRANDAR_IMG "resource/agrandar.png"
#define PATH_ROTACION_IMG "resource/rotacion.png"
#define PATH_ERROR_IMG "resource/error.jpg"
#define PATH_ZONA_CREACION "resource/fondoHerramientas.jpg"
#define PATH_BOTON_PLAY "resource/play.png"
#define PATH_BOTON_STOP "resource/stop.png"
#define IMG_ERROR "error.jpg"
#define PATH_FONDO "resource/fondo.jpg"


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


#endif /* CONSTANTESVISTA_H_ */
}
