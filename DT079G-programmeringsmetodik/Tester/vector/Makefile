#variables
flags= -c -std=c++11
gcc= g++ $(flags)

output: main.o
	g++ -std=c++11 -o output main.o

main.o: main.cpp
	$(gcc) main.cpp

run:
	@./output
