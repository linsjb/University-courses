#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

struct Entry {
	char name[20];
	char type;
	union {
		char string_value[5];
		int  int_value;
	} u;

};

int main()
{


	//string_value is used if type=='s'
	//int_value is used if type=='i'

	Entry p;

	cout << " Type a string up to 4 characters:";
	cin >> p.u.string_value;

	cout << "Type an int: ";
	cin >> p.u.int_value;

	cout << "Type either s or i: " << endl;
	cin >> p.type;

	switch (p.type)
	{
	case 's':  cout << p.u.string_value << endl; break;
	case 'i':  cout << p.u.int_value << endl;    break;
	default:  cerr << "type corrupted" << endl;
	}

	return 0;
} //end-main
