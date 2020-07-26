/*
 * PruebasTAD_Tablero.h
 *
 *  Created on: Dec 12, 2018
 *      Authors: Pedro Miguel Carmona Broncano y Rubén Marín Lucas
 */

#ifndef PRUEBASTAD_TABLERO_H_
#define PRUEBASTAD_TABLERO_H_

#include "TAD_Tablero.h"
#include "entorno.h"


void pruebaTAD_Tablero();


/*
 * En este modulo primero se inicia la matriz del tablero leida por el archivo de configuración para después comprobar que la matriz
 * que introducimos en el tablero es igual a la matriz m, idem para vSumaFilas y vSumaCol
 *
 */

void pruebaIniciarArchivo(Tablero &t, TipoMatrizInt m, TipoVector vSumaFilas, TipoVector vSumaCol);

/*
 * En este modulo se inicia la matriz del tablero aleatoriamente y se comprueba que los valores introducidos en dicha matriz están
 * comprendidos entre el 1 y el 9 ambos inclusive.
 *
 *
 */

void pruebaIniciarAleatorio (Tablero &t, int tamano, int MAX_Desactivar);

/*
 *  ******Paso 1 y 2******
 *
 *  Se inicia la matriz del tablero con valor 1, activa y no bloqueada quedando así la matriz:
 *
 *  1 1 1 1 -- 1
 *  1 1 1 1 -- 1
 *  1 1 1 1 -- 1
 *  1 1 1 1 -- 1
 *  | | | | -- |
 *  1 1 1 1 -- 1
 *
 *  --Dependiendo del la variable t.dimReal leida en el erchivo de configuración--
 *
 *
 *  Tambien se suman cada fila y columna para obtener cada posición de los vectores vSumaFilas y vSumaCol, y después se comprueba
 *  que cada posicion es igual a t.dimReal
 *
 *
 *
 *
 *   ******Paso 3******
 *
 *	Se cambian de estado de activación las cuatro esquinas del tablero.
 *
 *	esquina                      estadoActivacion
 *	_______________________________________________
 *
 *	(0,0)                               false
 *	(0,t.dimReal-1)                     false
 *	(t.dimReal-1,0)                     false
 *	(t.dimReal-1, t.dimReal-1)          false
 *
 *
 *
 *
 *  ******Paso 4******
 *
 *	Se comprueba que se ha cambiado el estado de activación de las casillas cambiadas anteriormente, ademas de ver
 *	que el estado de bloqueo permanece intacto
 *
 *	esquina                      estadoActivacion        estadoBloqueo
 *	___________________________________________________________________
 *
 *	(0,0)                               false                false
 *	(0,t.dimReal-1)                     false                false
 *	(t.dimReal-1,0)                     false                false
 *	(t.dimReal-1, t.dimReal-1)          false                false
 *
 *
 *
 *
 *	*****Paso 5******
 *
 *	Se vuelven a activar las casillas desactivadas y despues se bloquean, y se comprueba que el estado de bloqueo no
 *	influye en la suma de las filas o columnas
 *
 *	esquina                      estadoActivacion        estadoBloqueo
 *	___________________________________________________________________
 *
 *	(0,0)                               true                true
 *	(0,t.dimReal-1)                     true                true
 *	(t.dimReal-1,0)                     true                true
 *	(t.dimReal-1, t.dimReal-1)          true                true
 *
 *
 *
 *
 *	*****Paso 6******
 *
 *	Ahora desbloqueamos las casillas bloqueadas y cambiamos el valor de las cuatro esquinas para ver que la suma no
 *	concuerda con el valor almacenado en los vectores suma
 *
 *	esquina                      estadoActivacion        estadoBloqueo       valorCasilla
 *	_____________________________________________________________________________________
 *
 *	(0,0)                               true               	false                2
 *	(0,t.dimReal-1)                     true                false                2
 *	(t.dimReal-1,0)                     true                false                2
 *	(t.dimReal-1, t.dimReal-1)          true                false                2
 *
 *
 *	*****Paso 7******
 *
 *	Por ultimo vemos que regresando las cuatro esquinas al valor 1, la suma de las filas y de las columnas es correcto.
 *
 *	esquina                      estadoActivacion        estadoBloqueo       valorCasilla
 *	_____________________________________________________________________________________
 *
 *	(0,0)                               true               	false                1
 *	(0,t.dimReal-1)                     true                false                1
 *	(t.dimReal-1,0)                     true                false                1
 *	(t.dimReal-1, t.dimReal-1)          true                false                1
 *
 */

void pruebasOperaciones (Tablero &t);


#endif /* PRUEBASTAD_TABLERO_H_ */
