#include "grafo.h"

Grafo::Grafo(){
	primero = NULL;
	this->tamanio=0;
	ultimo=NULL;
	this->matriz=NULL;
	this->index=0;
}

bool Grafo :: estaVacio(){

	return primero==NULL;
}


int Grafo :: verCantidadVertices(){
	return this->tamanio;
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


/*pre: lista con todos los campos de una boca de subte que lee de un archivo
 * ej: campos boca subte 1-campos boca subte 2- etc
 * post:
 * para cada linea crea una estacion y la agrega a un vertice del grafo
 * */
void Grafo::cargarVertices(Lista<std::string>*registros, std::string tipoTransporte){
	/*no verifica si la estacion ya existe en el grafo, por ej una boca de subte
	 * siempre tiene su respectiva parte en otra calle con el mismo nombre pero en otro sentido de
	 * la linea o simplemente ingreso desde otra calle. Todas quedan cargadas*/
	registros->iniciarCursor();


	while(registros->avanzarCursor()) {
		std::string infoEstacion = registros->obtenerCursor();

		Estacion* nuevaEstacion = new Estacion (infoEstacion ,tipoTransporte);

		insertarVertice(nuevaEstacion, index);

		this->index++;
	}
}
void Grafo::verVertices(){
	Vertice *auxiliar=this->primero;
	while(auxiliar!=NULL){
		Estacion *nuevaEstacion=auxiliar->parada;
		std::cout<<nuevaEstacion->verUbicacionLatitud()<<" | "<<nuevaEstacion->verUbicacionLongitud()
							<<" | "<<nuevaEstacion->verNombre()<<" | "<<nuevaEstacion->verLinea()<<std::endl;
		auxiliar=auxiliar->siguiente;
	}
}
/*llamar solo cuando se tienen todos los vertices en el grafo*/
/*no usar este metodo*/
void Grafo::cargarAristas(){
	Vertice* iterando=this->primero;

	/*toma un vertice y recorre hasta el final buscando adyacencias por distancia*/
	while(iterando!=NULL){
		Vertice* posibleAdyacente=this->primero;
		Coordenadas ubicacionIterada=iterando->parada->verUbicacion();
		/*toma un vertice y verifica si esta cerca del anterior, si lo esta inserta
		 * la arista correspondiente*/
		while(posibleAdyacente!=NULL){
			Coordenadas ubicacionadyacentePosible=posibleAdyacente->parada->verUbicacion();
			ui distancia=ubicacionadyacentePosible.distanciaMetros(ubicacionIterada);
			if(iterando->parada->verLinea()==posibleAdyacente->parada->verLinea()&&
					iterando!=posibleAdyacente){
				this->insertarArista(iterando, posibleAdyacente, distancia);

			}
			else{
				if (distancia<500&&iterando!=posibleAdyacente){
					this->insertarArista(iterando, posibleAdyacente, distancia);
				}
			}

			posibleAdyacente=posibleAdyacente->siguiente;

		}
		iterando=iterando->siguiente;
	}
}
void Grafo::insertarVertice(Estacion *parada, ui index){
	Vertice *nuevo = new Vertice;
	nuevo->siguiente = NULL;
	nuevo->adyacente = NULL;
	nuevo->parada=parada;
	nuevo->index=index;
	if (estaVacio()){
		primero = nuevo;
		ultimo=nuevo;
	}
	else{

		ultimo->siguiente=nuevo;
		ultimo=nuevo;

		Vertice* posibleAdyacente=this->primero;
		Coordenadas ubicacionAgregada=nuevo->parada->verUbicacion();
		while(posibleAdyacente!=NULL){
			Coordenadas ubicacionAdyacentePosible=posibleAdyacente->parada->verUbicacion();
			if(posibleAdyacente->parada->verLinea()==nuevo->parada->verLinea()&&
					nuevo!=posibleAdyacente){
				ui distancia=ubicacionAdyacentePosible.distanciaMetros(ubicacionAgregada);

				this->insertarArista(posibleAdyacente, nuevo, distancia);

			}
			else{
				ui distancia=ubicacionAdyacentePosible.distanciaMetros(ubicacionAgregada);

				if (distancia<500&&nuevo!=posibleAdyacente){
					this->insertarArista(posibleAdyacente, nuevo, distancia);
				}
			}

			posibleAdyacente=posibleAdyacente->siguiente;

		}



	}
	this->tamanio++;
}


void Grafo :: insertarArista (Vertice *origen, Vertice *destino, ui distancia){
	if(origen!=destino&&origen->obtenerDato()->verNombre()!=destino->obtenerDato()->verNombre()){
		Arista  *aristaNueva= new Arista;
		aristaNueva->distancia = distancia;
		aristaNueva->siguiente = NULL;
		aristaNueva->Adyacente = destino;
		//Arista * adyacente;
		//adyacente = origen->adyacente;
		origen->agregarArista(aristaNueva);
		/*
		if(adyacente == NULL){
			origen->adyacente = aristaNueva;
		}
		else {
			while (adyacente != NULL){

				adyacente = adyacente->obtenerAristaSig();
			}
			adyacente = aristaNueva;
		}*/

	}

}



/*sirve para imprimir el grafo graficamente como una lista de adyacencia*/
void Grafo :: ListaAdyacencia(){

	Vertice *verticeAux;
	//Arista *aristaAux;
	std::list<Arista*>*aristasVertice;
	verticeAux = this->primero;
	while (verticeAux != NULL){
		std::cout<<verticeAux->parada->verNombre()<<"|"<<verticeAux->obtenerMarca()<<"|" <<"-->";

		aristasVertice=verticeAux->obtenerAristas();
		std::list<Arista*> ::iterator i;

         Arista* tempArista;

         for(i = aristasVertice->begin(); i != aristasVertice->end(); i++) {
            tempArista = *i;
			std::cout<<tempArista->Adyacente->parada->verNombre() <<"-->";
         }
        std::cout << std::endl;
 		verticeAux = verticeAux->obtenerVerticeSig();

	}




	/*
	verticeAux = this->primero;
	while (verticeAux != NULL){
		std::cout<<verticeAux->parada->verNombre()<<"|"<<verticeAux->obtenerMarca()<<"|" <<"-->";
		aristaAux = verticeAux->obtenerAristaAdyacente();
		while(aristaAux != NULL) {
			std::cout<<aristaAux->Adyacente->parada->verNombre() <<"-->";
			aristaAux = aristaAux->obtenerAristaSig();
		}
		verticeAux = verticeAux->obtenerVerticeSig();
		std::cout<<std::endl;
	}*/
}


/*metodo no revisado ni prbado con Estacion*/
void Grafo :: EliminarArista(Vertice *origen, Vertice *destino){

	int bandera = 0;
	Arista *actual, *anterior;
	actual = origen->adyacente;

	if (actual == NULL){
		std::cout<<"El vertice origen no tiene aristas" <<std::endl;
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
			std::cout<<"Esos dos vertices no estan conectados" <<std::endl;
		}
	}
}


Grafo :: ~Grafo(){

	/*borro vertices*/
	while(primero != NULL){
		Vertice *aBorrar=primero;

		this->primero=aBorrar->siguiente;
		delete(aBorrar);
	}
	delete []this->matriz;

}

