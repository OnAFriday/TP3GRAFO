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
	Vertice* obtenerVerticeDestino(){
		return this->Adyacente;
	}
	void agregarVerticeDestino(Vertice* nuevoDestino){
		this->Adyacente=nuevoDestino;
	}
	Arista* obtenerAristaSig(){
		return this->siguiente;
	}
	void cambiarAristaSig(Arista *nuevoSiguiente){
		this->siguiente=nuevoSiguiente;
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
	ui index;

	public:

	Arista* obtenerAristaAdyacente(){
		return this->adyacente;
	}
	void cambiarUltimaArista(Arista* aristaNueva){
		Arista *adyacenteAOrigenAux=this->adyacente;
		while (adyacenteAOrigenAux != NULL){
						/*obtiene la sig arista adyacente de origen, es decir cada vertice tiene una lista de arista que lo llevan a destino
						 * cuando llegue a una arista null guarda la nueva arista*/
						adyacenteAOrigenAux = adyacenteAOrigenAux->obtenerAristaSig();
		}
		adyacenteAOrigenAux=aristaNueva;
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
	ui obtenerMarca(){
		return this->index;
	}
	~Vertice(){

		while(adyacente != NULL) {
			Arista *aristaAux=adyacente;
			adyacente=aristaAux->obtenerAristaSig();

			delete aristaAux;
		}

		delete this->parada;

	}
};
#endif /* SRC_VERTICE_H_ */
