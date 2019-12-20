
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

public:
	Grafo();
	bool estaVacio();
	int verCantidadVertices();
	Vertice *getVertice(Estacion *parada);
	void insertarVertice(Estacion *parada, ui index);
	void cargarVertices(Lista<std::string> *estaciones, std::string tipoTransporte);
	void cargarAristas();
	void insertarArista(Vertice *origen, Vertice *destino, ui distancia);
	void verVertices();
	void ListaAdyacencia();
	/*de aca abajo metodos no probados*/

	void EliminarArista(Vertice *origen, Vertice *destino);
	void EliminarVertice(Vertice *vertice);
	~Grafo();

	void cargarMatriz()
	{
		this->matriz = new int *[this->tamanio];

		for (ui i = 0; i < this->tamanio; i++)
		{
			this->matriz[i] = new int[this->tamanio];
		}

		for (ui i = 0; i < this->tamanio; i++)
		{
			for (ui j = 0; j < this->tamanio; j++)
			{
				this->matriz[i][j] = infinito;
			}
		}

		Vertice *nodo = this->primero;
		while (nodo != NULL)
		{
			ui indice = nodo->obtenerMarca();

			Arista *aristaAdyacente = nodo->obtenerAristaAdyacente();
			while (aristaAdyacente != NULL)
			{
				ui indice2 = aristaAdyacente->obtenerVerticeDestino()->obtenerMarca();
				this->matriz[indice][indice2] = aristaAdyacente->obtenerDistancia();
				aristaAdyacente = aristaAdyacente->obtenerAristaSig();
			}
			nodo = nodo->obtenerVerticeSig();
		}

		// for(ui i=0; i<this->tamanio; i++){
		// 	for(ui j=0; j<this->tamanio; j++){
		// 			std::cout<<this->matriz[i][j]<< " | ";
		// 	}
		// 	std::cout<<std::endl;
		// }
		std::cout << this->matriz[44][45] << " | ";
	}

	//metodo auxiliar para encontrar el vertice con la minima distancia
	int minDistance(int dist[], bool sptSet[])
	{
		int min = infinito, min_index;

		for (int v = 0; v < this->tamanio; v++)
			if (sptSet[v] == false && dist[v] <= min)
				min = dist[v], min_index = v;

		return min_index;
	}

	void dijkstra(Vertice *origen)
	{
		//arreglo donde va a estar la distancia desde origan a cada uno de los demás vertices del grafo
		int dist[this->tamanio];

		//arreglo donde se indice si cada vertice ya fue recorrido
		bool sptSet[this->tamanio];

		//inicializo los arreglos
		for (int i = 0; i < this->tamanio; i++)
			dist[i] = infinito, sptSet[i] = false;

		//distancia del origen a si mismo es igual a cero
		dist[origen->obtenerMarca] = 0;

		for (int count = 0; count < this->tamanio - 1; count++) { 
		//eligo el vertice con la menor distancia entre los vertices no procesados
        int u = minDistance(dist, sptSet); 
  
        // marco tal vertice como procesado 
        sptSet[u] = true; 
  
		//actualizo la distancia de los demas vertices desde el vertice elegido
        for (int v = 0; v < this->tamanio; v++) 

			//actualizo el arreglo con las distancias si la nueva distancia es menor que la anterior
            if (!sptSet[v] && this->matriz[u][v] && dist[u] != infinito 
                && dist[u] + this->matriz[u][v] < dist[v]) 
                dist[v] = dist[u] + this->matriz[u][v]; 
    } 
  
	}
};

#endif /* GRAFO_H_ */
