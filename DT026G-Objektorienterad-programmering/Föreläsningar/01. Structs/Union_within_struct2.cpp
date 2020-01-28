#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

typedef union {
	char string_value[5];
	int  int_value;
} U;

typedef struct {
	char name[20];
	char type;
	U u;
} Entry;

int main()
{


	//string_value is used if type=='s'
	//int_value is used if type=='i'

	Entry p;

	cout << "Type either s or i: " << endl;
	cin >> p.type;

	switch (p.type)
	{
	case 's':
			cout << " Type a string up to 4 characters:";
			cin >> p.u.string_value;
			cout << p.u.string_value << endl;
			break;

	case 'i':
			cout << "Type an int: ";
			cin >> p.u.int_value;
			cout << p.u.int_value << endl;
			break;

	default:  cerr << "type corrupted" << endl;
	}

	return 0;
} //end-main
