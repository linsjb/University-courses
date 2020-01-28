#variables
flags= -c -std=c++11
gcc= g++ $(flags)

output: main.o data_generation.o Sorting.o
	g++ -std=c++11 -o output main.o data_generation.o Sorting.o

main.o: main.cpp
	$(gcc) main.cpp

data_generation.o: data_generation.cpp
	$(gcc) data_generation.cpp

Sorting.o: Sorting.cpp
	$(gcc) Sorting.cpp

run:
	@./output
