
/*
 Stacks are ADT's that has a LIFO characteristic.
 The Stack ADT usually has the following operations: 
•create - Makes a new empty stack. 
•destroy - Deletes all data on the stack. 
•push - Stores data on top of all other data in stack. 
•pop - Retrieves the data item on top of the stack. 
•top - Retrieves the data on top, but does not remove it. 
(Same as pop/push) 
•full - Checks if stack has room for more data. 
•empty - Checks if stack has any data available. 
*/
//-----------------------------------------------------------
// Main program.
//-----------------------------------------------------------

#include "Stack.h"

int main()
{
   Stack s;
   s.Push(3);
   s.Push(1);
   s.Push(4);
   s.Print();
   s.Push(1);
   s.Push(5);
   s.Push(9);
   s.Print();

   int num;
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

