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

	this->estacionesTren = new Lista<Estacion*>;
	this->bocasSubte = new Lista<Estacion*>;
	this->estacionesColectivo = new Lista<Estacion*>;
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
	this->subtes;
	/*Recorrido y carga de registros en listas*/


	//cargarDatos(this->bocasSubte, registrosBocasSubte, "subte");
	//std::cout<<"cargaron datos de subtes"<<std::endl;

	//cargarDatos(this->estacionesTren, registrosEstacionesTren, "ferrocarril");
	//std::cout<<"cargaron datos de trenes"<<std::endl;
	//cargarDatos(this->estacionesColectivo, registrosEstacionesColectivo, "colectivo");
	//std::cout<<"cargaron datos de colectivos"<<std::endl;

	//this->paradasColectivoAux.agregar(*estacionesColectivo);
}



void Ciudad::cargarDatos(Lista<Estacion*>* medioDeTransporte, Lista<std::string> datos, std::string tipoDeTransporte){
	
	datos.iniciarCursor();

	while(datos.avanzarCursor()) {
		std::string infoEstacion = datos.obtenerCursor();
		Estacion* nuevaEstacion = new Estacion (infoEstacion, tipoDeTransporte);
		medioDeTransporte->agregar(nuevaEstacion);
	}
}

Ciudad::~Ciudad(){

	borrarDatos(this->bocasSubte);
	borrarDatos(this->estacionesColectivo);
	borrarDatos(this->estacionesTren);
}

void Ciudad::borrarDatos(Lista<Estacion*>* medioDeTransporte){

	medioDeTransporte->iniciarCursor();

	while (medioDeTransporte->avanzarCursor()){
		delete medioDeTransporte->obtenerCursor();
	}

	delete medioDeTransporte;
}
