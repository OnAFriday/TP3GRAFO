/*
 * Ciudad.h
 *
 *  Created on: 14 oct. 2019
 *      Author: cristian
 */

#ifndef SRC_CIUDAD_H_
#define SRC_CIUDAD_H_
#define DISTANCIA_MAX 500

#include "Estacion.h"
#include "Archivo.h"
#include  "util.h"
#include "Coordenadas.h"
#include "grafo.h"

class Ciudad {

	private:
		Lista<Estacion*>*estacionesTren;
		Lista<Estacion*>*bocasSubte;
		Lista<Estacion*>*estacionesColectivo;
		Lista<Estacion*>paradasColectivoAux;
		Grafo* subtes;
		Grafo* paradasColectivo;
		Grafo *estacionesFerrocarril;

	private:


		void borrarDatos(Lista<Estacion*>* medioDeTransporte);


		void cargarAdyacentes();
	public:
		/*post: crea ciudad con datos de transportes de archivos csv
		 */
		Ciudad();


		const Lista<Estacion*>*verEstacionesTren(){
			return this->estacionesTren;
		}
		const Lista<Estacion*>* verBocasSubte(){
			return this->bocasSubte;
		}
		void verRecorridoConCombinacion(Coordenadas , Coordenadas j){

		};
		void verRecorridoDirecto(Coordenadas , Coordenadas j){

		}
		const Lista<Estacion*>* verColectivos(){
			return this->estacionesColectivo;
		}

		void cargarDatos (Lista<Estacion*> * medioDeTransporte, Lista<std::string> datos, std::string tipoDeTransporte);

		~Ciudad();
};

#endif /* SRC_CIUDAD_H_ */
