/*

*/
//-----------------------------------------------------------
// Main program.
//-----------------------------------------------------------

#include "Stack.h"
int main()
{
   Stack < string > s;
   s.Push("3");
   s.Push("1");
   s.Push("4");
   s.Print();
   s.Push("1");
   s.Push("5");
   s.Push("9");
   s.Print();

   string num;
   s.Pop(num);
   s.Pop(num);
   s.Print();
   s.Pop(num);
   s.Pop(num);
   s.Print();
   s.Pop(num);
   s.Pop(num);
   s.Print();
   return 0;
}