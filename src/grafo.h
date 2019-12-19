
#ifndef GRAFO_H_
#define GRAFO_H_

#include <iostream>
#include <string>
#include "Vertice.h"
#include <vector>

class Grafo {

	typedef unsigned int ui;

	Vertice *primero;
	Vertice* ultimo;
	ui tamanio;
	int ** matriz;

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

		void cargarMatriz() {
			long int infinito = 9999999;
			this->matriz = new int*[this->tamanio];
			
			for (int i = 0; i < this->tamanio; i++) {
    			this->matriz[i] = new int[this->tamanio];
			}

			for(ui i=0; i<this->tamanio; i++){
				for(ui j=0; j<this->tamanio; j++){
					this->matriz[i][j] = infinito; 
				}
			}

			Vertice * nodo = this->primero;
			ui indice=nodo->obtenerMarca();
			while(nodo!=NULL){
				Arista* aristaAdyacente=nodo->obtenerAristaAdyacente();
				while(aristaAdyacente!=NULL){
					ui indice2=aristaAdyacente->obtenerVerticeDestino()->obtenerMarca();
					this->matriz[indice][indice2]=aristaAdyacente->obtenerDistancia();
					aristaAdyacente=aristaAdyacente->obtenerAristaSig();
				}
				nodo=nodo->obtenerVerticeSig();
			}

		}

};



#endif /* GRAFO_H_ */
