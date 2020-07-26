/*
 * TAD_Juego.cpp
 *
 *  Created on: Dec 13, 2018
 *      Authors: Pedro Miguel Carmona Broncano Y Rubén Marín Lucas
 */

#include "TAD_Juego.h"
#include <iostream>
using namespace std;

void terminar (bool mensaje){


	if (mensaje) {

		entornoMostrarMensajeFin("¡¡¡  Has ganado !!!");

	}else {

		entornoMostrarMensajeFin("¡¡¡  Gracias por jugar !!!");

	}

	entornoPausa(5);
	entornoTerminar();

}



void confirmarTableroResueltoFilas (Juego &J, int i){


	if(sumaCasillasFilas(J.tablero, i-1)==obtenervSumaFilas(J.tablero, i-1)){


		entornoPonerResultado(i,0,obtenervSumaFilas(J.tablero, i-1),true);
		entornoPonerResultado(i,obtenerDimensionReal(J.tablero)+1,obtenervSumaFilas(J.tablero, i-1),true);


	}else{

		entornoPonerResultado(i,0,obtenervSumaFilas(J.tablero, i-1),false);
		entornoPonerResultado(i,obtenerDimensionReal(J.tablero)+1,obtenervSumaFilas(J.tablero, i-1),false);

	}
}


void confirmarTableroResueltoColumnas (Juego &J, int j){


	if(sumaCasillasColumnas(J.tablero,j-1)==obtenervSumaCol(J.tablero, j-1)){


			entornoPonerResultado(0,j,obtenervSumaCol(J.tablero, j-1),true);
			entornoPonerResultado(obtenerDimensionReal(J.tablero)+1,j,obtenervSumaCol(J.tablero, j-1),true);


	}else{

			entornoPonerResultado(0,j,obtenervSumaCol(J.tablero, j-1),false);
			entornoPonerResultado(obtenerDimensionReal(J.tablero)+1,j,obtenervSumaCol(J.tablero, j-1),false);


	}

}


void leerTeclas(Juego &J, int &i, int &j){

	TipoTecla tecla;

	int tamano = obtenerDimensionReal(J.tablero);
	int puntos = 0;
	bool salir = false;
	bool tfila = false;
	bool tcol = false;

	while((tfila != true || tcol != true) && salir != true){


		J.puntos = puntos;
		entornoPonerPuntuacion(puntos);
		tecla = entornoLeerTecla();
		entornoDesmarcarPosicion(i, j);

		if (puntos < 0) {

			puntos = 0;

		}


			switch (tecla) {
				case TSalir:

					salir = true;

					break;
				case TArriba:

					if(i == 1){

						i = tamano;

					}else{

						i--;

					}

					break;
				case TAbajo:

					if(i == tamano){

						i = 1;

					}else{

						i++;

					}

					break;
				case TDerecha:

					if(j == tamano){

						j = 1;

					}else{
						j++;

					}

					break;
				case TIzquierda:


					if(j == 1){

						j = tamano;

					}else{

						j--;

					}

					break;
				case TEnter:

				{

					cambiarEstadoBloqueoCelda(J.tablero, i-1, j-1);
					bool bloqueo = obtenerEstadoBloqueoCelda(J.tablero, i-1, j-1);
					bool activado = obtenerEstadoActivacionCelda(J.tablero, i-1, j-1);
					int num = obtenerValorCelda(J.tablero, i-1, j-1);


					if(bloqueo){

						entornoPonerBloqueado(i, j, num, activado);

					}else{


						entornoPonerNumero(i, j, num, activado);

					}

				}break;
				case TSPACE:{

					if (obtenerEstadoBloqueoCelda(J.tablero, i-1, j-1)==false) {

						cambiarEstadoActivacionCelda(J.tablero, i-1, j-1);
						bool activado = obtenerEstadoActivacionCelda(J.tablero, i-1, j-1);
						int num = obtenerValorCelda(J.tablero, i-1, j-1);
						entornoPonerNumero(i, j, num, activado);

						if(activado == false){


							puntos = puntos +2;


						}else{

							puntos = puntos-3;

						}

						tfila = tableroResueltoFilas(J.tablero);
						tcol = tableroResueltoColumnas(J.tablero);
						confirmarTableroResueltoFilas(J, i);
						confirmarTableroResueltoColumnas(J, j);




					}

				}break;
				case TY:{

					if (puntos == 0) {

						entornoMostrarMensaje("Puntos insuficientes");

					}else{


						int numFilas = sumaCasillasFilas(J.tablero, i-1);
						int numCol = sumaCasillasColumnas(J.tablero, j-1);
						entornoPonerResultado(i, tamano+2, numFilas, false);
						entornoPonerResultado(tamano+2, j, numCol, false);

						puntos = puntos/2;

						entornoPausa(5);

						entornoQuitarResultado(i, tamano+2);
						entornoQuitarResultado(tamano+2, j);

					}

				}break;
				default:
					break;
			}

			entornoMarcarPosicion(i, j);


			if (salir == true) {

				terminar(!salir);

			}

			if (tfila == true && tcol == true) {

				terminar(true);
			}

	}

}


void jugar(Juego &J){


	int tamano = obtenerDimensionReal(J.tablero);
	entornoIniciar(obtenerDimensionReal(J.tablero));
	entornoMostrarMensaje ("Proyecto con Ampliaciones");;

	for ( int i=1; i<=tamano; i++){
		for (int j=1; j<=tamano; j++){

			int valor = obtenerValorCelda(J.tablero, i-1, j-1);
			entornoPonerNumero(i,j,valor,true);
		}

	}


	entornoPausa (2);

	for (int i=1; i<=tamano; i++){

			entornoPonerResultado(i,tamano+1,obtenervSumaFilas(J.tablero, i-1),false);
			entornoPonerResultado(i,0,obtenervSumaFilas(J.tablero, i-1),false);
			entornoPonerResultado(tamano+1,i,obtenervSumaCol(J.tablero, i-1),false);
			entornoPonerResultado(0,i,obtenervSumaCol(J.tablero, i-1),false);

			entornoPausa (0.2);
	}


	int i = 1;
	int j = 1;
	entornoMarcarPosicion(i, j);

	for (int k = 1; k <= obtenerDimensionReal(J.tablero); k++) {

		confirmarTableroResueltoColumnas(J, k);
		confirmarTableroResueltoFilas(J, k);
		entornoPausa(0.5);

	}

	leerTeclas(J, i, j);


}


void iniciarJuego (Juego &J){


	TipoVector vSumaFilas, vSumaCol;
	TipoMatrizInt m;

	int tamano, cargarDeFichero, numMvtos, nivel;

	entornoCargarConfiguracion(tamano, cargarDeFichero, numMvtos, nivel, m, vSumaFilas, vSumaCol);
	copiarDimensionReal(J.tablero, tamano);


		if(cargarDeFichero == 0){


			iniciarArchivo(J.tablero, m, vSumaFilas, vSumaCol);



		}else{


			iniciarAleatorio(J.tablero, cargarDeFichero);

		}




}
