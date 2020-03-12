// transp.cpp -- uses structures with functions!
#include <iostream>
#include <windows.h>

using namespace std;

struct travel_time
{
	int hours;
	int mins;
};



travel_time sum(const travel_time days[]);
void print(const travel_time &t);

int main()
{
	//Nedanst�ende rad �r endast till f�r att svenska tecken skall visas i DOS.
	SetConsoleOutputCP(28591);

	//travel_time days[] = { 5, 45,4,55};

	travel_time days[] = { { 5, 45 },{ 4, 55 } };

	travel_time trip = sum(days);

	std::cout << "Summan f�r tv� dagar: ";
	print(trip);

	return 0;
}

travel_time sum(const travel_time t1[])
{
	travel_time total;
	const int Mins_per_hr = 60;

	total.mins = (t1[0].mins + t1[1].mins) % Mins_per_hr;
	total.hours = t1[0].hours + t1[1].hours + (t1[0].mins + t1[1].mins) / Mins_per_hr;

	return total;
}

void print(const travel_time &t)
{
	std::cout << t.hours << " timmar och "
		<< t.mins << " minuter" << std::endl;
}
