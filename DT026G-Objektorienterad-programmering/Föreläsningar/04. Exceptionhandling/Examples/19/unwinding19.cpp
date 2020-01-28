#include <iostream>
#include <string>
using namespace std;

double functionA(int val);
int functionB(int val);
int  main()
{
    try {
           cout<< functionA(0);
    }
    catch (string s) {
       cout<< s <<endl;
    }
   catch(...) {
       cout<< "else thing" <<endl;
    }
return 0;
}
double functionA(int val)
{
   return 2/ functionB(val);
}
int functionB(int val)  throw (string)
{
    if (val ==0)    {
        throw  string(" Divide By Zero ");
    }
    else
         if (val > 100)    {
           throw string(" DivideBySomething ");
    }
	return val;
}
