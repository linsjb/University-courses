#include <iostream>
using namespace std;
int main()   {
	int x = 5, y = 0, resultat;
	int exceptionCode = 25;
	try    {   //try-block start
		if (y == 0)   {
			throw exceptionCode;
		}
		resultat = x / y;
		cout << "Resultat: " << resultat << endl;
	}  //try-block end
	catch (int exceptionCode)  {  //catch-block start

		if (exceptionCode == 25)   {
			cout << "Divide by zero"
				<< endl;
		}
		else   {
			cout << "Exception of unknown type "
				<< endl;
		}

	}//catch-block end

	cout << " Bye" << endl;  //When an exception is thrown, the execution continues from here!!
	return 0;
} //End-main
