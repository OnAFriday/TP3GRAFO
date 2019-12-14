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

		void verRedSubte();
		void verRecorridoConCombinacion(Coordenadas , Coordenadas j){

		};
		void verRecorridoDirecto(Coordenadas , Coordenadas j){

		}


		~Ciudad();
};

#endif /* SRC_CIUDAD_H_ */
