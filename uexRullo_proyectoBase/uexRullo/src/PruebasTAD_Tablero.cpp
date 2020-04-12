/*
 * PruebasTAD_Tablero.cpp
 *
 *  Created on: Dec 12, 2018
 *      Authors: Pedro Miguel Carmona Broncano Y Rubén Marín Lucas
 */


#include "PruebasTAD_Tablero.h"

void pruebaIniciarArchivo(Tablero &t, TipoMatrizInt m, TipoVector vSumaFilas, TipoVector vSumaCol){

	cout << "---------------INICIO PRUEBA TABLERO INICIAR ARCHIVO-------------------" << endl << endl;

	iniciarArchivo(t, m, vSumaFilas, vSumaCol);


	for (int i = 0; i < t.dimReal; i++) {

		for (int j = 0; j < t.dimReal; j++) {

			if(obtenerValorCelda(t, i, j) != m[i][j]){


				cout << "Error en la casilla " << i << " , " << j << endl;

			}

			if(vSumaFilas [i] != t.vSumaFilas[i]){


				cout << "Error en vSumaFilas, posicion " << i << endl;

			}

		}

		if(vSumaCol [i] != t.vSumaCol[i]){


			cout << "Error en vSumaCol, posicion " << i << endl;

		}
	}

	cout << "---------------FIN PRUEBA TABLERO INICIAR ARCHIVO-------------------" << endl << endl;



}

void pruebaIniciarAleatorio (Tablero &t){

	iniciarAleatorio(t, 0);

	cout << "--------------INICIO PRUEBA TABLERO ALEATORIO--------------" << endl << endl;

	for (int i = 0; i < t.dimReal; i++) {

		for (int j = 0; j < t.dimReal; j++) {

			if (obtenerValorCelda(t, i, j) < 1 || obtenerValorCelda(t, i, j) > 9) {

				cout << "Error en valor de la casilla " << i << ", " + j;

			}

		}

	}

	cout << "---------------FIN PRUEBA TABLERO ALEATORIO---------------" << endl << endl;

}

