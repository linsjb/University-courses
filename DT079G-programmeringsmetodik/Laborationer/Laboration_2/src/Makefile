#variables
flags= -c -std=c++14
gcc= g++ $(flags)

output: main.o shape.o rectangle.o circle.o cylinder.o roundedRectangle.o parallelepiped.o
	g++ -std=c++14 -o output main.o shape.o rectangle.o circle.o cylinder.o roundedRectangle.o parallelepiped.o

main.o: main.cpp
	$(gcc) main.cpp

shape.o: shape.cpp
	$(gcc) shape.cpp

rectangle.o: rectangle.cpp
	$(gcc) rectangle.cpp

circle.o: circle.cpp
	$(gcc) circle.cpp

cylinder.o: cylinder.cpp
	$(gcc) cylinder.cpp

roundedRectangle.o: roundedRectangle.cpp
	$(gcc) roundedRectangle.cpp

parallelepiped.o: parallelepiped.cpp
	$(gcc) parallelepiped.cpp

run:
	@./output
