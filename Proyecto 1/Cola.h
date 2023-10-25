#pragma once
#include "Lista.h"
//Cola creada para almacenar una lista de canciones
ref class Cola {
private:
	Lista^ canciones;
public:
	Cola() {
		canciones = gcnew Lista(lista_cancion);
	}

	void queue(System::String^ nombre, System::String^ artista, System::String^ cd, int duración_segundos) {
		canciones->Add(nombre, artista, cd, duración_segundos);
	}

	void pop() {
		canciones->remove(0);
	}

	auto front() {
		return canciones->get(0);
	}

	void sort(ordenar_por orden, forma_ordenar forma) {
		canciones->quickSort(front(), canciones->get(canciones->Size() - 1), orden, forma);
	}

	void mostrar_cola(System::Windows::Forms::ListBox^ lb) {
		lb->Items->Clear();
		auto current = front();
		while (current) {
			auto current_canción = current->val_cancion;
			//Formatea la duración como un string
			int minutos = current_canción->obtener_duracion_segundos() / 60;
			int segundos = current_canción->obtener_duracion_segundos() % 60;
			std::string s = std::to_string(minutos) + ":";
			if (segundos < 10) s += "0";
			s += std::to_string(segundos);
			System::String^ duracion = gcnew System::String(s.c_str());
			System::String^ msg = gcnew System::String("Nombre: ") + current_canción->obtener_nombre()
				+ "; Artista: " + current_canción->obtener_artista() + "; Duración: " + duracion + "; cd: " 
				+ current_canción->obtener_cd();
			lb->Items->Add(msg);
			current = current->next;
		}
	}

	bool isEmpty() {
		return canciones->isEmpty();
	}
};