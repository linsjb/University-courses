// assert_test.cpp --Tests assert-macro

#include <iostream>
#include <cassert>
using namespace std;


void rangeValidation(int range);



int main()
{

	rangeValidation(11);
	cout << "This line never gets excuted!";

	return 0;
}

void rangeValidation(int range)
{
	// if true, nothing happens, otherwise a message is written out and exits with exit(0);
	assert(range >= 0 && range < 10);
}
