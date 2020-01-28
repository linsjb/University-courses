#variables
flags= -c -std=c++11
gcc= g++-8 $(flags)

output: main.o
	g++-8 -std=c++14 -o output main.o

main.o: main.cpp
	$(gcc) main.cpp

run:
	@./output
