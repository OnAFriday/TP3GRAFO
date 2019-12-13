
#ifndef GRAFO_H_
#define GRAFO_H_

#include <iostream>
#include <string>
using namespace std;


class Arista;


class Vertice{

	Vertice *siguiente;
	Arista *adyacente;
	string nombre;
	friend class Grafo;
};


class Arista {

	Arista *siguiente;
	Vertice *Adyacente;
	int precio;
	friend class Grafo;
};

class Grafo {

	Vertice *h;
	public:
		void Inicializar();
		bool Vacio();
		int Tamanio(); // numero de vertices del grafo
		Vertice *GetVertice (string nombre); // devuelve la direccion del vertice de este nombre
		void InsertaArista (Vertice *origen, Vertice *destino, int precio);
		void InsertaVertice(string nombre);
		void ListaAdyacencia();
		void EliminarArista(Vertice *origen, Vertice *destino);
		void Anular();
		void EliminarVertice(Vertice *vertice);
};



#endif /* GRAFO_H_ */
