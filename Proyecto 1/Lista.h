#include "cancion.h"
#include "Cd.h"

enum tipo_de_lista {
	lista_cd = 0,
	lista_cancion = 1
};

ref class Lista {
private:

	ref struct Node {
		//Variables del nodo
		Node^ next;
		Node^ prev;
		cancion^ val_cancion;
		Cd^ val_cd;

		//Constructor del nodo para las listas de canciones
		Node(System::String^ nombre, System::String^ artista, System::String^ cd, int duracion_segundos):
			next(nullptr), prev(nullptr), val_cd(nullptr)
		{
			val_cancion = gcnew cancion(nombre, artista, cd, duracion_segundos);
		}
		//Constructor del nodo para las listas de cd
		Node(System::String^ nombre) :
			next(nullptr), prev(nullptr), val_cancion(nullptr)
		{
			val_cd = gcnew Cd(nombre);
		}
	};
	//Variables de la lista
	Node^ head;
	Node^ tail;
	int size;
	const tipo_de_lista tipo;
public:
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
	void Add(System::String^ nombre) {
		if (tipo == lista_cancion) return;
		size++;
		if (!head) {
			//Se ejecuta en caso de que la lista está vacia
			head = gcnew Node(nombre);
			tail = head;
			return;
		}
		tail->next = gcnew Node(nombre);
		tail->next->prev = tail;
		tail = tail->next;
	}

	//Añade un nodo canción en el indice indicado, sin importar que el indice no este en el rango
	void Add(System::String^ nombre, System::String^ artista, System::String^ cd, int duracion_segundos, int index) {
		if (tipo == lista_cd) return;
		size++;
		if (!head) {
			//Se ejecuta en caso de que la lista está vacia
			head = gcnew Node(nombre, artista, cd, duracion_segundos);
			tail = head;
			return;
		}
		//Traversa la lista
		Node^ current = head;
		for (int i = 0; i < index && current->next; i++) {
			current = current->next;
		}
		//Añade el nodo
		current->next = gcnew Node(nombre, artista, cd, duracion_segundos);
		current->next->prev = current;
		//En caso de añadir al final de la lista, cambia la cola al nodo añadido
		if (current == tail) tail = tail->next;
	}

	//Añade un nodo cd en el indice indicado, sin importar que el indice no este en el rango
	void Add(System::String^ nombre, int index) {
		if (tipo == lista_cancion) return;
		size++;
		if (!head) {
			//Se ejecuta en caso de que la lista está vacia
			head = gcnew Node(nombre);
			tail = head;
			return;
		}
		//Traversa la lista
		Node^ current = head;
		for (int i = 0; i < index && current->next; i++) {
			current = current->next;
		}
		//Añade el nodo
		current->next = gcnew Node(nombre);
		current->next->prev = current;
		//En caso de añadir al final de la lista, cambia la cola al nodo añadido
		if (current == tail) tail = tail->next;
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
	Node^ remove(int index) {
		//Si el indice está fuera de rango, no hace nada
		if (index < 0 || index >= size) return nullptr;
		Node^ node_to_delete;
		//Elimina la cabeza
		if (index == 0) {
			node_to_delete = head;
			head = head->next;
			head->prev = nullptr;
			if (!head) tail = nullptr;
			size--;
			return node_to_delete;
		}
		//Elimina la cola
		if (index == size - 1) {
			node_to_delete = tail;
			tail = tail->prev;
			tail->next = nullptr;
			size--;
			return node_to_delete;
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
		//Quita los punteros en el nodo eliminado
		//El garbage collector de cli se hara cargo de limpiar la memoria 
		node_to_delete->prev = nullptr;
		node_to_delete->next = nullptr;
		//Retorna el nodo eliminado por si se desea acceder al valor o agregarlo a otra lista
		return node_to_delete;
	}

	bool isEmpty() {
		return size == 0;
	}
};

#pragma once
