#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double x = 800000.0 / 81.0;
	cout << setprecision(2) << x;
	//cout << fixed << setprecision(2) << x;
	return 0;
}
