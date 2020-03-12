//-----------------------------------------------------------
//  Purpose:    Implementation of Stack class.
//-----------------------------------------------------------
#include "Stack.h"

//-----------------------------------------------------------
// Constructor function.
//-----------------------------------------------------------
Stack::Stack()
{
   Head = NULL;
   Length = 0;
}

//----------------------------------------------
// Constructor function.
//----------------------------------------------
Stack::Stack(const Stack & stack)
{
   // Create first node
   SNode *copy = new SNode();
   Head = copy;

   // Walk list to copy nodes
   SNode *ptr = stack.Head;
   while (ptr != NULL)
   {
      copy->Next = new SNode();
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
Stack::~Stack()
{
   // Walk stack deleting data
   while (Head != NULL)
   {
      SNode *Temp = Head;
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
bool Stack::IsFull()
{
   return (false);
}

//-----------------------------------------------------------
// Check to see if stack is empty.
//-----------------------------------------------------------
bool Stack::IsEmpty()
{
   return (Length == 0);
}

//-----------------------------------------------------------
// Push data into the stack.
//-----------------------------------------------------------
void Stack::Push(int Number)
{
   // Check for full stack
   if (IsFull())
      return;

   // Allocate space for data
   SNode *Temp = new SNode;
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
void Stack::Pop(int &Number)
{
   // Check for empty stack
   if (IsEmpty())
      return;

   // Extract information from node
   Number = Head->Number;

   // Pop item from linked list
   SNode *Temp = Head;
   Head = Head->Next;
   delete Temp;
   Length--;

   // cout << "Pop " << Number << endl;
}

//-----------------------------------------------------------
// Return data from top of stack.
//-----------------------------------------------------------
void Stack::Top(int &Number)
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
int Stack::GetLength()
{
   return Length;
}

//-----------------------------------------------------------
// Print all records in the stack.
//-----------------------------------------------------------
void Stack::Print()
{
   // Walk the stack printing data
   cout << "size = " << Length << ", data = ";
   SNode *Temp = Head;
   while (Temp != NULL)
   {
      cout << Temp->Number << " ";
      Temp = Temp->Next;
   }
   cout << endl;
}

#ifdef STACK_MAIN
//-----------------------------------------------------------
// Main program.
//-----------------------------------------------------------
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
}
#endif
