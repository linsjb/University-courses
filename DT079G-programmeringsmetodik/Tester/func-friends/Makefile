#variables
flags= -c -std=c++11
gcc= g++ $(flags)

output: main.o house.o
	g++ -std=c++11 -o output main.o house.o

main.o: main.cpp
	$(gcc) main.cpp

house.o: house.cpp
	$(gcc) house.cpp

run:
	@./output
