/*
 * PruebasTAD_Casilla.cpp
 *
 *  Created on: Dec 8, 2018
 *     Authors: Pedro Miguel Carmona Broncano Y Rubén Marín Lucas
 */

#include "PruebasTAD_Casilla.h"


void pruebaTADCasilla(){


	  Casilla c;

	  cout << "----------------INICIO PRUEBAS CASILLA------------" << endl << endl;
	  //Creamos la casilla con los datos diseñados en la prueba
	  iniciarCasilla(c);
	  //comprobamos que los datos introducidos son los correctos
	  if(obtenerValor(c) != 1){
	      cout << "Error al obtener el valor de la casilla 1"<<endl;
	  }
	  if(casillaActiva(c) != true){
	      cout << "Error al obtener el estado de activación de la casilla 1"<<endl;
	  }
	  if(casillaBloqueada(c) != false){
	        cout << "Error al obtener el estado de bloqueo de la casilla 1"<<endl;
	    }

	  //Probamos también el cambio de estado

	  ponerValor(c,5);

	  if(obtenerValor(c) != 5){
	      cout << "Error al cambiar el estado de activación de la casilla 1"<<endl;
	  }
	  cambiarEstadoActivacion(c);

	  if(casillaActiva(c) != false){
	      cout << "Error al cambiar el estado de activación de la casilla 1"<<endl;
	  }


	  cambiarEstadoBloqueo(c);

	  if(casillaBloqueada(c) != true){
	      cout << "Error al obtener el estado de bloqueo de la casilla 1"<<endl;
	  }
	  cout << "----------------FIN PRUEBAS CASILLA------------" << endl << endl;

	}

