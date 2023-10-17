#pragma once
#include <iostream>
#include <string>
#include <msclr\marshal_cppstd.h>

ref class cancion {
private:
	System::String^ nombre;
	System::String^ artista;
	System::String^ cd;
	int duracion_segundos;
public:
	//Constructor de la clase
	cancion(System::String^ nombre, System::String^ artista, System::String^ cd, int duración_segundos): 
		nombre(nombre), artista(artista), cd(cd), duracion_segundos(duracion_segundos) {}
#pragma region Funciones que retornan valores privados

	std::string obtener_nombre() {
		msclr::interop::marshal_context context;
		return context.marshal_as<std::string>(nombre);
	}

	std::string obtener_artista() {
		msclr::interop::marshal_context context;
		return context.marshal_as<std::string>(artista);
	}

	int obtener_duracion_segundos() {
		return duracion_segundos;
	}
#pragma endregion
};
#pragma once
