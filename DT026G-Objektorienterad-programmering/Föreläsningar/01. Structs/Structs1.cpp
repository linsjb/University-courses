#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;

struct date {
	int day = {};
	int month = int(); //default initialization
	int year = {};
	//date() = default; //C++11
};

struct myCat {
	char firstName[20]={ "John" };
	string lastName=string("Bear");
	double hight = { 23.5 };
	date birthDate = {};      //struct in a struct
	//myCat() = default;

};


int main()
{
	date bron = {};
	//date death = { 01, 02, 2002 };
	date death = {};
	//myCat bear = {"John","Bear",23.5, {12,12,1900} };
	myCat bear;


	//myCat bear = {"John","Bear",23.5,{ 12, 12, 1900 }};

	cout << bear.firstName << " " << bear.lastName << " "
		<< bear.hight << endl;
	cout << "Year " << bear.birthDate.year << endl;
	cout << "Death " << death.year << endl;
	cout << "Type hight : ";
		cin >> bear.hight;

	cout << "Type dd mm yyyy : ";
		cin >> bear.birthDate.day >> bear.birthDate.month
		>> bear.birthDate.year;

	cout << "Type firstname : ";
		cin.getline(bear.firstName, 20).get();

	cout << "Type lastname : ";
		getline(cin, bear.lastName).get();
	return 0;
}
