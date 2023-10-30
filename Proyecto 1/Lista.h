#pragma once
#include "cancion.h"

enum tipo_de_lista {
	lista_cd = 0,
	lista_cancion = 1
};

ref class Lista {
public:
	//Está clase estaba antes en su propio header file, pero me estaba dando problemas así que mejor lo deje aquí :P
	ref class Cd {
	private:
		System::String^ nombre;
		Lista^ canciones;
	public:
		Cd(System::String^ nombre, Lista^ canciones) : nombre(nombre), canciones(canciones) {}
		System::String^ get_nombre() {
			return nombre;
		}

		Lista^ get_canciones() {
			return canciones;
		}
	};

	ref struct Node {
		//Variables del nodo
		Node^ next;
		Node^ prev;
		cancion^ val_cancion;
		Cd^ val_cd;

		//Constructor del nodo para las listas de canciones
		Node(System::String^ nombre, System::String^ artista, System::String^ cd, int duracion_segundos) :
			next(nullptr), prev(nullptr), val_cd(nullptr)
		{
			val_cancion = gcnew cancion(nombre, artista, cd, duracion_segundos);
		}
		//Constructor del nodo para las listas de cd
		Node(System::String^ nombre, Lista^ canciones) :
			next(nullptr), prev(nullptr), val_cancion(nullptr)
		{
			val_cd = gcnew Cd(nombre, canciones);
		}
	};

	//Variables de la lista
	Node^ head;
	Node^ tail;
	int size;
	const tipo_de_lista tipo;

	//Constructor de la lista
	Lista(tipo_de_lista tipo): size(0), tipo(tipo){}

	//Copy constructor
	Lista(Lista^ l): size(l->size), tipo(l->tipo), head(l->head), tail(l->tail) {}

	//Añade un nodo canción al final de la lista
	void Add(System::String^ nombre, System::String^ artista, System::String^ cd, int duracion_segundos) {
		if (tipo == lista_cd) return;
		size++;
		if (!head) {
			//Se ejecuta en caso de que la lista está vacia
			head = gcnew Node(nombre, artista, cd, duracion_segundos);
			tail = head;
			return;
		}
		tail->next = gcnew Node(nombre, artista, cd, duracion_segundos);
		tail->next->prev = tail;
		tail = tail->next;
	}
	//Añade un nodo cd al final de la lista
	void Add(System::String^ nombre, Lista^ canciones) {
		if (tipo == lista_cancion) return;
		size++;
		if (!head) {
			//Se ejecuta en caso de que la lista está vacia
			head = gcnew Node(nombre, canciones);
			tail = head;
			return;
		}
		tail->next = gcnew Node(nombre, canciones);
		tail->next->prev = tail;
		tail = tail->next;
	}

	//Regresa la cantidad de nodos en la lista
	int Size() {
		return size;
	}

	//Retorna el nodo en el indice indicado, si el indice está fuera del rango retorna nullptr 
	Node^ get(int index) {
		if (index < 0) return nullptr;
		Node^ current = head;
		for (int i = 0; i < index && current; i++) {
			current = current->next;
		}
		return current;
	}

	//Elimina un nodo de la lista
	void remove(int index) {
		//Si el indice está fuera de rango, no hace nada
		if (index < 0 || index >= size) return;
		Node^ node_to_delete;
		//Elimina la cabeza
		if (index == 0) {
			node_to_delete = head;
			head = head->next;
			head->prev = nullptr;
			if (!head) tail = nullptr;
			size--;
			delete node_to_delete;
			return;
		}
		//Elimina la cola
		if (index == size - 1) {
			node_to_delete = tail;
			tail = tail->prev;
			tail->next = nullptr;
			size--;
			delete node_to_delete;
			return;
		}
		size--;
		//Traversas la lista hasta un nodo anterior al nodo a eliminar
		Node^ current = head;
		for (int i = 0; i < index - 1; i++) {
			current = current->next;
		}
		node_to_delete = current->next;
		current->next = node_to_delete->next;
		node_to_delete->next->prev = current;
		//Elimina el nodo indicado
		delete node_to_delete;
	}

	bool isEmpty() {
		return size == 0;
	}
#pragma region Sort
	Node^ partition(Node^ low, Node^ high, ordenar_por orden, forma_ordenar forma) {
		cancion^ pivot = high->val_cancion;
		Node^ i = low->prev;
		for (Node^ j = low; j != high; j = j->next) {
			if (pivot->comparar(j->val_cancion, orden, forma)) {
				if (i) i = i->next;
				else i = low;
				i->val_cancion->swap(j->val_cancion);
			}
		}
		if (i) i = i->next;
		else i = low;
		i->val_cancion->swap(high->val_cancion);
		return i;
	}

	void quickSort(Node^ low, Node^ high, ordenar_por orden, forma_ordenar forma) {
		if (high != nullptr && low != high && low != high->next) {
			Node^ pivot = partition(low, high, orden, forma);
			quickSort(low, pivot->prev, orden, forma);
			quickSort(pivot->next, high, orden, forma);
		}
	}
#pragma endregion

};