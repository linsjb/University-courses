#include <iostream>
using namespace std;

int main()
{
	enum class Day { MONDAY = 1, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY } day;
	//or you can exactly define the type:
	//enum class Day: char { MONDAY = 1, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY } day;

	cout << "Enter a day (1 for Monday, 2 for Tuesday, etc): ";
	int dayNumber;
	cin >> dayNumber;

	switch (dayNumber) {
	case static_cast<int>(Day::MONDAY) :
		cout << "Play soccer" << endl;
		break;
	case static_cast<int>(Day::TUESDAY) :
		cout << "Piano lesson" << endl;
		break;
	case static_cast<int>(Day::WEDNESDAY) :
		cout << "Math team" << endl;
		break;
	default:
		cout << "Go home" << endl;
	}


	return 0;
}
