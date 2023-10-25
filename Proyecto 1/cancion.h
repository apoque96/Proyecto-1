#pragma once
#include <iostream>
#include <string>
#include <msclr\marshal_cppstd.h>
#include "Lista.h"

enum forma_ordenar {
	ascendente = 0,
	descendente = 1
};

enum ordenar_por {
	nombre = 0,
	artista = 1,
	duracion = 2
};

ref class cancion {
private:
	System::String^ nombre;
	System::String^ artista;
	System::String^ cd;
	int duracion_segundos;
public:
	//Constructor de la clase
	cancion(System::String^ nombre, System::String^ artista, System::String^ cd, int duracion_segundos): 
		nombre(nombre), artista(artista), cd(cd), duracion_segundos(duracion_segundos) {}
#pragma region Funciones que retornan valores privados

	System::String^ obtener_nombre() {
		return nombre;
	}

	System::String^ obtener_artista() {
		return artista;
	}

	System::String^ obtener_cd() {
		return cd;
	}

	int obtener_duracion_segundos() {
		return duracion_segundos;
	}

	bool comparar(cancion^ c, ordenar_por orden, forma_ordenar forma) {
		msclr::interop::marshal_context context;
		std::string a;
		std::string b;
		switch (orden)
		{
		case ordenar_por::nombre:
			a = context.marshal_as<std::string>(nombre);
			b = context.marshal_as<std::string>(c->nombre);
			if (forma == ascendente)
				return a.compare(b) > 0 ? true : false;
			return a.compare(b) > 0 ? false : true;
			break;
		case ordenar_por::artista:
			a = context.marshal_as<std::string>(artista);
			b = context.marshal_as<std::string>(c->artista);
			if (forma == ascendente)
				return a.compare(b) > 0 ? true : false;
			return a.compare(b) > 0 ? false : true;
			break;
		case ordenar_por::duracion:
			return forma == ascendente ? duracion_segundos > c->duracion_segundos :
			duracion_segundos <= c->duracion_segundos;
			break;
		}
	}

	void swap(cancion^ c) {
		System::String^ nombre_temp = nombre;
		System::String^ artista_temp = artista;
		System::String^ cd_temp = cd;
		int duración_temp = duracion_segundos;

		nombre = c->nombre;
		artista = c->artista;
		cd = c->cd;
		duracion_segundos = c->duracion_segundos;

		c->nombre = nombre_temp;
		c->artista = artista_temp;
		c->cd = cd_temp;
		c->duracion_segundos = duración_temp;
	}
#pragma endregion
};
#pragma once
