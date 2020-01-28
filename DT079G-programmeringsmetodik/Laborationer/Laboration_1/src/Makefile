#variables
flags= -c -std=c++11

output: main.o int_buffer.o int_sorted.o
	g++ -std=c++11 -o output main.o int_buffer.o int_sorted.o

main.o: main.cpp
	g++ $(flags) main.cpp

int_buffer.o: int_buffer.cpp int_buffer.h
	g++ $(flags) int_buffer.cpp

int_sorted.o: int_sorted.cpp int_sorted.h
	g++ $(flags) int_sorted.cpp

clean:
	@echo Cleaning files
	rm *.o
	rm output
	rm a.out
	rm -rf a.out.dSYM

run:
	@./output
