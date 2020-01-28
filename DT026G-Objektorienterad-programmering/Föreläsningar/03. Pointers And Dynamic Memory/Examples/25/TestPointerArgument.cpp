#include <iostream>
using namespace std;

// Swap two variables using pass-by-value
void swap1(int n1, int n2)
{
  int temp = n1;
  n1 = n2;
  n2 = temp;
}

// Swap two variables using pass-by-reference
void swap2(int &n1, int &n2)
{
  int temp = n1;
  n1 = n2;
  n2 = temp;
}

// Swap two variables using pass-by-pointers
void swap3(int *pValue1, int *pValue2)
{
  int temp = *pValue1;
  *pValue1 = *pValue2;
  *pValue2 = temp;
}

int main()
{
  // Declare and initialize variables
  int num1 = 1;
  int num2 = 2;

  cout << "Before invoking the swap function, num1 is "
    << num1 << " and num2 is " << num2 << endl;

  // Invoke the swap function to attempt to swap two variables
  swap1(num1, num2);

  cout << "After invoking the swap function, num1 is " << num1 <<
    " and num2 is " << num2 << endl;

  cout << "Before invoking the swap function, num1 is "
    << num1 << " and num2 is " << num2 << endl;

  // Invoke the swap function to attempt to swap two variables
  swap2(num1, num2);

  cout << "After invoking the swap function, num1 is " << num1 <<
    " and num2 is " << num2 << endl;

  cout << "Before invoking the swap function, num1 is "
    << num1 << " and num2 is " << num2 << endl;

  // Invoke the swap function to attempt to swap two variables
  swap3(&num1, &num2);

  cout << "After invoking the swap function, num1 is " << num1 <<
    " and num2 is " << num2 << endl;

  return 0;
}
