#variables
flags= -c -std=c++11 -O3
gcc= g++ $(flags)

output: main.o Alg_search.o
	g++ -std=c++11 -o output main.o Alg_search.o

main.o: main.cpp
	$(gcc) main.cpp

Alg_search.o: Alg_search.cpp
	$(gcc) Alg_search.cpp

run:
	@./output
