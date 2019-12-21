#include "grafo.h"

Grafo::Grafo()
{
	primero = NULL;
	this->tamanio = 0;
	ultimo = NULL;
	this->matriz = NULL;
	this->index = 0;
}

bool Grafo ::estaVacio()
{
	return primero == NULL;
}

int Grafo ::verCantidadVertices()
{
	return this->tamanio;
}

Vertice *Grafo ::obtenerVertice(ui marca)
{
	Vertice *iterar = NULL;
	bool encontrado = false;
	iterar = primero;
	while (iterar != NULL && !encontrado)
	{
		encontrado = iterar->obtenerMarca() == marca;
		if (encontrado)
		{
			return iterar;
		}
		else
		{
			iterar = iterar->siguiente;
		}
	}
	return iterar;
}

/*devuelve el vertice considerando que 2 estaciones son iguales si tienen la misma
 * ubicacion geografica*/
Vertice *Grafo::getVertice(Estacion *parada)
{
	Vertice *iterar = NULL;
	bool encontrado = false;
	iterar = primero;
	while (iterar != NULL && !encontrado)
	{
		encontrado = iterar->parada == parada;

		iterar = iterar->siguiente;
	}
	return iterar;
}

/*pre: lista con todos los campos de una boca de subte que lee de un archivo
 * ej: campos boca subte 1-campos boca subte 2- etc
 * post:
 * para cada linea crea una estacion y la agrega a un vertice del grafo
 * */
void Grafo::cargarVertices(Lista<std::string> *registros, std::string tipoTransporte)
{
	/*no verifica si la estacion ya existe en el grafo, por ej una boca de subte
	 * siempre tiene su respectiva parte en otra calle con el mismo nombre pero en otro sentido de
	 * la linea o simplemente ingreso desde otra calle. Todas quedan cargadas*/
	registros->iniciarCursor();

	while (registros->avanzarCursor())
	{
		std::string infoEstacion = registros->obtenerCursor();

		Estacion *nuevaEstacion = new Estacion(infoEstacion, tipoTransporte);

		insertarVertice(nuevaEstacion, index);

		this->index++;
	}
}

void Grafo::verVertices()
{
	Vertice *auxiliar = this->primero;
	while (auxiliar != NULL)
	{
		Estacion *nuevaEstacion = auxiliar->parada;
		std::cout << nuevaEstacion->verUbicacionLatitud() << " | " << nuevaEstacion->verUbicacionLongitud()
				  << " | " << nuevaEstacion->verNombre() << " | " << nuevaEstacion->verLinea() << std::endl;
		auxiliar = auxiliar->siguiente;
	}
}
/*llamar solo cuando se tienen todos los vertices en el grafo*/
/*no usar este metodo*/
void Grafo::cargarAristas()
{
	Vertice *iterando = this->primero;

	/*toma un vertice y recorre hasta el final buscando adyacencias por distancia*/
	while (iterando != NULL)
	{
		Vertice *posibleAdyacente = this->primero;
		Coordenadas ubicacionIterada = iterando->parada->verUbicacion();
		/*toma un vertice y verifica si esta cerca del anterior, si lo esta inserta
		 * la arista correspondiente*/
		while (posibleAdyacente != NULL)
		{
			Coordenadas ubicacionadyacentePosible = posibleAdyacente->parada->verUbicacion();
			ui distancia = ubicacionadyacentePosible.distanciaMetros(ubicacionIterada);
			if (iterando->parada->verLinea() == posibleAdyacente->parada->verLinea() &&
				iterando != posibleAdyacente)
			{
				this->insertarArista(iterando, posibleAdyacente, distancia);
			}
			else
			{
				if (distancia < 500 && iterando != posibleAdyacente)
				{
					this->insertarArista(iterando, posibleAdyacente, distancia);
				}
			}

			posibleAdyacente = posibleAdyacente->siguiente;
		}
		iterando = iterando->siguiente;
	}
}

void Grafo::insertarVertice(Estacion *parada, ui index)
{
	Vertice *nuevo = new Vertice;
	nuevo->siguiente = NULL;
	nuevo->adyacente = NULL;
	nuevo->parada = parada;
	nuevo->index = index;
	if (estaVacio())
	{
		primero = nuevo;
		ultimo = nuevo;
	}
	else
	{

		ultimo->siguiente = nuevo;
		ultimo = nuevo;

		Vertice *posibleAdyacente = this->primero;
		Coordenadas ubicacionAgregada = nuevo->parada->verUbicacion();
		while (posibleAdyacente != NULL)
		{
			Coordenadas ubicacionAdyacentePosible = posibleAdyacente->parada->verUbicacion();
			if (posibleAdyacente->parada->verLinea() == nuevo->parada->verLinea() &&
				nuevo != posibleAdyacente)
			{
				ui distancia = ubicacionAdyacentePosible.distanciaMetros(ubicacionAgregada);

				this->insertarArista(posibleAdyacente, nuevo, distancia);
			}
			else
			{
				ui distancia = ubicacionAdyacentePosible.distanciaMetros(ubicacionAgregada);

				if (distancia < 500 && nuevo != posibleAdyacente)
				{
					this->insertarArista(posibleAdyacente, nuevo, distancia);
				}
			}
			posibleAdyacente = posibleAdyacente->siguiente;
		}
	}
	this->tamanio++;
}

