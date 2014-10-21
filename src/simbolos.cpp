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
	virtual Elemento* lookup(string name)=0;
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
	Elemento* lookup(string name){
		for( it = vector_tablas.begin(); it != vector_tablas.end(); ++it) {
			unordered_map<string, Elemento> tabla = *it;
			unordered_map<string,Elemento>::iterator local_it = tabla.begin();
			for ( local_it = tabla.begin(); local_it!= tabla.end(); ++local_it ){
				if(local_it->first == name){
					Elemento temp = local_it->second;
					Elemento *aux = &temp;
					cout << "lo encontre";
					return aux;
				}
			}
      	}
		cout<< "CASO DE NULL";
		return NULL;		
	}

	/* funcion que inserta dentro de la tabla de simbolos del alcance actual un elemento*/
	virtual void insert(string name, Elemento record){
		vector_tablas.back().insert({name,record});
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
		vector_tablas.erase(vector_tablas.end());
		tabla_actual = vector_tablas.back();
	}

	/* Funcion que nos permite saber si name esta dentro del alcaance local, es decir el
	mas interno hasta el momento*/
	bool declaredLocally(string name){
		bool declarado = false;
		unordered_map<string,Elemento>  tabla = vector_tablas.back();
		unordered_map<string,Elemento>::iterator it;
		for(it = tabla.begin(); it!= tabla.end();++it){
			if(it->first == name){
				declarado = true;
			}
		}
		return declarado;
	}

	/*Funcion para imprimir la tabla, usada para las pruebas*/
	void print() {
		
		cout << "tam vector_tablas: " << vector_tablas.size() << endl;
		for( it = vector_tablas.begin(); it != vector_tablas.end(); ++it) {
			unordered_map<string, Elemento> for_print = *it;
			cout << "tam de un map: " << for_print.size() << endl;
			for ( auto local_it = for_print.begin(); local_it!= for_print.end(); ++local_it )
      			cout << " " << local_it->first;
      		cout << endl;
		}
		
	}
};

int main(){
	Simbolo *prueba = new Simbolo();
	prueba->openScope();
	struct Elemento test;
	test.alcance = 0;
	test.number = 10;
	prueba->insert("equis",test);
	prueba->insert("equis2", test);
	prueba->insert("equis3", test);
	prueba->insert("hola", test);
	
	cout <<prueba->declaredLocally("adios");
	cout <<prueba->declaredLocally("equis");
	cout <<"\n";
	prueba->openScope();
	prueba->insert("nuevo elemento", test);
	prueba->print();
	prueba->lookup("nombre");
	cout<< "\n";
	prueba->lookup("equis");
	cout<< "\n";
	prueba->closeScope();
	prueba->print();
	return 0;
}