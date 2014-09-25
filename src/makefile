all: proyecto_01 run

proyecto_01: flex pila keyword
	g++ pila.o keyword.o pylex.cpp -o pylex

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
