all: proyecto_01 run

proyecto_01: flex pila
	g++ pila.o pylex.cpp -o pylex

pila: pila.cpp
	g++ -c pila.cpp

flex:
	flex pylex.l

clean: 
	rm pylex pylex.cpp pila.o

run:
	./pylex pyprueba1.py
