#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

struct Entry {
	char name[20];
	char type;
	char string_value[5];
	int  int_value;
};


int main()
{


//string_value is used if type=='s'
//int_value is used if type=='i'

Entry p;

cout << "sizeof(struct p) = " << sizeof(p) << endl;


cout << " Type a string up to 4 characters:";
cin >> p.string_value;

cout << "Type an int: ";
cin >> p.int_value;

cout << "Type either s or i: " << endl;
cin >> p.type;

switch (p.type)
{
	case 's':  cout << p.string_value << endl; break;
	case 'i':  cout << p.int_value << endl;    break;
	default:  cerr << "type corrupted" << endl;
}

return 0;
} //end-main
