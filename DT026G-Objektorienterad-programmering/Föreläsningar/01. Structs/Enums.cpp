// enums.cpp

//Lite komplex!!

#include <iostream>

struct Sales {

	enum WeekDay { Mon, Tues, Wed, Thu, Fri };

	int  sold[5];

};



int main()

{

	Sales ThisWeek = { 23, 43, 12, 34, 32 };


	//Observera hur jag kommer �t WeekDay elementen!!
	//(Sales::Mon �r ju 0,n�sta �r 1 osv.)
	//Kan jag komma �t dessa p� ett annat s�tt?

	for (int day = Sales::Mon; day <= Sales::Fri; ++day)

		std::cout << ThisWeek.sold[day] << std::endl;
	return 0;
}
