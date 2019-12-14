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
/*pre: lista con todos los campos de una boca de subte que lee de un archivo
 * ej: campos boca subte 1-campos boca subte 2- etc
 * post:
 * para cada linea crea una estacion y la agrega a un vertice del grafo
 * */
void Grafo::cargarVertices(Lista<std::string>*bocas){
	/*no verifica si la estacion ya existe en el grafo, por ej una boca de subte
	 * siempre tiene su respectiva parte en otra calle con el mismo nombre pero en otro sentido de
	 * la linea o simplemente ingreso desde otra calle. Todas quedan cargadas*/
	bocas->iniciarCursor();

	while(bocas->avanzarCursor()) {
		std::string infoEstacion = bocas->obtenerCursor();
		Estacion* nuevaEstacion = new Estacion (infoEstacion);
		insertarVertice(nuevaEstacion);
	}
}
/*llamar solo cuando se tienen todos los vertices en el grafo*/
void Grafo::cargarAristas(){
	Vertice* iterando=this->primero;
	Vertice* posibleAdyacente=this->primero;
	/*toma un vertice y recorre hasta el final buscando adyacencias por distancia*/
	while(iterando!=NULL){
		Coordenadas ubicacionIterada=iterando->parada->verUbicacion();
		/*toma un vertice y verifica si esta cerca del anterior, si lo esta inserta
		 * la arista correspondiente*/
		while(posibleAdyacente!=NULL){
			Coordenadas ubicacionadyacentePosible=posibleAdyacente->parada->verUbicacion();
			ui distancia=ubicacionadyacentePosible.distanciaMetros(ubicacionIterada);
			if (distancia<500){
				this->insertarArista(iterando, posibleAdyacente, distancia);
			}
			posibleAdyacente=posibleAdyacente->siguiente;

		}
		iterando=iterando->siguiente;
	}

}
/*sirve para imprimir el grafo graficamente como una lista de adyacencia*/
void Grafo :: ListaAdyacencia(){

	Vertice *verticeAux;
	Arista *aristaAux;

	verticeAux = primero;
	while (verticeAux != NULL){
		cout<<verticeAux->parada->verNombre() <<"-->";
		aristaAux = verticeAux->adyacente;
		while(aristaAux != NULL) {
			cout<<aristaAux->Adyacente->parada->verNombre() <<"-->";
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

