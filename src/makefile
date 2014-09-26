all: proyecto_01 run

proyecto_01: bison flex pila keyword
	g++ pila.o keyword.o pylex_parser.o pylex.cpp -o pylex

bison:
	bison -dv pylex.y -o pylex_parser.cpp
	g++ -c pylex_parser.cpp

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
