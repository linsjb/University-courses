#include <iostream>
#include <cctype>
using namespace std;

int main()
{
	cout << "Enter a hex digit between (A and F): ";
	char hexDigit;
	cin >> hexDigit;

	hexDigit = toupper(hexDigit);

	int value = 10 + hexDigit - 'A';
	cout << "The decimal value for hex digit "
			<< hexDigit << " is " << value << endl;


	return 0;
}
