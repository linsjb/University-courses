//-----------------------------------------------------------
//  Purpose:    Implementation of Stack class.
//-----------------------------------------------------------
#include "Stack.h"

//-----------------------------------------------------------
// Constructor function.
//-----------------------------------------------------------
template < typename T > Stack < T >::Stack()
{
   Head = NULL;
   Length = 0;
}

//----------------------------------------------
// Constructor function.
//----------------------------------------------
template < typename T > Stack < T >::Stack(const Stack & stack)
{
   // Create first node
   SNode < T > *copy = new SNode < T >;
   Head = copy;

   // Walk list to copy nodes
   SNode < T > *ptr = stack.Head;
   while (ptr != NULL)
   {
      copy->Next = new SNode < T >;
      copy = copy->Next;
      copy->Number = ptr->Number;
      copy->Next = NULL;
      ptr = ptr->Next;
   }

   // Tidy first node
   copy = Head;
   Head = copy->Next;
   delete copy;
}

//-----------------------------------------------------------
// Destructor function.
//-----------------------------------------------------------
template < typename T > Stack < T >::~Stack()
{
   // Walk stack deleting data
   while (Head != NULL)
   {
      SNode < T > *Temp = Head;
      Head = Head->Next;
      delete Temp;
   }

   // Reset head
   Head = NULL;
   Length = 0;
}

//-----------------------------------------------------------
// Check to see if stack is full.
//-----------------------------------------------------------
template < typename T > bool Stack < T >::IsFull()
{
   return (false);
}

//-----------------------------------------------------------
// Check to see if stack is empty.
//-----------------------------------------------------------
template < typename T > bool Stack < T >::IsEmpty()
{
   return (Length == 0);
}

//-----------------------------------------------------------
// Push data into the stack.
//-----------------------------------------------------------
template < typename T > void Stack < T >::Push(T Number)
{
   // Check for full stack
   if (IsFull())
      return;

   // Allocate space for data
   SNode < T > *Temp = new SNode < T >;
   if (Temp == NULL)
      return;

   // Insert data at head of list
   Temp->Number = Number;
   Temp->Next = Head;
   Head = Temp;
   Length++;

   // cout << "Push " << Number << endl;
}

//-----------------------------------------------------------
// Pop data from the stack.
//-----------------------------------------------------------
template < typename T > void Stack < T >::Pop(T & Number)
{
   // Check for empty stack
   if (IsEmpty())
      return;

   // Extract information from node
   Number = Head->Number;

   // Pop item from linked list
   SNode < T > *Temp = Head;
   Head = Head->Next;
   delete Temp;
   Length--;

   // cout << "Pop " << Number << endl;
}

//-----------------------------------------------------------
// Return data from top of stack.
//-----------------------------------------------------------
template < typename T > void Stack < T >::Top(T & Number)
{
   // Check for empty stack
   if (IsEmpty())
      return;

   // Return information from node
   Number = Head->Number;

   // cout << "Top " << Number << endl;
}

//-----------------------------------------------------------
// Return the number of elements in stack.
//-----------------------------------------------------------
template < typename T > int Stack < T >::GetLength()
{
   return Length;
}

//-----------------------------------------------------------
// Print all records in the stack.
//-----------------------------------------------------------
template < typename T > void Stack < T >::Print()
{
   // Walk the stack printing data
   cout << "size = " << Length << ", data = ";
   SNode < T > *Temp = Head;
   while (Temp != NULL)
   {
      cout << Temp->Number << " ";
      Temp = Temp->Next;
   }
   cout << endl;
}
