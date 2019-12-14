/*
 * Ciudad.cpp
 *
 *  Created on: 14 oct. 2019
 *      Author: cristian
 */

#include <iostream>
#include "Ciudad.h"
#include "Coordenadas.h"
#include "Estacion.h"
Ciudad::Ciudad(){

	this->estacionesFerrocarril=new Grafo;
	this->paradasColectivo=new Grafo;
	this->subtes=new Grafo;

	Archivo trenes(ARCHIVO_TRENES);
	Lista<std::string> registrosEstacionesTren;
	trenes.leerArchivo(registrosEstacionesTren);
/*
	Archivo colectivos(ARCHIVO_COLECTIVOS);
	Lista<std::string> registrosEstacionesColectivo;
	colectivos.leerArchivo(registrosEstacionesColectivo);
*/
	Archivo subtes(ARCHIVO_SUBTES);
	Lista<std::string> registrosBocasSubte;
	subtes.leerArchivo(registrosBocasSubte);
	this->subtes->cargarVertices(&registrosBocasSubte);
	this->subtes->cargarAristas();
	/*Recorrido y carga de registros en listas*/


}



Ciudad::~Ciudad(){
	delete this->subtes;
	delete this->estacionesFerrocarril;
	delete this->paradasColectivo;

}


