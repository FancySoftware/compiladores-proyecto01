all: proyecto_01

proyecto_01: bison flex pila keyword
	g++ -std=c++0x pila.o keyword.o pylex.cpp patrones.cpp nodo.cpp pypar.cpp -o pylex

bison:
	bison -dv pypar.y -o pypar.cpp

flex:
	flex pylex.l

pila: pila.cpp
	g++ -std=c++0x -c pila.cpp

keyword: keyword.cpp
	g++ -std=c++0x -c keyword.cpp

clean:
	rm pylex pylex.cpp *.o

run:
	./pylex pyprueba1.py
