#include <iostream>
using namespace std;

class Simbolos
{

public:

/*Creacion de la estructura para cada uno de los elementos de la tabla de simbolos*/
	struct Elemento{
		char name[];
		char tipo[];
		/* Union para definir el valor de los elementos*/
		union {
			int number;
			char cadena[];
		};
	};

/*Declaracion de los metodo que tenemos que implementar*/
	virtual Elemento lookup(char buscado[])=0;
	virtual void insert(char name[], int record)=0;
	virtual void openScope()=0;
	virtual void closeScope()=0;
	virtual bool declaredLocally(char name[])=0;



};
int main(){
	return 0;
}