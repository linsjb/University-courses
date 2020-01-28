#include <iostream>
#include <string>
using namespace std;

struct DivideBySomething{ };
struct DivideByZero{ };
double functionA(int val);
int functionB(int val);
int  main()
{
	try {
		cout << functionA(101);
	}
	catch (DivideByZero) {
		cout << "DivideByZero" << endl;
	}
	return 0;
}
double functionA(int val)
{
	return 2 / functionB(val);
}
int functionB(int val)
{
	if (val == 0)    {
		throw DivideByZero();
	}
	else
	if (val > 100)    {
		throw DivideBySomething();
	}
	return val;
}
