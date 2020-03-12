#include <iostream>
#include <string>

using namespace std;
void functionA()
{
	//....do something
	throw range_error(string("some info"));
}

int  main()
{
	try {
		functionA();
	}
	catch (range_error   & r) {
		cout << r.what() << endl;
	}
	return 0;
}
