
#ifndef GRAFO_H_
#define GRAFO_H_

#include <iostream>
#include <string>
#include "Vertice.h"
#include <vector>

class Grafo
{

	typedef unsigned int ui;

	Vertice *primero;
	Vertice *ultimo;
	ui tamanio;
	int **matriz;
	ui index;
	long int infinito = 9999999;
private:
	void borrarMatriz(){
		/*
		for (ui i = 0; i < this->tamanio; i++) {
		        delete [] this->matriz[i];
		}
		   delete [] matriz;
	*/
		/*comenatrio para commit*/
	}

public:
	Grafo();
	bool estaVacio();
	int verCantidadVertices();
	Vertice *getVertice(Estacion *parada);
	Vertice* obtenerVertice(ui marca);
	Vertice *obtenerVertice(Coordenadas posicion);
	void insertarVertice(Estacion *parada, ui index);
	void cargarVertices(Lista<std::string> *estaciones, std::string tipoTransporte);
	void cargarAristas();
	void insertarArista(Vertice *origen, Vertice *destino, ui distancia);
	void verVertices();
	void ListaAdyacencia();

	void EliminarArista(Vertice *origen, Vertice *destino);
	void EliminarVertice(Vertice *vertice);

	void cargarMatriz();
	//metodo auxiliar para encontrar el vertice con la minima distancia
	int minDistance(int dist[], bool sptSet[]);
	void dijkstra(Vertice *origen);//, Vertice* destino)
	void imprimirRecorrido(int * dist, int * predecesor, Vertice *origen);
	void imprimirRecorrido(int *dist, int *predecesor, Vertice *origen, Vertice *destino);
	
	~Grafo();

};

#endif /* GRAFO_H_ */
