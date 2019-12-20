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
	this->transportes=new Grafo;

	Archivo trenes("../estaciones-de-ferrocarril.csv");
	Lista<std::string> registrosEstacionesTren;
	trenes.leerArchivo(registrosEstacionesTren);

	Archivo subtes("../bocas-de-subte.csv");
	Lista<std::string> registrosBocasSubte;
	subtes.leerArchivo(registrosBocasSubte);
	/*
	Archivo colectivos(ARCHIVO_COLECTIVOS);
	Lista<std::string> registrosEstacionesColectivo;
	colectivos.leerArchivo(registrosEstacionesColectivo);
	 */
	this->subtes->cargarVertices(&registrosBocasSubte, "subte");
	this->subtes->cargarAristas();
	this->estacionesFerrocarril->cargarVertices(&registrosEstacionesTren, "ferrocarril");
	this->estacionesFerrocarril->cargarAristas();

	this->transportes->cargarVertices(&registrosBocasSubte, "subte");
	this->transportes->cargarVertices(&registrosEstacionesTren,"ferrocarril");
	std::cout<<"Cargo la lista de vertices "<<std::endl;
	this->transportes->cargarAristas();
	std::cout<<"Cargaron las adyacencias "<<std::endl;



}
/*post: tendria que imprimir una lista con las bocas de subte y a la derecha sus adyacentes;*/
void Ciudad::verRedSubte(){
	this->subtes->ListaAdyacencia();
}
void Ciudad::verRedTren(){
	this->estacionesFerrocarril->ListaAdyacencia();
}
void Ciudad::verRedTransporte(){
	this->transportes->ListaAdyacencia();
}

Ciudad::~Ciudad(){
	delete this->subtes;
	delete this->estacionesFerrocarril;
	delete this->paradasColectivo;
	delete this->transportes;

}


