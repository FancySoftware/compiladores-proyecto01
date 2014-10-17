#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Simbolos
{

public:

/*Creacion de la estructura para cada uno de los elementos de la tabla de simbolos*/
	struct Elemento{
		int alcance;
		string nombre;
		string tipo;
		/* Union para definir el valor de los elementos*/
		union {
			int number;
			char cadena[];
		};
	};

/*Declaracion de los metodo que tenemos que implementar*/
	virtual Elemento lookup(string name)=0;
	virtual void insert(string name, Elemento record)=0;
	virtual void openScope()=0;
	virtual void closeScope()=0;
	virtual bool declaredLocally(string name)=0;

};

class Simbolo: public Simbolos{

	vector<unordered_map<string,Elemento>> vector_tablas;
	int alcance_actual;
	unordered_map<string, Elemento> tabla_actual;


	/* Funcion para buscar un elemento en la tabla de simbolos*/
	Elemento lookup(string name){
		for (int i =alcance_actual-1; i>=0;i--){
			unordered_map<string, Elemento>	tabla_aux = vector_tablas[i];
			unordered_map<string,Elemento>::const_iterator iter = tabla_aux.find(name); 
			if(iter != tabla_aux.end()){
				return iter->second;
			}
		}
	}
	
	/* Funcion para abrir un nuevo alcance en la tabla de simbolos */
	void openScope(){
		alcance_actual +=1;
		unordered_map<string,Elemento> tabla_nva;
		tabla_actual = tabla_nva;
	}

	/* Funcion que nos permite saber si name esta dentro del alcaance local, es decir el 
	mas interno hasta el momento*/
	bool declaredLocally(string name){
		bool declarado = true;
		unordered_map<string,Elemento>::const_iterator iter = tabla_actual.find(name);
		Elemento temp = iter->second;
		if(temp.alcance != alcance_actual || iter == tabla_actual.end()){
			declarado = false;
		}
		return declarado;
	}

	/* Cierra el alcance actual referido a la tabla de simbolos, regresa a un alcance exterior*/
	void closeScope(){
		alcance_actual -= 1;
	}
};



int main(){
	return 0;
}