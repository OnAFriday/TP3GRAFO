/*
 * Vertice.h
 *
 *  Created on: 19 dic. 2019
 *      Author: cristian
 */

#ifndef SRC_VERTICE_H_
#define SRC_VERTICE_H_
#include "Estacion.h"
class Vertice;
class Arista {
	typedef unsigned int ui;

	Arista *siguiente;
	Vertice *Adyacente;
	ui distancia;
	friend class Grafo;
	public:

	Arista(){
		this->siguiente=NULL;
		this->Adyacente=NULL;
		this->distancia=0;
	}
	Arista* obtenerAristaSig(){
		return this->siguiente;
	}
	ui obtenerDistancia(){
		return this->distancia;
	}
	~Arista(){

	}

};

class Vertice{

	typedef unsigned int ui;
	Vertice *siguiente;
	Arista *adyacente;
	Estacion* parada;
	friend class Grafo;

	public:

	Arista* obtenerAristaAdyacente(){
		return this->adyacente;
	}
	Vertice* obtenerVerticeSig(){
		return this->siguiente;
	}
	bool operator !=(Vertice* aComparar){
			return (this->parada!=aComparar->parada);
	}
	Estacion *obtenerDato(){
		return this->parada;
	}
	~Vertice(){

		while(adyacente != NULL) {
			//std::cout<<aristaAux->Adyacente->parada->verNombre() <<"-->";
			Arista *aristaAux=adyacente;
			adyacente=aristaAux->obtenerAristaSig();

			delete aristaAux;
		}

		delete this->parada;

	}
};
#endif /* SRC_VERTICE_H_ */