void pruebaOperaciones (Tablero t){

/*	1. Primero iniciaremos una matriz de t.dimReal x t.dimReal con valor en cada casilla de 1, activa y no bloqueada.

	2. Sumamos todas las filas y las columnas y las almacenamos en los vectores correspondientes (vSumaFilas y vSumaCol)

	*/

	cout << "--------------INICIO PRUEBA OPERACIONES---------------" << endl << endl;
	cout << "--------------INICIO PASO 1 Y 2---------------" << endl << endl;

	for (int i = 0; i < t.dimReal; ++i) {

		for (int j = 0; j < t.dimReal; ++j) {

			iniciarCasilla(t.matrizTablero[i][j]);
			t.vSumaCol[j] = sumaCasillasColumnas(t, j);

		}

		t.vSumaFilas[i] = sumaCasillasFilas(t,i);
	}

	if (obtenervSumaFilas(t, 0)!=t.dimReal) {

		cout << "Error en suma de la fila 0" << endl;

	}

	if (obtenervSumaFilas(t, t.dimReal-1)!= t.dimReal) {

		cout << "Error en suma de la fila t.dimReal" << endl;

	}

	if (obtenervSumaCol(t, 0)!= t.dimReal) {

		cout << "Error en suma de la columna 0" << endl;

	}

	if (obtenervSumaCol(t, t.dimReal-1)!=t.dimReal) {

		cout << "Error en suma de la columna t.dimReal" << endl;

	}



	cout << "---------------FIN PASO 1 Y 2---------------" << endl << endl;



	/*
	 * 3. Procedemos ahora a desactivar las 4 esquinas, por lo cual tambien tiene que ser diferente el valor objetivo con la suma dada.
	 *
	 */


	cout << "---------------INICIO PASO 3---------------" << endl << endl;

	cambiarEstadoActivacionCelda(t, 0, 0);
	cambiarEstadoActivacionCelda(t, 0, t.dimReal-1);
	cambiarEstadoActivacionCelda(t, t.dimReal-1, 0);
	cambiarEstadoActivacionCelda(t, t.dimReal-1, t.dimReal-1);


	if (sumaCasillasFilas(t, 0)==obtenervSumaFilas(t, 0)) {

		cout << "Error en suma de la fila 0" << endl;

	}

	if (sumaCasillasFilas(t, t.dimReal-1)==obtenervSumaFilas(t, t.dimReal-1)) {

		cout << "Error en suma de la fila t.dimReal" << endl;

	}

	if (sumaCasillasColumnas(t, 0)==obtenervSumaCol(t, 0)) {

		cout << "Error en suma de la columna 0" << endl;

	}

	if (sumaCasillasColumnas(t, t.dimReal-1)==obtenervSumaCol(t, t.dimReal-1)) {

		cout << "Error en suma de la columna t.dimReal" << endl;

	}


	cout << "---------------FIN PASO 3--------------" << endl << endl;

	/*
	 * 4. Obtenemos el estado de activacion y de bloqueo de las casillas que hemos cambiado el estado de activacion anteriormente
	 *  y vemos que ahora está desactivada y no bloqueda
	 *
	 */


	cout << "---------------INICIO PASO 4---------------" << endl << endl;

	if (obtenerEstadoActivacionCelda(t, 0, 0) != false) {

		cout << "Error en obtencion de estado de activacion de casilla (0,0)" << endl;

	}

	if (obtenerEstadoBloqueoCelda(t, 0, 0) ==true) {

		cout << "Error en obtencion de estado de bloqueo de casilla (0,0)" << endl;


	}

	if (obtenerEstadoActivacionCelda(t, 0, t.dimReal-1) != false) {

		cout << "Error en obtencion de estado de activacion de casilla (0,0)" << endl;

	}

	if (obtenerEstadoBloqueoCelda(t, 0, t.dimReal-1) ==true) {

		cout << "Error en obtencion de estado de bloqueo de casilla (0,0)" << endl;


	}

	if (obtenerEstadoActivacionCelda(t, t.dimReal-1, 0) != false) {

		cout << "Error en obtencion de estado de activacion de casilla (0,0)" << endl;

	}

	if (obtenerEstadoBloqueoCelda(t, t.dimReal-1, 0) ==true) {

		cout << "Error en obtencion de estado de bloqueo de casilla (0,0)" << endl;


	}

	if (obtenerEstadoActivacionCelda(t, t.dimReal-1, t.dimReal-1) != false) {

		cout << "Error en obtencion de estado de activacion de casilla (0,0)" << endl;

	}

	if (obtenerEstadoBloqueoCelda(t, t.dimReal-1, t.dimReal-1) ==true) {

		cout << "Error en obtencion de estado de bloqueo de casilla (0,0)" << endl;


	}




	cout << "---------------FIN PASO 4---------------" << endl << endl;


	/*
	 * 5. Volvemos a activar las casillas desactivadas (en este ejemplo, las cuatro esquinas), para posteriormente bloquearlas y ver
	 *  que no influye en la suma de las filas y columnas
	 *
	 */


	cout << "---------------INICIO PASO 5---------------" << endl << endl;

	cambiarEstadoActivacionCelda(t, 0, 0);
	cambiarEstadoActivacionCelda(t, 0, t.dimReal-1);
	cambiarEstadoActivacionCelda(t, t.dimReal-1, 0);
	cambiarEstadoActivacionCelda(t, t.dimReal-1, t.dimReal-1);

	cambiarEstadoBloqueoCelda(t, 0, 0);
	cambiarEstadoBloqueoCelda(t, 0, t.dimReal-1);
	cambiarEstadoBloqueoCelda(t, t.dimReal-1, 0);
	cambiarEstadoBloqueoCelda(t, t.dimReal-1, t.dimReal-1);

	if (sumaCasillasFilas(t, 0)!=obtenervSumaFilas(t, 0)) {

		cout << "Error en suma de la fila 0" << endl;

	}

	if (sumaCasillasFilas(t, t.dimReal-1)!=obtenervSumaFilas(t, t.dimReal-1)) {

		cout << "Error en suma de la fila t.dimReal" << endl;

	}

	if (sumaCasillasColumnas(t, 0)!=obtenervSumaCol(t, 0)) {

		cout << "Error en suma de la columna 0" << endl;

	}

	if (sumaCasillasColumnas(t, t.dimReal-1)!=obtenervSumaCol(t, t.dimReal-1)) {

		cout << "Error en suma de la columna t.dimReal" << endl;

	}


	cout << "---------------FIN PASO 5---------------" << endl << endl;


	/*
	 *   6.Procedemos a desactivar las casillas bloquedas y cambiamos el valor para comprobar que la suma de las filas
	 *   y las columnas no dan el valor resultado
	 *
	 */


	cout << "---------------INICIO PASO 6---------------" << endl << endl;


		cambiarEstadoBloqueoCelda(t, 0, 0);
		cambiarEstadoBloqueoCelda(t, 0, t.dimReal-1);
		cambiarEstadoBloqueoCelda(t, t.dimReal-1, 0);
		cambiarEstadoBloqueoCelda(t, t.dimReal-1, t.dimReal-1);

		cambiarValorCelda(t, 0, 0, 2);
		cambiarValorCelda(t, 0, t.dimReal-1, 2);
		cambiarValorCelda(t, t.dimReal-1, 0, 2);
		cambiarValorCelda(t, t.dimReal-1, t.dimReal-1, 2);


		if (sumaCasillasFilas(t, 0)==obtenervSumaFilas(t, 0)) {

			cout << "Error en suma de la fila 0" << endl;

		}

		if (sumaCasillasFilas(t, t.dimReal-1)==obtenervSumaFilas(t, t.dimReal-1)) {

			cout << "Error en suma de la fila t.dimReal" << endl;

		}

		if (sumaCasillasColumnas(t, 0)==obtenervSumaCol(t, 0)) {

			cout << "Error en suma de la columna 0" << endl;

		}

		if (sumaCasillasColumnas(t, t.dimReal-1)==obtenervSumaCol(t, t.dimReal-1)) {

			cout << "Error en suma de la columna t.dimReal" << endl;

		}


	cout << "---------------FIN PASO 6---------------" << endl << endl;


		/*
		 *  7.Por ultimo cambiamos el valor de nuevo a el valor original para comprobar que las sumas de las filas y
		 *  columnas si dan el valor resultado
		 *
		 */


	cout << "---------------INICIO PASO 7---------------" << endl << endl;

		cambiarValorCelda(t, 0, 0, 1);
		cambiarValorCelda(t, 0, t.dimReal-1, 1);
		cambiarValorCelda(t, t.dimReal-1, 0, 1);
		cambiarValorCelda(t, t.dimReal-1, t.dimReal-1, 1);


		if (sumaCasillasFilas(t, 0)!=obtenervSumaFilas(t, 0)) {

			cout << "Error en suma de la fila 0" << endl;

		}

		if (sumaCasillasFilas(t, t.dimReal-1)!=obtenervSumaFilas(t, t.dimReal-1)) {

			cout << "Error en suma de la fila t.dimReal" << endl;

		}

		if (sumaCasillasColumnas(t, 0)!=obtenervSumaCol(t, 0)) {

			cout << "Error en suma de la columna 0" << endl;

		}

		if (sumaCasillasColumnas(t, t.dimReal-1)!=obtenervSumaCol(t, t.dimReal-1)) {

			cout << "Error en suma de la columna t.dimReal" << endl;

		}


	cout << "---------------FIN PASO 7---------------" << endl << endl;
	cout << "---------------FIN PRUEBA OPERACIONES---------------" << endl << endl;


}

void pruebaTAD_Tablero(){

	int tamano, cargarDeFichero, numMvtos, nivel;
	Tablero t;
	TipoMatrizInt m;
	TipoVector vSumaFilas, vSumaCol;

	entornoCargarConfiguracion(tamano, cargarDeFichero, numMvtos, nivel, m, vSumaFilas, vSumaCol);
	t.dimReal = tamano;

	pruebaIniciarArchivo(t, m, vSumaFilas, vSumaCol);
	pruebaIniciarAleatorio(t);
	pruebaOperaciones(t);
}

