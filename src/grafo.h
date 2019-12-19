
#ifndef GRAFO_H_
#define GRAFO_H_

#include <iostream>
#include <string>
#include "Estacion.h"
using namespace std;

class Vertice;
class Arista {
	typedef unsigned int ui;

	Arista *siguiente;
	Vertice *Adyacente;
	ui distancia;
	friend class Grafo;
	Arista(){
		this->siguiente=NULL;
		this->Adyacente=NULL;
		this->distancia=0;
	}
	public:
	Arista* obtenerAristaSig(){
		return this->siguiente;
	}
	ui obtenerDistancia(){
		return this->distancia;
	}

};

class Vertice{

	typedef unsigned int ui;
	Vertice *siguiente;
	Arista *adyacente;
	string nombre;
	Estacion* parada;
	friend class Grafo;

	public:

	bool operator !=(Vertice* aComparar){
			return (this->parada!=aComparar->parada);
		}
	~Vertice(){
		Arista *aristaABorrar=this->adyacente;
		this->adyacente=aristaABorrar->obtenerAristaSig();
		while(adyacente!=NULL){
			delete aristaABorrar;
			aristaABorrar=this->adyacente;
			this->adyacente=aristaABorrar->obtenerAristaSig();
		}
		delete this->parada;

	}

};




class Grafo {
	typedef unsigned int ui;

	Vertice *primero;
	ui tamanio;

	public:
		Grafo();
		bool estaVacio();
		int verCantidadVertices();
		Vertice *getVertice(Estacion *parada);
		void insertarVertice(Estacion *parada);
		void cargarVertices(Lista<std::string>*estaciones, std::string tipoTransporte);
		void cargarAristas();
		void insertarArista (Vertice *origen, Vertice *destino, ui distancia);
		/*de aca abajo metodos no probados*/
		void verVertices();
		void ListaAdyacencia();
		void EliminarArista(Vertice *origen, Vertice *destino);
		void EliminarVertice(Vertice *vertice);
		~Grafo();

};



#endif /* GRAFO_H_ */
