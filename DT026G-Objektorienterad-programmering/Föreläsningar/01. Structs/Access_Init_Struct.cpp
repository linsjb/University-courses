#include <iostream>
#include <windows.h>


struct Date {
	int day;
	int month;
	int year;
};

struct MyCat {
	char firstName[20];
	char lastName[20];
	double length;
	Date birthDate;      //struct in a struct
};

int main()
{
	//Nedanst�ende rad �r till f�r att svenska tecken skall visas i DOS. 
	SetConsoleOutputCP(28591);

	Date tillkomst;
	Date bortGang = { 01, 02, 2002 };
	MyCat bjorn = { "Bj�rne","Bj�rn",23.5,{ 12, 12, 1900 } };

	std::cout << bjorn.firstName << " " << bjorn.lastName << " "
		<< bjorn.length << std::endl;

	std::cout << "�rtal " << bjorn.birthDate.year << std::endl;
	std::cout << "D�ds�r " << bortGang.year << std::endl;
	std::cout << "Ange F�rnamn: ";
	std::cin.getline(bjorn.firstName, 20, '\n');

	std::cout << "Ange Efternamn: ";
	std::cin.getline(bjorn.lastName, 20, '\n');

	std::cout << "Ange l�ngd: ";
	std::cin >> bjorn.length;
	std::cin.ignore();
	std::cout << "Ange dd mm yyyy==>";
	std::cin >> bjorn.birthDate.day;

	return 0;
}
