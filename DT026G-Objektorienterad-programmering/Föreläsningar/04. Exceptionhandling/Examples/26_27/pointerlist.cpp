#include <iostream>
#include <exception>
#include <typeinfo>
using namespace std;

void createList(int* &Array, int Size);
int getUserInput( );

int main() 
{
	int* Array=0, Dimension=0;
	try {
			createList(Array, Dimension);
	}

	catch (int e) {
			cerr << "Cannot allocate: " << e << endl;
	return -1;
	}

	catch (bad_alloc b)   //The re-thrown exception willl be catched here!
	{
		cerr << "Allocation failed" << endl;
		return -1;
	}
return 0;	
}
void createList( int*& Array, int Size)  { //Array is a  referece to a pointer
	Size = getUserInput();
	try {
		Array = new int[Size];
	}
	catch (bad_alloc b) {         // you can catch an exception
		throw(b);                  // and re-throw it
	}#include <iostream>
#include <exception>
#include <typeinfo>
using namespace std;

void createList(int* &Array, int Size);
int getUserInput();

int main()
{
	int* Array = 0, Dimension = 0;
	try {
		createList(Array, Dimension);
	}

	catch (int e) {
		cerr << "Cannot allocate: " << e << endl;
		return -1;
	}

	catch (bad_alloc b)   //The re-thrown exception will be cached here!
	{
		cerr << "Allocation failed" << endl;
		return -1;
	}
	return 0;
}
void createList(int*& Array, int Size)  { //Array is a  reference to a pointer
	Size = getUserInput();
	try {
		Array = new int[Size];
	}
	catch (bad_alloc b) {         // you can catch an exception
		throw(b);                  // and re-throw it
	}
}

int getUserInput()  //This function can throw any kind of exception!
{
	int Response;
	cout << "Please enter the desired dimension." << endl;
	cin >> Response;
	if (Response <= 0) 
	{ 
		throw (Response); // caught in main() 
	}    
	return Response;
}

}

int getUserInput( )  //This function can throw any kind of exception!
{
	int Response;
	cout << "Please enter the desired dimension."<< endl;
	cin >> Response;
	if (Response <= 0) {  throw (Response); }    // caught in main() 
      return Response;
}
