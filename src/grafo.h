
#ifndef GRAFO_H_
#define GRAFO_H_

#include <iostream>
#include <string>
#include "Estacion.h"
using namespace std;


class Arista;


class Vertice{

	typedef unsigned int ui;
	Vertice *siguiente;
	Arista *adyacente;
	string nombre;
	Estacion* parada;
	friend class Grafo;
};


class Arista {
	typedef unsigned int ui;

	Arista *siguiente;
	Vertice *Adyacente;
	int distancia;
	friend class Grafo;
};

class Grafo {
	typedef unsigned int ui;

	Vertice *primero;
	public:
		Grafo();
		bool estaVacio();
		int Tamanio();

		Vertice *getVertice(Estacion *parada);
		void insertarVertice(Estacion *parada);
		void cargarVertices(Lista<std::string>*estaciones);
		void cargarAristas();
		/*de aca abajo metodos no probados*/
		void insertarArista (Vertice *origen, Vertice *destino, ui distancia);
		void ListaAdyacencia();
		void EliminarArista(Vertice *origen, Vertice *destino);
		~Grafo();
		void EliminarVertice(Vertice *vertice);
};



#endif /* GRAFO_H_ */
