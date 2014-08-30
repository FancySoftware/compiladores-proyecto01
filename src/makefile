all: proyecto_01

proyecto_01: flex
	g++ pylex.cpp -o pylex

flex:
	flex pylex.l

clean: 
	rm pylex pylex.cpp