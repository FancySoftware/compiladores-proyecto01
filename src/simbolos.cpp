#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

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

class Simbolos
{

public:

/*Declaracion de los metodo que tenemos que implementar*/
	virtual Elemento lookup(string name)=0;
	virtual void insert(string name, Elemento record)=0;
	virtual void openScope()=0;
	virtual void closeScope()=0;
	virtual bool declaredLocally(string name)=0;
	virtual void print()=0;

};

class Simbolo: public Simbolos{
public:
	vector<unordered_map<string,Elemento>> vector_tablas;
	vector<unordered_map<string,Elemento>>::iterator it;

	int alcance_actual;
	unordered_map<string, Elemento> tabla_actual;

	Simbolo() {
		alcance_actual = 0;
	}

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

	/* funcion que inserta dentro de la tabla de simbolos del alcance actual un elemento*/
	virtual void insert(string name, Elemento record){
		//if(!declaredLocally(name)){
			tabla_actual.insert({name,record});
		//}
	}

	/* Funcion para abrir un nuevo alcance en la tabla de simbolos */
	void openScope(){
		alcance_actual +=1;
		unordered_map<string,Elemento> tabla_nva;
		tabla_actual = tabla_nva;
		// Agregamos la nueva tabla del alcance a nuestro vector de tablas
		it = vector_tablas.begin();
		vector_tablas.push_back(tabla_nva);
	}

	/* Cierra el alcance actual referido a la tabla de simbolos, regresa a un alcance exterior*/
	void closeScope(){
		alcance_actual -= 1;
		tabla_actual = vector_tablas[alcance_actual];
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

	/*Funcion para imprimir la tabla, usada para las pruebas*/
	void print() {
		/*for( it = vector_tablas.begin(); it != vector_tablas.end(); ++it) {
			unordered_map<string, Elemento> for_print = *it;
			for ( auto local_it = for_print.begin(); local_it!= for_print.end(); ++local_it )
      			cout << " " << local_it->first << ":" << local_it->second;
      		cout << endl;
		}*/
	}
};

int main(){
	Simbolo *prueba = new Simbolo();
	prueba->openScope();
	struct Elemento test;
	test.alcance = 0;
	test.nombre = "equis";
	test.tipo = "int";
	test.number = 10;
	prueba->insert("equis",test);
	//prueba->print();
	return 0;
}