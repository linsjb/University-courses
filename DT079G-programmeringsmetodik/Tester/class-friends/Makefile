#variables
flags= -c -std=c++11
gcc= g++ $(flags)

output: main.o a.o b.o
	g++ -std=c++11 -o output main.o a.o b.o

main.o: main.cpp
	$(gcc) main.cpp

a.o: a.cpp
	$(gcc) a.cpp

b.o: b.cpp
	$(gcc) b.cpp


run:
	@./output
