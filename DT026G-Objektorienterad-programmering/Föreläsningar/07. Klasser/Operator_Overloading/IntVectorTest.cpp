#include "IntVector.h"

int main()
{
	Vec a(15);  //Default Ctor is called
	Vec b;		//Default Ctor is called
	Vec c;		//Default Ctor is called
	//Vec d=2;  //inte bra! ,vi gör en explicit Ctor 

	Vec d(2); //Default Ctor is called
	  

	a.get(8) = 27;    //8:e pos. sätts till 27  , int& Vec::get(int index) används
	c.get(8) = 10;   //8:e pos. sätts till 10   , int& Vec::get(int index)  används

	b = a + c;

	cout << endl;

	cout << "a = " << a << endl << "b = " << b
		<< endl << "c = " << c << endl;
	cout << endl;


	cin.get();

	a = b = c;
	cout << "a = " << a << endl << "b = " << b
		<< endl << "c = " << c << endl;
	cout << endl;

	cin.get();

	a = (a + (b = a));
	cout << "a = " << a << endl << "b = " << b
		<< endl << "c = " << c << endl;

	cin.get();

	a = 1 + b + a + 2;
	cout << "a = " << a << endl << "b = " << b
		<< endl << "c = " << c << endl;


	try {
		cout << a.get(11) << endl;
	}

	catch (OutOfRange &Range)
	{
		Range.report();
	}


	for (int i = -1; i <= 6; i++) {
		try {
			cout << "a[" << i << "]=" << a.get(i) << endl;
		}
		catch (OutOfRange &Range) {
			Range.report();
		}
	}

	//cout<<"printing c: ";
	//print(cout,c);

	cin.get();

	//Testing operator >>
	//cin>>c;
	//cout<<c;

	//Testing ++a (prefix) and a++ (postfix)


	cout << "++a" << endl;
	++a;
	cout << a << endl;

	cout << "a++" << endl;
	a++;
	cout << a << endl;

	//Testing &=(int) //expand a  with 10.
	a &= 10;

	b &= c;    //Concatenation of two  Vec , b och c

	cout << b << endl;

	//Testing !=

	if (a != b)
		cout << "The two Vectors are not equal!" << endl;
	else
		cout << "The two Vectors are equal!" << endl;

	return 0;
}
