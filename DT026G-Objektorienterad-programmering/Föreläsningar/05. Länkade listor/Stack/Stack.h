//-----------------------------------------------------------
//  Purpose:    Header file for the Stack class.
//-----------------------------------------------------------

#include <cmath>
#include <iostream>
using namespace std;

//-----------------------------------------------------------
// Stack data node definition
//-----------------------------------------------------------
class SNode
{
  public:
   int Number;
   SNode *Next;
};

//-----------------------------------------------------------
// Define the Stack class interface 
//-----------------------------------------------------------
class Stack
{
 public:
   // Constructors
   Stack();
   Stack(const Stack & stack);
   ~Stack();

   // Methods
   bool IsFull();
   bool IsEmpty();
   void Push(int Number);
   void Pop(int &Number);
   void Top(int &Number);
   int GetLength();
   void Print();

 private:
   SNode *Head;
   int Length;
};
