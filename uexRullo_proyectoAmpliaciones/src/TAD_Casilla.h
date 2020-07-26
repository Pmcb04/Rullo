/*
 * TAD_Casilla.h
 *
 *  Created on: Dec 3, 2018
 *     Authors: Pedro Miguel Carmona Broncano Y Rubén Marín Lucas
 */

#ifndef TAD_CASILLA_H_
#define TAD_CASILLA_H_

using namespace std;
#include <iostream>

struct Casilla{

	int valor;
	bool activa;
	bool bloqueada;


};


/*
 * PRE: {  }
 * POST: {Inicia la casilla c con un valor (1), activa y no bloqueada}
 * COMPLEJIDAD: O(1);
 *
 */

void iniciarCasilla (Casilla &c);

/*
 * PRE:{c debe estar inicializada correctamente     1 <= v <= 9}
 * POST:{Modifica el valor de la casilla c, cambiándolo por el valor v}
 * COMPLEJIDAD:O(1);
 *
 */

void ponerValor (Casilla &c, int v);

/*
 * PRE:{c debe estar inicializada correctamente}
 * POST:{Modifica el estado de activación de la casilla (si estaba
 * activa, se desctivará, o viceversa)}
 * COMPLEJIDAD:O(1);
 *
 */


void cambiarEstadoActivacion (Casilla &c);

/*
 * PRE:{c debe estar inicializada correctamente}
 * POST:{Modifica el estado de bloqueo de la casilla (si estaba
 * bloqueada, se desctivará, o viceversa)}
 * COMPLEJIDAD:O(1);
 *
 */

void cambiarEstadoBloqueo (Casilla &c);

/*
 * PRE:{c debe estar inicializada correctamente}
 * POST:{Devuelve el valor de la casilla c}
 * COMPLEJIDAD:O(1);
 *
 */

int obtenerValor (Casilla &c);


/*
 * PRE:{c debe estar inicializada correctamente}
 * POST:{Devuelve el estado de activación de la casilla c}
 * COMPLEJIDAD:O(1);
 *
 */

bool casillaActiva (Casilla &c);

/*
 * PRE:{c debe estar inicializada correctamente}
 * POST:{Devuelve el estado de bloqueo de la casilla c}
 * COMPLEJIDAD:O(1);
 *
 */

bool casillaBloqueada (Casilla &c);

#endif /* TAD_CASILLA_H_ */
