/*
 * Estacion.h
 *
 *  Created on: 14 oct. 2019
 *      Author: cristian
 */

#ifndef SRC_ESTACION_H_
#define SRC_ESTACION_H_

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Coordenadas.h"
#include "Lista.h"
#include <vector>
class Estacion {
	private:
		std::string linea;
		std::string tipoTransporte; 
		std::string nombre;

		//Lista<Estacion*>*adyacentes;
		Coordenadas * ubicacion;

		void leerInformacionSubte(std::string informacion);
		void leerInformacionFerrocarril(std::string informacion);
		void leerInformacionColectivo(std::string informacion);

	public:

		Estacion(std::string informacionEstacion, std::string tipoTransporte);
		Estacion (std::string informacionBocaSubte);
		Coordenadas verUbicacion(){
			return (*ubicacion);
		}
		std::string verTipoTransporte(){
			return this->tipoTransporte;
		}
        float verUbicacionLatitud(){
        	return this->ubicacion->verLatitud();
        }

		float verUbicacionLongitud(){
        	return this->ubicacion->verLongitud();
        }


		bool operator !=(Estacion* aComparar){
			return (aComparar->verUbicacion()!=(*ubicacion))&&(this->nombre!=aComparar->nombre);
		}
		std::string verLinea(){
			return this->linea;
		}

		std::string verNombre(){
			return this->nombre;
		}
		bool operator ==(Estacion* aComparar){
			return *ubicacion==aComparar->verUbicacion();
		}

		~Estacion(){
			delete this->ubicacion;

	}
};

#endif /* SRC_ESTACION_H_ */
