#include <vector>
using namespace std;

class Pila {
	private:
		//Vector que contiene a los elementos de la pila
		vector<int> pila;
  	public:
  		//Funcion push para introducir un elemento a la pila
  		void push(int);

  		//Funcion pop para tomar el elemento del tope de la pila
  		int pop();

  		//Funcion para imprimir la pila actual
  		void print();

  		//Funcion para conocer el tamano de la pila
  		int length();
};