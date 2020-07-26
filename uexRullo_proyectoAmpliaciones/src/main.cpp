/*
 * main.cpp
 *
 *  Created on: Jan 15, 2019
 *      Authors: Pedro Miguel Carmona Broncano y Ruben Marín Lucas
 */

#include "TAD_Juego.h"
#include "PruebasTAD_Casilla.h"
#include "PruebasTAD_Tablero.h"


void juegoDePruebas(){

	pruebaTADCasilla();
	pruebaTAD_Tablero();

}

int main(){

	Juego J;

	iniciarJuego(J);
	jugar(J);

	//juegoDePruebas();



	return 0;

}



