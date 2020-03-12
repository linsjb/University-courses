// transp.cpp -- uses structures with functions and vector!

#include <iostream>
#include <vector>
#include <windows.h>


struct travel_time
{
	int hours;
	int mins;

};


std::ostream& operator << (std::ostream &o, const travel_time &t)
{
	o << t.hours << " timmar och " << t.mins << " minuter" << std::endl;
	return o;
}


std::istream& operator >> (std::istream &i, travel_time &t)
{

	i >> t.hours;
	i >> t.mins;
	return i;
}



travel_time sum(const travel_time days[]);
travel_time sum(const std::vector <travel_time> &t1);
void print(const travel_time &t);


int main()
{
	//Nedanstående 2 rader är endast till för att svenska tecken skall visas i DOS.
	UINT oldcodepage = GetConsoleOutputCP();
	SetConsoleOutputCP(28591);

	travel_time days[] = { { 5, 45 },{ 4, 55 } };

	// med vector om 2 element
	std::vector <travel_time> day(2);
	std::cout << "Ange timmar och min. för första dagen:";
	std::cin >> day[0];   //detta anropar den överlagrade operatorn ovan
	std::cout << "Ange timmar och min. för andra dagen:";
	std::cin >> day[1];   //detta anropar den överlagrade operatorn ovan

	std::cout <<"Detta är en ren utskrift: "<< day[0];   //detta anropar den överlagrade operatorn ovan

	//skickar day (std::vector <travel_time> day(2);) till sum
	std::cout << sum(day);


	//vector <travel_time>day;  //days här kan expandera, alltså växa allteftersom man lägger in data
	
	//skickar day (travel_time days[] = { { 5, 45 },{ 4, 55 } };) till sum
	travel_time trip = sum(days);

	std::cout << "Summan för två dagar: ";
	print(trip);
	//cout << trip;

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



travel_time sum(const std::vector <travel_time> &t1)
{
	travel_time total;
	const int Mins_per_hr = 60;

	total.mins = (t1[0].mins + t1[1].mins) % Mins_per_hr;
	total.hours = t1[0].hours + t1[1].hours + (t1[0].mins + t1[1].mins) / Mins_per_hr;

	return total;
}

void print(const travel_time &t)
{
	std::cout << t.hours << " timmar och " << t.mins << " minuter" << std::endl;
}


