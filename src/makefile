all: proyecto_01 run

proyecto_01: bison flex pila keyword
	g++ pila.o keyword.o pylex.cpp pypar.cpp -o pylex

bison:
	bison -dv pypar.y -o pypar.cpp

flex:
	flex pylex.l

pila: pila.cpp
	g++ -c pila.cpp

keyword: keyword.cpp
	g++ -c keyword.cpp

clean:
	rm pylex pylex.cpp *.o

run:
	./pylex pyprueba1.py
