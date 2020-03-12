#include <iostream>
#include <string>
using namespace std;
int main()   {
    int x = 5, y = 0, resultat;
    try    {   //try-block start
	   if (y == 0)   {
           throw string("Divide by Zero ");
        }
        resultat = x/y;
    }  //try-block end
catch (string e)  {  //catch-block start
	cout << e << endl;
    }//catch-block end
cout << "Bye" << endl;  
return 0;
} //End-main