void Grafo ::insertarArista(Vertice *origen, Vertice *destino, ui distancia)
{
	if (origen != destino && origen->obtenerDato()->verNombre() != destino->obtenerDato()->verNombre())
	{
		Arista *aristaNueva = new Arista;
		aristaNueva->distancia = distancia;
		aristaNueva->siguiente = NULL;
		aristaNueva->Adyacente = destino;
		origen->agregarArista(aristaNueva);
	}
}

/*sirve para imprimir el grafo graficamente como una lista de adyacencia*/
void Grafo ::ListaAdyacencia()
{

	Vertice *verticeAux;
	//Arista *aristaAux;
	std::list<Arista *> *aristasVertice;
	verticeAux = this->primero;
	while (verticeAux != NULL)
	{
		std::cout << verticeAux->parada->verNombre() << "|" << verticeAux->obtenerMarca() << "|"
				  << "-->";

		aristasVertice = verticeAux->obtenerAristas();
		std::list<Arista *>::iterator i;

		Arista *tempArista;

		for (i = aristasVertice->begin(); i != aristasVertice->end(); i++)
		{
			tempArista = *i;
			std::cout << tempArista->Adyacente->parada->verNombre() << "-->";
		}
		std::cout << std::endl;
		verticeAux = verticeAux->obtenerVerticeSig();
	}
}

/*metodo no revisado ni prbado con Estacion*/
void Grafo ::EliminarArista(Vertice *origen, Vertice *destino)
{

	int bandera = 0;
	Arista *actual, *anterior;
	actual = origen->adyacente;

	if (actual == NULL)
	{
		std::cout << "El vertice origen no tiene aristas" << std::endl;
	}
	else if (actual->Adyacente == destino)
	{
		origen->adyacente = actual->siguiente;
		delete (actual);
	}
	else
	{
		while (actual != NULL)
		{
			if (actual->Adyacente == destino)
			{

				bandera = 1;
				anterior->siguiente = actual->siguiente;
				delete (actual);
				break;
			}
			anterior = actual;
			actual = actual->siguiente;
		}

		if (bandera == 0)
		{
			std::cout << "Esos dos vertices no estan conectados" << std::endl;
		}
	}
}

void Grafo ::cargarMatriz()
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
		std::list<Arista *> *aristasVertice = nodo->obtenerAristas();
		std::list<Arista *>::iterator i;
		Arista *tempArista;

		for (i = aristasVertice->begin(); i != aristasVertice->end(); i++)
		{
			tempArista = *i;
			ui indice2 = tempArista->obtenerVerticeDestino()->obtenerMarca();
			this->matriz[indice][indice2] = tempArista->obtenerDistancia();
		}
		nodo = nodo->obtenerVerticeSig();
	}

}

int Grafo ::minDistance(int dist[], bool sptSet[])
{
	int min = infinito, min_index;

	for (ui v = 0; v < this->tamanio; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void Grafo ::dijkstra(Vertice *origen) //, Vertice* destino)
{

	int predecesor[this->tamanio];
	//arreglo donde va a estar la distancia desde origan a cada uno de los demás vertices del grafo
	int dist[this->tamanio];

	//arreglo donde se indice si cada vertice ya fue recorrido
	bool sptSet[this->tamanio];

	this->cargarMatriz();

	//inicializo los arreglos
	for (ui i = 0; i < this->tamanio; i++)
	{
		dist[i] = infinito, sptSet[i] = false;
	}
	//distancia del origen a si mismo es igual a cero
	dist[origen->obtenerMarca()] = 0;

	for (ui count = 0; count < this->tamanio - 1; count++)
	{
		//eligo el vertice con la menor distancia entre los vertices no procesados
		int u = minDistance(dist, sptSet);
		/**/
		// marco tal vertice como procesado
		sptSet[u] = true;

		//actualizo la distancia de los demas vertices desde el vertice elegido
		for (ui v = 0; v < this->tamanio; v++)
		{
			//actualizo el arreglo con las distancias si la nueva distancia es menor que la anterior
			if (!sptSet[v] && this->matriz[u][v] && dist[u] != infinito && dist[u] + this->matriz[u][v] < dist[v])
			{
				/*cargo el predecesor*/
				predecesor[v] = u;
				dist[v] = dist[u] + this->matriz[u][v];
			}
		}
	}

	imprimirRecorrido(dist, predecesor, origen);
}

void Grafo :: imprimirRecorrido(int * dist, int * predecesor, Vertice *origen){
	/*imprimo d con origen y destino*/
	for (ui i = 0; i < this->tamanio; i++)
	{
		if (dist[i] != infinito)
		{
			//std::cout<<dist[i]<<std::endl;
			Vertice *destino = this->obtenerVertice(i);
			ui marcaPredecesor = predecesor[i];
			Vertice *predecesor = this->obtenerVertice(marcaPredecesor);
			if (origen == predecesor)
			{
				std::cout << origen->obtenerDato()->verNombre() << "---" << destino->obtenerDato()->verNombre() << " |" << dist[i] << "m" << std::endl;
			}
			else
			{
				std::cout << origen->obtenerDato()->verNombre() << "---" << predecesor->obtenerDato()->verNombre() << "---" << destino->obtenerDato()->verNombre() << " |" << dist[i] << "m" << std::endl;
			}
		}
	}
}

Grafo ::~Grafo()
{

	/*borro vertices*/
	while (primero != NULL)
	{
		Vertice *aBorrar = primero;

		this->primero = aBorrar->siguiente;
		delete (aBorrar);
	}
	delete[] this->matriz;
}
