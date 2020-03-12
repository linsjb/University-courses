#variables
flags= -c -std=c++11
gcc= g++-8 $(flags)

output: main.o object.o
	g++-8 -std=c++11 -o output main.o object.o

main.o: main.cpp
	$(gcc) main.cpp

object.o: object.cpp
	$(gcc) object.cpp

run:
	@./output
