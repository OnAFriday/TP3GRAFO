
#ifndef GRAFO_H_
#define GRAFO_H_

#include <iostream>
#include <string>
#include "Vertice.h"


class Grafo {

	typedef unsigned int ui;

	Vertice *primero;
	Vertice* ultimo;
	ui tamanio;

	public:
		Grafo();
		bool estaVacio();
		int verCantidadVertices();
		Vertice *getVertice(Estacion *parada);
		void insertarVertice(Estacion *parada, ui index);
		void cargarVertices(Lista<std::string>*estaciones, std::string tipoTransporte);
		void cargarAristas();
		void insertarArista (Vertice *origen, Vertice *destino, ui distancia);
		void verVertices();
		void ListaAdyacencia();
		/*de aca abajo metodos no probados*/
		void dijkstra(Vertice* origen, Vertice* destino){


		}
		void EliminarArista(Vertice *origen, Vertice *destino);
		void EliminarVertice(Vertice *vertice);
		~Grafo();

		int ** cargarMatriz() {
			int matriz [this->tamanio][this->tamanio];
			Vertice * nodo = this->primero;

			for(ui i=0; i<this->tamanio; i++){
				for(ui j=0; j<this->tamanio; j++){
					
				}
			}
		}

};



#endif /* GRAFO_H_ */
