//-----------------------------------------------------------
//  Purpose:    Header file for the Stack class.
//-----------------------------------------------------------

#include <cmath>
#include <iostream>
using namespace std;

//-----------------------------------------------------------
// Stack data node definition
//-----------------------------------------------------------
template < typename T > class SNode
{
  public:
	T Number;
	SNode *Next;
};

//-----------------------------------------------------------
// Define the Stack class interface 
//-----------------------------------------------------------
template < typename T > class Stack
{
 public:
   // Constructors
   Stack();
   Stack(const Stack & stack);
   ~Stack();

   // Methods
   bool IsFull();
   bool IsEmpty();
   void Push(T Number);
   void Pop(T & Number);
   void Top(T & Number);
   int GetLength();
   void Print();

 private:
   SNode < T > *Head;
   int Length;
};
