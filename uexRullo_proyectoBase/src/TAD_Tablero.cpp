/*
 * TAD_Tablero.cpp
 *
 *  Created on: Dec 5, 2018
 *      Authors: Pedro Miguel Carmona Broncano Y Rubén Marín Lucas
 */
#include "TAD_Tablero.h"
#include <stdlib.h>

void iniciarAleatorio (Tablero &t, int MAX_Desactivar){

	int contDesactivar = 0;
	int pos_i, pos_j;

	srand(time(NULL));

	for (int i = 0; i < t.dimReal; i++) {

		for (int j = 0; j < t.dimReal; j++) {

			iniciarCasilla(t.matrizTablero[i][j]);
			ponerValor(t.matrizTablero[i][j],rand() % 9 + 1);

			t.vSumaCol[j] = sumaCasillasColumnas(t,j);


		}

		t.vSumaFilas[i] = sumaCasillasFilas(t,i);


	}


	while(MAX_Desactivar > contDesactivar){

		pos_i = rand() % t.dimReal;
		pos_j = rand() % t.dimReal;
		int aux = obtenerValorCelda(t, pos_i, pos_j);
		cambiarValorCelda(t, pos_i, pos_j, 0);
		contDesactivar++;

		t.vSumaCol[pos_j] = sumaCasillasColumnas(t,pos_j);
		t.vSumaFilas[pos_i] = sumaCasillasFilas(t,pos_i);

		cambiarValorCelda(t,pos_i,pos_j, aux);



	}




}



void iniciarArchivo (Tablero &t,TipoMatrizInt m,  TipoVector vSumaFilas, TipoVector vSumaCol){


	for (int i = 0; i < t.dimReal; i++) {

			for (int j = 0; j < t.dimReal; j++) {

				iniciarCasilla(t.matrizTablero[i][j]);
				cambiarValorCelda(t, i, j, m[i][j]);
				t.vSumaCol[j] = vSumaCol[j];

			}

			t.vSumaFilas[i] = vSumaFilas[i];

	}



}

void copiarDimensionReal (Tablero &t, int tamano){

	t.dimReal = tamano;

}

void cambiarValorCelda (Tablero &t, int i, int j, int v){

	ponerValor(t.matrizTablero[i][j], v);

}

void cambiarEstadoActivacionCelda(Tablero &t, int i, int j){

	cambiarEstadoActivacion(t.matrizTablero[i][j]);
}

void cambiarEstadoBloqueoCelda(Tablero &t, int i, int j){

	cambiarEstadoBloqueo(t.matrizTablero[i][j]);

}

int obtenervSumaFilas(Tablero t, int i){

	return t.vSumaFilas[i];

}

int obtenervSumaCol(Tablero t, int j){

	return t.vSumaCol[j];

}

int obtenerValorCelda(Tablero &t, int i, int j){

	return obtenerValor(t.matrizTablero[i][j]);
}

int obtenerDimensionReal (Tablero &t){

	return t.dimReal;

}


bool obtenerEstadoActivacionCelda(Tablero &t, int i, int j){

	return casillaActiva(t.matrizTablero[i][j]);

}

bool obtenerEstadoBloqueoCelda (Tablero &t, int i, int j){

	return casillaBloqueada (t.matrizTablero[i][j]);

}


int sumaCasillasFilas (Tablero &t, int i){

	int suma = 0;

		for (int j = 0; j < t.dimReal; j++) {

			if(obtenerEstadoActivacionCelda(t,i, j) == true){

				suma = suma + obtenerValorCelda(t, i, j);

			}


		}

	return suma;

}


int sumaCasillasColumnas(Tablero &t, int j){

	int suma = 0;

		for (int i = 0; i < t.dimReal; i++) {

			if(obtenerEstadoActivacionCelda(t,i, j) == true){

				suma = suma + obtenerValorCelda(t, i, j);


			}

		}


	return suma;

}

bool tableroResueltoFilas (Tablero &t){

	int contador = 0;


	for (int  i = 0; i < t.dimReal; i++) {

			if(t.vSumaFilas[i] == sumaCasillasFilas(t,i)){

				contador++;

			}


	}

	return contador == t.dimReal;


}

bool tableroResueltoColumnas (Tablero &t){

	int contador = 0;

	for (int  j = 0; j < t.dimReal; j++) {

			if(t.vSumaCol[j] == sumaCasillasColumnas(t,j)){

				contador++;

			}
	}


	return contador == t.dimReal;


}






