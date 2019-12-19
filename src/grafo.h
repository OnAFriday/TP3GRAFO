
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
		void insertarVertice(Estacion *parada);
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

};



#endif /* GRAFO_H_ */
