#include <iostream>
#include <string>
using namespace std;
struct DivideByZero  {
//public:
    DivideByZero(int n, int d) : num(n), denom(d), message("Divide by zero") { }
    //~DivideByZero() { }
    int getNumerator()
    {
      return num;
    }

    int getDenominator()
    {
      return denom;
    }

    string getMessage()
    {
      return message;
    }

private:
    int num, denom;   string message;
};

int main()
{
    int x = 5, y = 0, resultat;

    try
    {
      if (y == 0)
      {
          throw DivideByZero(x, y);
      }
      resultat = x/y;
    }
    
    catch (DivideByZero e)
    {
        cout << e.getMessage() << endl;
        cout << "Numerator: " << e.getNumerator() << endl;
        cout << "Denominator: " << e.getDenominator() << endl;
    }
return 0;
}
