/*
 * Vertice.h
 *
 *  Created on: 19 dic. 2019
 *      Author: cristian
 */

#ifndef SRC_VERTICE_H_
#define SRC_VERTICE_H_
#include "Estacion.h"
#include <list>

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
	std::list<Arista*>*aristas;
	ui index;

	public:
	Vertice(){
		this->siguiente=NULL;
		this->adyacente=NULL;
		this->parada=NULL;
		this->aristas= new std::list<Arista*>;
		this->index=0;
	}
	void agregarArista(Arista*nuevaArista){
		std::list<Arista*> ::iterator i;

         Arista* tempArista;
         bool existe=false;
         for(i = aristas->begin(); i != aristas->end(); i++) {
            tempArista = *i;
            existe=tempArista->obtenerVerticeDestino()->obtenerDato()->verNombre()==nuevaArista->
            		obtenerVerticeDestino()->obtenerDato()->verNombre();
         }
         if(!existe){
     		this->aristas->push_back(nuevaArista);

         }
	}
	std::list<Arista*>*obtenerAristas(){
		return this->aristas;
	}
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
	ui obtenerMarca(){
		return this->index;
	}
	~Vertice(){
		std::list<Arista*> ::iterator i;
        Arista* tempArista;

         while(!this->aristas->empty()){
        	 tempArista= aristas->front();
        	 aristas->pop_front();
        	 delete tempArista;
         }
         delete this->aristas;
		delete this->parada;

	}
};
#endif /* SRC_VERTICE_H_ */
