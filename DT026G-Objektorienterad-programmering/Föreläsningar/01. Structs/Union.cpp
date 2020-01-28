#include <iostream>
#include <iomanip>      // std::setprecision

using std::cout;
using std::endl;

union MyLittleUnion
{
	char    aChar;
	int     anInt;
	double  aDouble;
};


int  main()
{
	MyLittleUnion aUnionObjekt;

	cout << "sizeof(aUnionObjekt) = "
		<< sizeof(aUnionObjekt) << endl;

	aUnionObjekt.aChar = 'U';

	aUnionObjekt.anInt = 32;

	aUnionObjekt.aDouble = 3234.1467899;

	cout << aUnionObjekt.aChar << endl
		<< aUnionObjekt.anInt << endl
		<< std::setprecision(12)<< aUnionObjekt.aDouble << endl;
	return 0;
}
