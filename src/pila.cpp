#include <vector>
#include <iostream>

#include "pila.h"

using namespace std;

//Funcion push para introducir un elemento a la pila
void Pila::push(int nuevo_elemento) {
	//Agregamos el elemento hasta el final
	pila.push_back(nuevo_elemento);
}

//Funcion pop para tomar el elemento del tope de la pila
int Pila::pop() {
	//Guardamos el elemento
	int resultado = pila.back();
	//Quitamos el elemento de la pila (por que es pop)
	pila.pop_back();
	//Regresamos el elemento
	return resultado;
}

//Funcion para ver, es decir no lo quita, el tope de la pila
int Pila::top() {
	//Guardamos el elemento
	int resultado = pila.back();
	//Regresamos el elemento
	return resultado;
}

//Funcion para imprimir la pila actual
void Pila::print() {
	//Iteramos desde el tamano de la pila hasta cero e imprimimos el elemento
	for (unsigned i = pila.size(); i-- > 0; ) {
		cout << pila.at(i) << "\n";
    }
}

//Funcion para conocer el tamano de la pila
int Pila::length() {
	//Nos apoyamos de la funcion size de los vectores para regresar el tamano de la pila
	return pila.size();
}