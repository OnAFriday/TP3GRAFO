#include "grafo.h"

Grafo::Grafo(){

	primero = NULL;
}


bool Grafo :: estaVacio(){

	return primero==NULL;
}


int Grafo :: Tamanio(){

	int contador = 0;
	Vertice *aux;
	aux = primero;
	while (aux != NULL){
		contador++;
		aux = aux->siguiente;
	}
	return contador;
}



/*devuelve el vertice considerando que 2 estaciones son iguales si tienen la misma
 * ubicacion geografica*/
Vertice *Grafo::getVertice(Estacion *parada){
	Vertice *iterar=NULL;
	bool encontrado =false;
	iterar=primero;
	while (iterar != NULL&&!encontrado){
		encontrado=iterar->parada == parada;

		iterar = iterar->siguiente;
	}
	return iterar;
}


void Grafo :: insertarArista (Vertice *origen, Vertice *destino, ui distancia){

	Arista * aristaNueva = new Arista;
	aristaNueva->distancia = distancia;
	aristaNueva->siguiente = NULL;
	aristaNueva->Adyacente = NULL;

	Arista * aux;

	aux = origen->adyacente;
	if(aux == NULL){
		origen->adyacente = aristaNueva;
		aristaNueva->Adyacente = destino;
	}
	else {
		while (aux->siguiente != NULL){
			aux = aux->siguiente;
		}
		aux->siguiente = aristaNueva;
		aristaNueva->Adyacente = destino;
	}
}
void Grafo::insertarVertice(Estacion *parada){
	Vertice *nuevo = new Vertice;
	nuevo->siguiente = NULL;
	nuevo->adyacente = NULL;
	nuevo->parada=parada;
	if (estaVacio()){
		primero = nuevo;
	}
	else{
		Vertice *aux;
		aux = primero;
		while(aux->siguiente != NULL){
			aux = aux->siguiente;
		}
		aux->siguiente = nuevo;
	}
}



void Grafo :: ListaAdyacencia(){

	Vertice *verticeAux;
	Arista *aristaAux;

	verticeAux = primero;
	while (verticeAux != NULL){
		cout<<verticeAux->parada->verNombre() <<"-->";
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


Grafo :: ~Grafo(){

	Vertice *aux;

	while(primero != NULL){

		aux = primero;
		primero = primero->siguiente;
		delete(aux);
	}
}

