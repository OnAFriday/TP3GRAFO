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
	std::cout<<"Cargo la lista de estaciones de ferrocarril "<<std::endl;
	this->estacionesFerrocarril->cargarVertices(&registrosEstacionesTren);
	std::cout<<"Cargaron los vertices "<<std::endl;
	this->estacionesFerrocarril->cargarAristas();
	std::cout<<"Cargaron las aristas "<<std::endl;

	Archivo subtes(ARCHIVO_SUBTES);
	Lista<std::string> registrosBocasSubte;
	subtes.leerArchivo(registrosBocasSubte);
	std::cout<<"Cargo la lista de bocas "<<std::endl;
	this->subtes->cargarVertices(&registrosBocasSubte);
	std::cout<<"Cargaron los vertices "<<std::endl;
	this->subtes->cargarAristas();
	std::cout<<"Cargaron las aristas "<<std::endl;

	/*
	Archivo colectivos(ARCHIVO_COLECTIVOS);
	Lista<std::string> registrosEstacionesColectivo;
	colectivos.leerArchivo(registrosEstacionesColectivo);
	 */



}
/*post: tendria que imprimir una lista con las bocas de subte y a la derecha sus adyacentes;*/
void Ciudad::verRedSubte(){
	this->subtes->ListaAdyacencia();
}
void Ciudad::verRedTren(){
	this->estacionesFerrocarril->ListaAdyacencia();
}


Ciudad::~Ciudad(){
	delete this->subtes;
	delete this->estacionesFerrocarril;
	delete this->paradasColectivo;

}


