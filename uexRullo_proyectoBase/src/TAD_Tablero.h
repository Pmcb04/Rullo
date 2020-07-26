/*
 * TAD_Tablero.h
 *
 *  Created on: Dec 5, 2018
 *      Authors: Pedro Miguel Carmona Broncano Y Rubén Marín Lucas
 */

#ifndef TAD_TABLERO_H_
#define TAD_TABLERO_H_


#include "TAD_Casilla.h"

const int MAX = 8;
typedef Casilla TipoMatriz [MAX][MAX];
typedef int TipoVector [MAX];
typedef int TipoMatrizInt [MAX][MAX];


struct Tablero {

	TipoMatriz matrizTablero;
	TipoVector vSumaFilas;
	TipoVector vSumaCol;
	int dimReal;

};


/*
 * PRE: { }
 * POST: { inicia el tablero con valores aleatorios y posteriormente suma las filas y
 * 		   las columnas poniendo algunas celdas a 0 y las guarda en vectores en el tablero
 * 		   y luego pone las casillas que se han cambiado a cero con el valor anterior }
 * COMPLEJIDAD: O(n²);
 *
 */

void iniciarAleatorio (Tablero &t,int MAX_Desactivar);


/*
 * PRE: { }
 * POST: { inicia el tablero con los valores leidos en el archivo "rullo.cnf"
 *         y tambien guarda en el tablero los vectores con las sumas de las filas
 *         y las columnas tambien sacadas del archivo rullo.cnf}
 * COMPLEJIDAD: O(n²);
 *
 */

void iniciarArchivo (Tablero &t, TipoMatrizInt m, TipoVector vSumaFilas, TipoVector vSumaCol);

/*
 * PRE: { 4 <= tamano <= 8 }
 * POST: { Modifica el valor del campo dimReal del tablero t por la variable tamano }
 * COMPLEJIDAD: O(1);
 *
 */

void copiarDimensionReal (Tablero &t, int tamano);

/*
 * PRE: { t debe estar inicializada correctamente  1 <= v <= 9
 * 			  0 <= i <= t.dimReal-1    0 <= j <= t.dimReal-1   }
 * POST: { Modifica el campo "valor" de la casilla en la posicion
 * 		 (i,j) por la información de la variable v }
 * COMPLEJIDAD: O(1);
 *
 */

void cambiarValorCelda (Tablero &t, int i, int j, int v);

/*
 * PRE: { t debe estar inicializada correctamente   0 <= i <= t.dimReal-1    0 <= j <= t.dimReal-1 }
 * POST: { Modifica  el estado de activacion de la celda en la posición (i,j)}
 * COMPLEJIDAD: O(1);
 *
 */

void cambiarEstadoActivacionCelda(Tablero &t, int i, int j);

/*
 * PRE: { t debe estar inicializada correctamente    0 <= i <= t.dimReal-1    0 <= j <= t.dimReal-1  }
 * POST: {  Modifica  el estado de bloqueo de la celda en la posición (i,j)}
 * COMPLEJIDAD: O(1);
 *
 */

void cambiarEstadoBloqueoCelda(Tablero &t, int i, int j);

/*
 * PRE: { t debe estar inicializada correctamente   0 <= i <= t.dimReal-1    0 <= j <= t.dimReal-1 }
 * POST: { Devuelve el valor de la celda en la posicion (i,j) }
 * COMPLEJIDAD: O(1);
 *
 */

int obtenerValorCelda(Tablero &t, int i, int j);

/*
 * PRE: { t debe estar inicializada correctamente }
 * POST: { Devuelve el tamaño real de t }
 * COMPLEJIDAD: O(1);
 *
 */

int obtenerDimensionReal (Tablero &t);

/*
 * PRE: { t debe estar inicializada correctamente  0 <= i <= t.dimReal-1 }
 * POST: { Devuelve el valor de la posición i del vector "t.vSumaFilas" }
 * COMPLEJIDAD: O(1);
 *
 */

int obtenervSumaFilas(Tablero t, int i);

/*
 * PRE: { t debe estar inicializada correctamente  0 <= j <= t.dimReal-1 }
 * POST: { Devuelve el valor de la posición j del vector "t.vSumaCol" }
 * COMPLEJIDAD: O(1);
 *
 */

int obtenervSumaCol(Tablero t, int j);

/*
 * PRE: { t debe estar inicializada correctamente    0 <= i <= t.dimReal-1    0 <= j <= t.dimReal-1 }
 * POST: { Devuelve el estado de activacion de la celda en la posicion (i,j)}
 * COMPLEJIDAD: O(1);
 *
 */

bool obtenerEstadoActivacionCelda(Tablero &t, int i, int j);

/*
 * PRE: { t debe estar inicializada correctamente   0 <= i <= t.dimReal-1    0 <= j <= t.dimReal-1  }
 * POST: { Devuelve el estado de bloqueo de la celda en la posicion (i,j) }
 * COMPLEJIDAD: O();
 *
 */

bool obtenerEstadoBloqueoCelda (Tablero &t, int i, int j);


/*
 * PRE: { t debe estar inicializada correctamente   0 <= k <= t.dimReal-1  }
 * POST: {  Suma las casillas activas de la fila k }
 * COMPLEJIDAD: O(n);
 *
 */


int sumaCasillasFilas (Tablero &t, int k);

/*
 * PRE: { t debe estar inicializada correctamente   0 <= k <= t.dimReal-1  }
 * POST: {  Suma las casillas activas de la columna k }
 * COMPLEJIDAD: O(n);
 *
 */


int sumaCasillasColumnas (Tablero &t, int k);

/*
 * PRE: { t debe estar inicializada correctamente }
 * POST: { Comprueba si la suma de las casillas activas en cada fila coincide
 * 		   con su valor resultado en "t.vSumaFilas"}
 * COMPLEJIDAD: O(n);
 *
 */

bool tableroResueltoFilas (Tablero &t);


/*
 * PRE: { m debe estar inicializada correctamente }
 * POST: { Comprueba si la suma de las casillas activas en cada columna coincide
 * 		   con su valor resultado en "t.vSumaCol"}
 * COMPLEJIDAD: O(n);
 *
 */

bool tableroResueltoColumnas (Tablero &t);


#endif /* TAD_TABLERO_H_ */
