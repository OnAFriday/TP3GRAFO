
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
	Vertice* obtenerVertice(ui marca){
		Vertice *iterar=NULL;
		bool encontrado =false;
		iterar=primero;
		while (iterar != NULL&&!encontrado){
			encontrado=iterar->obtenerMarca() == marca;
			if(encontrado){
				return iterar;
			}
			else{
				iterar = iterar->siguiente;
			}
		}
		return iterar;
	}

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
/*
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
		}*/
		Vertice *nodo = this->primero;
		while (nodo != NULL){
			ui indice = nodo->obtenerMarca();
			std::list<Arista*>*aristasVertice=nodo->obtenerAristas();
			std::list<Arista*> ::iterator i;
			Arista* tempArista;

         for(i = aristasVertice->begin(); i != aristasVertice->end(); i++) {
	         tempArista = *i;
        	 ui indice2 = tempArista->obtenerVerticeDestino()->obtenerMarca();
			this->matriz[indice][indice2] = tempArista->obtenerDistancia();
			//std::cout<<tempArista->Adyacente->parada->verNombre() <<"-->";
	        }
			nodo = nodo->obtenerVerticeSig();
		}




/*

		 for(ui i=0; i<this->tamanio; i++){
		 	for(ui j=0; j<this->tamanio; j++){
		 			std::cout<<this->matriz[i][j]<< " | ";
		 	}
		 	std::cout<<std::endl;
		 }*/
		//std::cout << this->matriz[44][45] << " | ";
		Vertice* lasHeras=this->obtenerVertice(3);
		this->dijkstra(lasHeras);
	}

	//metodo auxiliar para encontrar el vertice con la minima distancia
	int minDistance(int dist[], bool sptSet[])
	{
		int min = infinito, min_index;

		for (ui v = 0; v < this->tamanio; v++)
			if (sptSet[v] == false && dist[v] <= min)
				min = dist[v], min_index = v;

		return min_index;
	}

	void dijkstra(Vertice *origen)
	{
		int predecesor[this->tamanio];
		//arreglo donde va a estar la distancia desde origan a cada uno de los demás vertices del grafo
		int dist[this->tamanio];

		//arreglo donde se indice si cada vertice ya fue recorrido
		bool sptSet[this->tamanio];

		//inicializo los arreglos
		for (ui i = 0; i < this->tamanio; i++){
			dist[i] = infinito, sptSet[i] = false;
		}
		//distancia del origen a si mismo es igual a cero
		dist[origen->obtenerMarca()] = 0;

		 for (ui count = 0; count < this->tamanio - 1; count++) {
		//eligo el vertice con la menor distancia entre los vertices no procesados
			 int u = minDistance(dist, sptSet);
        /**/
        // marco tal vertice como procesado
			 sptSet[u] = true;

  
		//actualizo la distancia de los demas vertices desde el vertice elegido
			 for (ui v = 0; v < this->tamanio; v++){

			//actualizo el arreglo con las distancias si la nueva distancia es menor que la anterior
				 if (!sptSet[v] && this->matriz[u][v] && dist[u] != infinito
						 && dist[u] + this->matriz[u][v] < dist[v]){
					 /*cargo el predecesor*/
					 predecesor[v]=u;
					 dist[v] = dist[u] + this->matriz[u][v];
				 }
			 }
		 }
		 /*imprimo d con origen y destino*/
		 for (ui i=0;i<this->tamanio;i++){
			 if(dist[i]!=infinito){
				 //std::cout<<dist[i]<<std::endl;
				 Vertice* destino=this->obtenerVertice(i);
				 ui marcaPredecesor=predecesor[i];
				 Vertice * predecesor=this->obtenerVertice(marcaPredecesor);
				 if(origen==predecesor){
					 std::cout<<origen->obtenerDato()->verNombre()<< "---"<<
							 destino->obtenerDato()->verNombre()<<" |"<<dist[i]<<"m"<<std::endl;
				 }else{
					 std::cout<<origen->obtenerDato()->verNombre()<<"---"<<
							 predecesor->obtenerDato()
					 ->verNombre()<< "---"<< destino->obtenerDato()->verNombre()<<" |"<<dist[i]<<"m"<<std::endl;
				 }
			 }
		 }
  

	}
};

#endif /* GRAFO_H_ */
