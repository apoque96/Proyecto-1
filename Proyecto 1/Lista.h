#include "cancion.h"

class Lista {
private:
	struct  Node
	{
		cancion^ 
	};
	bool ordenada;
	int size;
public:
	//Constructor que indica si la lista es ordenada o no ordenada
	Lista(bool ordenar): size(0), ordenada(ordenar){}

	//Añade elementos a la lista de forma que la lista quede ordenada o al final según se indique
	void Añadir() {

	}

	int size() {
		return size;
	}
};

#pragma once
