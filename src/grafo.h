
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
			int incidencias [this->tamanio][this->tamanio];
			/*unsigned int distanciaMax=100000000000;
			for(ui i=0; i<this->tamanio; i++){
				Vertice * posibleAdyacente = this->primero;

				for(ui j=0; j<this->tamanio; j++){

				}
			}*/

			Vertice * nodo = this->primero;
			ui indice=nodo->obtenerMarca();
			while(nodo!=NULL){
				Arista* aristaAdyacente=nodo->obtenerAristaAdyacente();
				while(aristaAdyacente!=NULL){
					ui indice2=aristaAdyacente->obtenerVerticeDestino()->obtenerMarca();
					incidencias[indice][indice2]=aristaAdyacente->obtenerDistancia();
					aristaAdyacente=aristaAdyacente->obtenerAristaSig();
				}
				nodo=nodo->obtenerVerticeSig();
			}

		}

};



#endif /* GRAFO_H_ */
