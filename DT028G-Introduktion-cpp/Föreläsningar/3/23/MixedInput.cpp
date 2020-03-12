#include <iostream>
#include <string>
using namespace std;


int main()
{
	string firstname;
	string lastname;
	int age;

	cout << "Type your name: ";
	getline(cin, firstname);
	cout << "Type your lucky number: ";
	cin >> age;
	cout << "Type your lastname: ";
	//cin.ignore();
	//cin.get();
	getline(cin, lastname);
	
	cout << firstname << endl;
	cout << lastname << endl;
	cout << age << endl;

	return 0;
}
