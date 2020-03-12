#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;


class date {
public:
	int day;
	int month;
	int year;
	date(int d = 0, int m = 0, int y = 0) :day(d), month(m), year(y) {};
};

class myCat {
public:
	char firstName[20];
	string lastName;
	double hight;
	date birthDate;
	myCat(char first[20], string last, double h, date birth);
};

myCat::myCat(char first[20], string last, double h, date birth)
{
	strcpy_s(firstName, first);
	lastName = last;
	hight = h;
	birthDate = birth;

}

int main()
{

	date bron;
	date death = { 01, 02, 2002 };

	myCat bear = { "John","Bear",23.5,{ 12,12,1900 } };

	cout << "bear.firstName: " << bear.firstName << endl
		<< "bear.lastName: " << bear.lastName << endl
		<< "bear.hight: " << bear.hight << endl;

	cout << "Birth Year " << bear.birthDate.year << endl;
	cout << "Death Year " << death.year << endl;


	return 0;
}
