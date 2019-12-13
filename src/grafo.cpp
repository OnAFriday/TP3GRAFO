#include "grafo.h"

void Grafo :: Inicializar(){

	h = NULL;
}


bool Grafo :: Vacio(){

	return h==NULL;
}


int Grafo :: Tamanio(){

	int contador = 0;
	Vertice *aux;
	aux = h;
	while (aux != NULL){
		contador++;
		aux = aux->siguiente;
	}
	return contador;
}


Vertice *Grafo :: GetVertice (string nombre){
	Vertice *aux;
	aux=h;
	while (aux != NULL){
		if (aux->nombre == nombre){
			return aux;
		}
		aux = aux->siguiente;
	}
	return NULL;

}


void Grafo :: InsertaArista (Vertice *origen, Vertice *destino, int precio){

	Arista * nueva = new Arista;
	nueva->precio = precio;
	nueva->siguiente = NULL;
	nueva->Adyacente = NULL;

	Arista * aux;

	aux = origen->adyacente;
	if(aux == NULL){
		origen->adyacente = nueva;
		nueva->Adyacente = destino;
	}
	else {
		while (aux->siguiente != NULL){
			aux = aux->siguiente;
		}
		aux->siguiente = nueva;
		nueva->Adyacente = destino;
	}
}


void Grafo :: InsertaVertice(string nombre){

	Vertice *nuevo = new Vertice;
	nuevo->nombre = nombre;
	nuevo->siguiente = NULL;
	nuevo->adyacente = NULL;

	if (Vacio()){
		h = nuevo;
	}
	else{
		Vertice *aux;
		aux = h;
		while(aux->siguiente != NULL){
			aux = aux->siguiente;
		}
		aux->siguiente = nuevo;
	}
}


void Grafo :: ListaAdyacencia(){

	Vertice *verticeAux;
	Arista *aristaAux;

	verticeAux = h;
	while (verticeAux != NULL){
		cout<<verticeAux->nombre <<"-->";
		aristaAux = verticeAux->adyacente;
		while(aristaAux != NULL) {
			cout<<aristaAux->Adyacente->nombre <<"-->";
			aristaAux = aristaAux->siguiente;
		}
		verticeAux = verticeAux->siguiente;
		cout<<endl;
	}
}


void Grafo :: EliminarArista(Vertice *origen, Vertice *destino){

	int bandera = 0;
	Arista *actual, *anterior;
	actual = origen->adyacente;

	if (actual == NULL){
		cout<<"El vertice origen no tiene aristas" <<endl;
	}
	else if (actual->Adyacente == destino){
		origen->adyacente = actual->siguiente;
		delete(actual);
	}
	else {
		while(actual != NULL){
			if (actual->Adyacente == destino){

				bandera = 1;
				anterior->siguiente = actual->siguiente;
				delete(actual);
				break;
			}
			anterior = actual;
			actual = actual->siguiente;
		}

		if (bandera == 0){
			cout<<"Esos dos vertices no estan conectados" <<endl;
		}
	}
}


void Grafo :: Anular(){

	Vertice *aux;

	while(h != NULL){

		aux = h;
		h = h->siguiente;
		delete(aux);
	}
}

