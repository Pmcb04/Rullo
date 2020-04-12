/*
 * TAD_Juego.h
 *
 *  Created on: Dec 13, 2018
 *      Authors: Pedro Miguel Carmona Broncano Y Rubén Marín Lucas
 */

#include "TAD_Tablero.h"
#include "entorno.h"

struct Juego{

	Tablero tablero;

};


/*
 * PRE: { mensaje declarada correctamente }
 * POST: { Dependiendo mensaje  mostrará un mensaje de despedida o
 * 		   de victoria}
 * COMPLEJIDAD: O(1);
 *
 */

void terminar (bool mensaje);

/*
 * PRE: { J correctamente declarado   0 <= i <= t.dimReal-1   }
 * POST: { Cada vez que se llame a este modulo comprobará si el
 * 		   tablero J.tablero está resuelto por filas y pone el resultado enmarcado }
 * COMPLEJIDAD: O(1);
 *
 */

void confirmarTableroResueltoFilas (Juego &J, int i);


/*
 * PRE: { J correctamente declarado   0 <= i <= t.dimReal-1   }
 * POST: { Cada vez que se llame a este modulo comprobará si el
 * 		   tablero J.tablero está resuelto por columnas y pone el resultado enmarcado }
 * COMPLEJIDAD: O(1);
 *
 */

void confirmarTableroResueltoColumnas (Juego &J, int j);

/*
 * PRE: { J, i, j declaradas correctamente    0 <= i <= t.dimReal-1    0 <= j <= t.dimReal-1 }
 * POST: { Este modulo es el encargado de la lectura de las teclas que se
 * 		   van introduciendo por teclado y de actualizar la funcion que hace cada tecla
 * 		   tanto en memoria como en pantalla }
 * COMPLEJIDAD: O(1);
 *
 */

void leerTeclas(Juego &J, int &i, int &j);

/*
 * PRE: { J declarada correctamente }
 * POST: { inicia el entorno gráfico a partir del tamano de la matriz
 *
 * 			si:
 *
 * 				cargarDeFichero = 0 --> se iniciará a partir de la matriz m (además de vSumaFilas y vSumaCol) leida en el archivo de configuracion
 * 				cargarDeFichero > 0 --> cargará la matriz del tablero de J iniciada aleatoriamente}
 *
 * COMPLEJIDAD: O(n²);
 *
 */

void iniciarJuego (Juego &J);

/*
 * PRE: { J correctamente declarado }
 * POST: { Este modulo se encarga de toda la interacción de la
 *         memoria con el apartado gráfico}
 * COMPLEJIDAD: O(n);
 *
 */

void jugar(Juego &J);


#ifndef TAD_JUEGO_H_
#define TAD_JUEGO_H_

#endif /* TAD_JUEGO_H_ */
