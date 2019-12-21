/*
 * Menu.cpp
 *
 *  Created on: 29 oct. 2019
 *      Author: David
 */
#include<iostream>
#include"Menu.h"
#include "Coordenadas.h"
#include <string>
using namespace std;


Menu::Menu(){
	miCiudad = new Ciudad();
}

void Menu::iniciarMenu(){

	string auxLatitudOrigen,auxLatitudDestino,auxLongitudOrigen,auxLongitudDestino;
	char opcionMenu ;
	bool salir = false;
	cout<<""<<endl;
	cout<<"   -- CIUDAD DIGITAL EN MOVIMIENTO V1.0 --"<<endl;
	cout<<""<<endl;

	while(!salir){
		cout <<""<<endl;
		cout<<"PUNTO DE ORIGEN"<<endl;
		cout<<"   Ingrese latitud de origen: ";
		cin>>auxLatitudOrigen;
		cout<<"   Ingrese longitud de origen: ";
		cin>>auxLongitudOrigen;
		cout<<"PUNTO DE DESTINO"<<endl;
		cout<<"   Ingrese latitud de destino: ";
		cin>>auxLatitudDestino;
		cout<<"   Ingrese longitud de destino: ";
		cin>>auxLongitudDestino;

		Coordenadas origen(auxLongitudOrigen, auxLatitudOrigen);
		Coordenadas destino(auxLongitudDestino, auxLatitudDestino);

		this->miCiudad->verRecorridoConCombinacion(origen,destino);


		cout <<"PARA BUSCAR OTRO RECORRIDO INGRESE 'S', DE LO CONTRARIO INGRESE 'N' "<<endl;
		cin>>opcionMenu;

		if(opcionMenu == 'N' || opcionMenu == 'n'){
			salir = true;
		}


	}
}

Menu::~Menu(){
	delete this->miCiudad;
}



