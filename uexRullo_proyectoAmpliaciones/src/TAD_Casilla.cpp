/*
 * TAD_Casilla.cpp
 *
 *  Created on: Dec 3, 2018
 *      Authors: Pedro Miguel Carmona Broncano Y Rubén Marín Lucas
 */



#include "TAD_Casilla.h"


void iniciarCasilla (Casilla &c){

	c.valor = 1;
	c.activa = true;
	c.bloqueada = false;

}

void ponerValor(Casilla &c, int v){

	c.valor = v;
}

void cambiarEstadoActivacion (Casilla &c){

	if(c.activa){

		c.activa = false;

	}else{

		c.activa = true;

	}

}

void cambiarEstadoBloqueo (Casilla &c){


	if(c.bloqueada){

		c.bloqueada = false;

	}else{

		c.bloqueada = true;

	}
}


int obtenerValor (Casilla &c){

	return c.valor;
}

bool casillaActiva(Casilla &c){

	return c.activa;
}

bool casillaBloqueada (Casilla &c){

	return c.bloqueada;
}






