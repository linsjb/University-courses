#include <iostream>
using namespace std;

int main()   {
	int x = 5, y = 0, resultat;
	try    {   //try-block start
		if (y == 0)   {
			throw " Divide by Zero ";  
		}
		resultat = x / y;
	}  //try-block end
	catch (char *e)  {  //catch-block start

		cout << e << endl;
	}//catch-block end

	cout << " Bye" << endl;
	return 0;
} //End-main
