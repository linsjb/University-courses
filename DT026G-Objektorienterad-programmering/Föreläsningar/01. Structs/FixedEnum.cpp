#include <iostream>
using namespace std;

int main()
{
	//Strongly typed enums, which is new in C++11.
	enum class Nail { RED, GREEN, BLUE };
	enum class Toothbrush { EXCITED, MOODY, BLUE };
	Nail yourNail = Nail::RED;
	Toothbrush myToothbrush = Toothbrush::EXCITED;

	if (Toothbrush::EXCITED == myToothbrush && Nail::RED == yourNail)
		cout << "Yes that's like that." << endl;
	else
		cout << "Noway, they aren't the same." << endl;

	return 0;
}
