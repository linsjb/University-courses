#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  float floatValue = 19.5;
  int* p = reinterpret_cast<int*>(&floatValue);
  cout << "int value " << *p << " and float value "  
    << floatValue << "\nhave the same binary representation "
    << hex << *p << endl;

  return 0;
}
